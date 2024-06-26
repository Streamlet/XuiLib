#include "native_window_win.h"
#include "../utility/graph_util_win.h"
#include <winuser.h>

#define REGISTER_MSG_HANDLER(msg, handler)                                                                             \
    RegisterMessageHandler(msg, std::bind(&NativeWindow::handler, this, std::placeholders::_1, std::placeholders::_2,  \
                                          std::placeholders::_3, std::placeholders::_4))

namespace xui
{

NativeWindow::NativeWindow(RootWindow *window) : window_(window), gdi_renderer_(std::make_unique<GdiRenderer>())
{
    REGISTER_MSG_HANDLER(WM_CREATE, OnCreate);
    REGISTER_MSG_HANDLER(WM_CLOSE, OnClose);
    REGISTER_MSG_HANDLER(WM_DESTROY, OnDestroy);
    REGISTER_MSG_HANDLER(WM_SIZE, OnSize);
    REGISTER_MSG_HANDLER(WM_NCPAINT, OnNcPaint);
    REGISTER_MSG_HANDLER(WM_ERASEBKGND, OnEraseBkgnd);
    REGISTER_MSG_HANDLER(WM_PAINT, OnPaint);
    REGISTER_MSG_HANDLER(WM_SYSKEYDOWN, OnSysKeyDown);
    REGISTER_MSG_HANDLER(WM_SYSKEYUP, OnSysKeyUp);
    REGISTER_MSG_HANDLER(WM_KEYDOWN, OnKeyDown);
    REGISTER_MSG_HANDLER(WM_KEYUP, OnKeyUp);
    REGISTER_MSG_HANDLER(WM_CHAR, OnChar);
    REGISTER_MSG_HANDLER(WM_UNICHAR, OnUniChar);
    REGISTER_MSG_HANDLER(WM_LBUTTONDOWN, OnLButtonDown);
    REGISTER_MSG_HANDLER(WM_LBUTTONUP, OnLButtonUp);
    REGISTER_MSG_HANDLER(WM_LBUTTONDBLCLK, OnLButtonDblClk);
    REGISTER_MSG_HANDLER(WM_RBUTTONDOWN, OnRButtonDown);
    REGISTER_MSG_HANDLER(WM_RBUTTONUP, OnRButtonUp);
    REGISTER_MSG_HANDLER(WM_RBUTTONDBLCLK, OnRButtonDblClk);
    REGISTER_MSG_HANDLER(WM_MBUTTONDOWN, OnMButtonDown);
    REGISTER_MSG_HANDLER(WM_MBUTTONUP, OnMButtonUp);
    REGISTER_MSG_HANDLER(WM_MBUTTONDBLCLK, OnMButtonDblClk);
    REGISTER_MSG_HANDLER(WM_XBUTTONDOWN, OnXButtonDown);
    REGISTER_MSG_HANDLER(WM_XBUTTONUP, OnXButtonUp);
    REGISTER_MSG_HANDLER(WM_XBUTTONDBLCLK, OnXButtonDblClk);
    REGISTER_MSG_HANDLER(WM_MOUSEWHEEL, OnMouseWheel);
    REGISTER_MSG_HANDLER(WM_MOUSEHWHEEL, OnMouseHWheel);
    REGISTER_MSG_HANDLER(WM_SETFOCUS, OnSetFocus);
    REGISTER_MSG_HANDLER(WM_KILLFOCUS, OnKillFocus);
}

NativeWindow::~NativeWindow()
{
}

LRESULT NativeWindow::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    window_->ProcessMessage(XUI_WM_CREATE, nullptr, bHandled);
    Redraw();
    return 0;
}

LRESULT NativeWindow::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    window_->ProcessMessage(XUI_WM_DESTROY, nullptr, bHandled);
    return 0;
}

LRESULT NativeWindow::OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    return TRUE;
}

LRESULT NativeWindow::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    PAINTSTRUCT ps = {0};
    ::BeginPaint(hwnd_, &ps);
    RenderWindow(window_, ps.hdc,
                 Rect(Point(ps.rcPaint.left, ps.rcPaint.top),
                      Size(ps.rcPaint.right - ps.rcPaint.left, ps.rcPaint.bottom - ps.rcPaint.top)));
    ::EndPaint(hwnd_, &ps);
    return 0;
}

