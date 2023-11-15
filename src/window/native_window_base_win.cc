#include "native_window_base_win.h"
#include <cassert>

namespace xui
{

Tls NativeWindowBase::tls_;
HFONT NativeWindowBase::font_;

NativeWindowBase::NativeWindowBase() : hwnd_(nullptr), original_proc_(::DefWindowProc)
{
#ifdef _DEBUG
    thread_id_ = 0;
#endif
}

NativeWindowBase::~NativeWindowBase()
{
    assert(hwnd_ == nullptr);
}

bool NativeWindowBase::Create(HWND hParent,
                              const Rect &rect,
                              DWORD style,
                              DWORD exStyle,
                              LPCTSTR className,
                              LPCTSTR windowName,
                              HMENU menu,
                              HINSTANCE instance)
{
    assert(hwnd_ == nullptr);
#ifdef _DEBUG
    thread_id_ = ::GetCurrentThreadId();
#endif

    WNDCLASSEX wcex = {sizeof(WNDCLASSEX)};
    bool stdControl = !!GetClassInfoEx(nullptr, className, &wcex);
    if (!stdControl)
    {
        ZeroMemory(&wcex, sizeof(WNDCLASSEX));
        wcex.cbSize = sizeof(WNDCLASSEX);
        wcex.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
        wcex.lpfnWndProc = StartWndProc;
        wcex.hInstance = instance;
        wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszClassName = className;

        ATOM atom = RegisterClassEx(&wcex);
        if (atom == 0)
        {
            return false;
        }

        tls_.Set((void *)this);
    }

    HWND hWnd = ::CreateWindowEx(exStyle, className, windowName, style, rect.l, rect.t, rect.W(), rect.H(), hParent,
                                 menu, instance, nullptr);
    if (hWnd == nullptr)
    {
        DWORD dw = ::GetLastError();
        return false;
    }

    if (stdControl)
    {
        Attach(hWnd);
    }

    if (font_ == nullptr)
    {
        NONCLIENTMETRICS m_tagNONCLIENTMETRICSW = {sizeof(m_tagNONCLIENTMETRICSW)};
        SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(NONCLIENTMETRICS), &m_tagNONCLIENTMETRICSW, 0);

        font_ = CreateFontIndirect(&m_tagNONCLIENTMETRICSW.lfMessageFont);
    }
    ::SendMessage(hwnd_, WM_SETFONT, (WPARAM)font_, MAKELPARAM(FALSE, 0));

    return true;
}

bool NativeWindowBase::Destroy()
{
    assert(hwnd_ != nullptr);
    return !!::DestroyWindow(hwnd_);
}

NativeWindowBase::operator HWND() const
{
    return hwnd_;
}

bool NativeWindowBase::Attach(HWND hWnd)
{
    assert(hwnd_ == nullptr);
    hwnd_ = hWnd;

    tls_.Set(this);
    original_proc_ = (WNDPROC)::SetWindowLongPtr(hwnd_, GWLP_WNDPROC, (LONG_PTR)StartWndProc);

    // Force the StartWndProc to be called:
    ::SendMessage(hwnd_, WM_NULL, 0, 0);

    return true;
}

HWND NativeWindowBase::Detach()
{
    assert(hwnd_ != nullptr);
    HWND hWnd = hwnd_;
    ::SetWindowLongPtr(hwnd_, GWLP_WNDPROC, (LONG_PTR)original_proc_);
    hwnd_ = nullptr;
    return hWnd;
}

void NativeWindowBase::RegisterMessaheHandler(UINT uMsg, MsgHandler handler)
{
#ifdef _DEBUG
    assert(thread_id_ == 0 || thread_id_ == ::GetCurrentThreadId());
#endif
    msg_handlers_.emplace(uMsg, handler);
}

LRESULT NativeWindowBase::ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    LRESULT lResult = 0;
    for (auto it = msg_handlers_.lower_bound(uMsg), end = msg_handlers_.upper_bound(uMsg); it != end; ++it)
    {
        lResult = it->second(uMsg, wParam, lParam, bHandled);
        if (bHandled)
        {
            return lResult;
        }
    }
    bHandled = false;
    return lResult;
}

LRESULT CALLBACK NativeWindowBase::StartWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    NativeWindowBase *pThis = (NativeWindowBase *)tls_.Get();

    pThis->thunk_.SetObject(pThis);
    pThis->thunk_.SetRealProc(&NativeWindowBase::StaticWndProc);
    pThis->hwnd_ = hwnd;
    WNDPROC pWndProc = pThis->thunk_.GetThunkProc();

    ::SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)pWndProc);

    return pWndProc(hwnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK NativeWindowBase::StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    bool bHandled = true;
    NativeWindowBase *pThis = (NativeWindowBase *)hWnd;
    LRESULT lResult = pThis->ProcessMessage(uMsg, wParam, lParam, bHandled);

    if (!bHandled)
    {
        lResult = pThis->original_proc_(pThis->hwnd_, uMsg, wParam, lParam);
    }

    if (uMsg == WM_NCDESTROY)
    {
        pThis->hwnd_ = nullptr;
    }

    return lResult;
}

} // namespace xui
