#pragma once

#include <xui/gragh/rect.h>
#include <xui/window/window.h>

namespace xui
{

class NativeWindow
{
  public:
    NativeWindow(Window *window);
    ~NativeWindow();

    bool Create(const Rect &rect, const char *title);
    bool Destroy();

  public:
    void *ProcessMessage(WindowMessage msg, void *param, bool &handled);

  private:
    Window *window_;
    void *ns_window_;
};

} // namespace xui
