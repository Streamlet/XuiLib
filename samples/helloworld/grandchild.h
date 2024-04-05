#pragma once

#include <xui/xuilib.h>

class Grandchild : public xui::ChildWindow
{
  public:
    Grandchild();
    ~Grandchild();

  private:
    void *OnPaint(xui::WindowMessage msg, void *param, bool &handled);
};
