#pragma once

#include <xui/gragh/rect.h>

namespace xui
{

class NativeWindow
{
  public:
    NativeWindow();
    ~NativeWindow();

    bool Create(const Rect &rect, const char *title);
    bool Destroy();

  private:
    void *oc_window_;
};

} // namespace xui
