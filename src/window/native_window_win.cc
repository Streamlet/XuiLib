#include "native_window_win.h"

#define REGISTER_MSG_HANDLER(msg, handler) RegisterMessageHandler(msg, std::bind(&NativeWindow::handler, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4))

namespace xui
{

NativeWindow::NativeWindow(Window *window) : window_(window)
{
    REGISTER_MSG_HANDLER(WM_CREATE, OnCreate);
    REGISTER_MSG_HANDLER(WM_CLOSE, OnClose);
    REGISTER_MSG_HANDLER(WM_DESTROY, OnDestroy);
    REGISTER_MSG_HANDLER(WM_SIZE, OnSize);
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