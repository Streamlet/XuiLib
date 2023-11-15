#include "native_window_win.h"

namespace xui
{

NativeWindow::NativeWindow(Window *window) : window_(window)
{
    using namespace std::placeholders;
    RegisterMessaheHandler(WM_CREATE, std::bind(&NativeWindow::OnCreate, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_CLOSE, std::bind(&NativeWindow::OnClose, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_DESTROY, std::bind(&NativeWindow::OnDestroy, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_SIZE, std::bind(&NativeWindow::OnSize, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_ERASEBKGND, std::bind(&NativeWindow::OnEraseBkgnd, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_PAINT, std::bind(&NativeWindow::OnPaint, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_SYSKEYDOWN, std::bind(&NativeWindow::OnSysKeyDown, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_SYSKEYUP, std::bind(&NativeWindow::OnSysKeyUp, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_KEYDOWN, std::bind(&NativeWindow::OnKeyDown, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_KEYUP, std::bind(&NativeWindow::OnKeyUp, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_CHAR, std::bind(&NativeWindow::OnChar, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_UNICHAR, std::bind(&NativeWindow::OnUniChar, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_LBUTTONDOWN, std::bind(&NativeWindow::OnLButtonDown, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_LBUTTONUP, std::bind(&NativeWindow::OnLButtonUp, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_LBUTTONDBLCLK, std::bind(&NativeWindow::OnLButtonDblClk, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_RBUTTONDOWN, std::bind(&NativeWindow::OnRButtonDown, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_RBUTTONUP, std::bind(&NativeWindow::OnRButtonUp, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_RBUTTONDBLCLK, std::bind(&NativeWindow::OnRButtonDblClk, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_MBUTTONDOWN, std::bind(&NativeWindow::OnMButtonDown, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_MBUTTONUP, std::bind(&NativeWindow::OnMButtonUp, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_MBUTTONDBLCLK, std::bind(&NativeWindow::OnMButtonDblClk, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_XBUTTONDOWN, std::bind(&NativeWindow::OnXButtonDown, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_XBUTTONUP, std::bind(&NativeWindow::OnXButtonUp, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_XBUTTONDBLCLK, std::bind(&NativeWindow::OnXButtonDblClk, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_MOUSEWHEEL, std::bind(&NativeWindow::OnMouseWheel, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_MOUSEHWHEEL, std::bind(&NativeWindow::OnMouseHWheel, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_SETFOCUS, std::bind(&NativeWindow::OnSetFocus, this, _1, _2, _3, _4));
    RegisterMessaheHandler(WM_KILLFOCUS, std::bind(&NativeWindow::OnKillFocus, this, _1, _2, _3, _4));
}

NativeWindow::~NativeWindow()
{
}

LRESULT NativeWindow::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
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

LRESULT NativeWindow::OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
}

LRESULT NativeWindow::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)
{
    bHandled = false;
    return 0;
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