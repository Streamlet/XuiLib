#include <xui/window/root_window.h>

#include "native_window_win.h"

const TCHAR *ROOT_WINDOW_CLASS_NAME = _T("XUI_ROOT_WINDOW");

namespace xui
{

RootWindow::RootWindow() : native_window_(std::make_unique<NativeWindow>(this))
{
}

RootWindow::~RootWindow()
{
}

bool RootWindow::Create(const RootWindow *owner, const Rect &rect)
{
    rect_ = rect;
    bool result = native_window_->Create(owner == nullptr ? nullptr : (HWND)*owner->native_window_, rect,
                                         WS_OVERLAPPEDWINDOW | WS_VISIBLE, alpha_ == 255 ? 0 : WS_EX_LAYERED,
                                         ROOT_WINDOW_CLASS_NAME, nullptr);
    bool bHandled = true;
    ProcessChildMessage(XUI_WM_CREATE, nullptr, bHandled);
    return result;
}

bool RootWindow::Destroy()
{
    bool result = native_window_->Destroy();
    bool bHandled = true;
    ProcessChildMessage(XUI_WM_DESTROY, nullptr, bHandled);
    return result;
}

} // namespace xui
