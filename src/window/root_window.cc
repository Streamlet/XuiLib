#include <xui/window/root_window.h>

#if defined(_WIN32)
#include "native_window_win.h"
#elif defined(__APPLE__)
#include "native_window_mac.h"
#endif

#if defined(_WIN32)
const TCHAR *ROOT_WINDOW_CLASS_NAME = _T("XUI_ROOT_WINDOW");

#endif

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
    return native_window_->Create(owner == nullptr ? nullptr : (HWND)*owner->native_window_, rect,
                                  WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, ROOT_WINDOW_CLASS_NAME, caption.c_str());
}

bool RootWindow::Destroy()
{
    return native_window_->Destroy();
}

} // namespace xui