void NativeWindow::Redraw()
{
    if ((GetWindowLong(hwnd_, GWL_EXSTYLE) & WS_EX_LAYERED) != 0)
    {
        RECT rcWindow = {};
        ::GetWindowRect(hwnd_, &rcWindow);

        POINT ptClient = {0, 0};
        ::ClientToScreen(hwnd_, &ptClient);

        ptClient.x -= rcWindow.left;
        ptClient.y -= rcWindow.top;
        ::OffsetRect(&rcWindow, rcWindow.left, rcWindow.top);
        SIZE szWindow = {rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top};

        RECT rcClient = {};
        ::GetClientRect(hwnd_, &rcClient);
        ::OffsetRect(&rcClient, ptClient.x, ptClient.y);
        SIZE szClient = {rcClient.right - rcClient.left, rcClient.bottom - rcClient.top};
        LONG lBorderWidth = ptClient.x;
        LONG lCaptionHeight = ptClient.y - ptClient.x;

        HDC hDC = GetDC(hwnd_);
        HDC hTargetDC = CreateCompatibleDC(hDC);

        HBITMAP hBitmap = graph_util::CreateBitmap(szWindow.cx, szWindow.cy, nullptr);
        ::SelectObject(hTargetDC, hBitmap);

        RenderWindow(window_, hTargetDC, Rect(rcClient.left, rcClient.top, rcClient.right, rcClient.bottom));

        BLENDFUNCTION bf = {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};
        POINT pt = POINT{0, 0};
        HDC hScreenDC = GetDC(NULL);
        ::UpdateLayeredWindow(hwnd_, hScreenDC, &pt, &szWindow, hTargetDC, &pt, 0, &bf, ULW_ALPHA);
        ::ReleaseDC(nullptr, hScreenDC);
        ::DeleteObject(hBitmap);
        ::DeleteDC(hTargetDC);
        ::ReleaseDC(hwnd_, hTargetDC);
    }
    else
    {
        InvalidateRect(hwnd_, nullptr, true);
    }
}

void NativeWindow::RenderWindow(Window *window, HDC hDC, Rect rect)
{
    HDC hTargetDC = hDC;
    HBITMAP hBitmap = nullptr;
    HRGN hRgn = nullptr;
    Point offset(0, 0);
    if (window->alpha_ != 255)
    {
        hTargetDC = ::CreateCompatibleDC(hDC);
        hBitmap = graph_util::CreateBitmap(rect.W(), rect.H(), nullptr);
        ::SelectObject(hTargetDC, hBitmap);
    }
    else
    {
        offset = rect.TL();
        HRGN hNewRgn = ::CreateRectRgn(rect.l, rect.t, rect.r, rect.b);
        hRgn = ::CreateRectRgn(0, 0, 1, 1);
        ::GetClipRgn(hTargetDC, hRgn);
        ::SelectClipRgn(hTargetDC, hNewRgn);
        ::SetViewportOrgEx(hTargetDC, rect.l, rect.t, nullptr);
    }

    
    bool bHandled = true;
    gdi_renderer_->AttachDC(hTargetDC);
    window->ProcessMessage(XUI_WM_PAINT, (Renderer *)gdi_renderer_.get(), bHandled);
    gdi_renderer_->DetachDC();
    for (const auto &child : window->children_)
    {
        Rect rc(Point(offset.x + child->rect_.l, offset.y + child->rect_.t), child->rect_.Size());
        RenderWindow(child, hTargetDC, rc);
    }

    if (hTargetDC == hDC)
    {
        ::SetViewportOrgEx(hTargetDC, 0, 0, nullptr);
        ::SelectClipRgn(hTargetDC, hRgn);
    }
    else
    {
        BLENDFUNCTION bf = {AC_SRC_OVER, 0, window->alpha_, AC_SRC_ALPHA};
        ::AlphaBlend(hDC, rect.l, rect.t, rect.W(), rect.H(), hTargetDC, 0, 0, rect.W(), rect.H(), bf);
        ::DeleteObject(hBitmap);
        ::DeleteDC(hTargetDC);
    }
}

LRESULT NativeWindow::OnSysKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnSysKeyUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnKeyUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnUniChar(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnLButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnLButtonDblClk(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnRButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnRButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnRButtonDblClk(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnMButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnMButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnMButtonDblClk(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnXButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnXButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnXButtonDblClk(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnMouseWheel(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnMouseHWheel(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

} // namespace xui
