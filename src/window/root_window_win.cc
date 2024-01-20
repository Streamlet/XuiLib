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

bool RootWindow::Create(const RootWindow *owner, const Rect &rect, const string &caption)
{
    rect_ = rect;
    return native_window_->Create(owner == nullptr ? nullptr : (HWND)*owner->native_window_, rect,
                                  WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, ROOT_WINDOW_CLASS_NAME,
                                  caption.c_str());
}

bool RootWindow::Destroy()
{
    return native_window_->Destroy();
}

} // namespace xui
