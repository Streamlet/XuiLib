#pragma once

#include <xui/gragh/rect.h>
#include <xui/window/root_window.h>

namespace xui
{

class NativeWindow
{
  public:
    NativeWindow(RootWindow *window);
    ~NativeWindow();

    bool Create(const Rect &rect, const char *title);
    bool Destroy();

  public:
    void *ProcessMessage(WindowMessage msg, void *param, bool &handled);

  private:
    RootWindow *window_;
    void *ns_window_;
};

} // namespace xui
