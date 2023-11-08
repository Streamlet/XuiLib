#include <xui/window/root_window.h>

#include "native_window_mac.h"

namespace xui
{

RootWindow::RootWindow() : native_window_(std::make_unique<NativeWindow>())
{
}

RootWindow::~RootWindow()
{
}

bool RootWindow::Create(const RootWindow *owner, const Rect &rect, const string &caption)
{
    return native_window_->Create(rect, caption.c_str());
}

bool RootWindow::Destroy()
{
    return native_window_->Destroy();
}

} // namespace xui
