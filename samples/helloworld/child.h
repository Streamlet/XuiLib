#pragma once

#include "grandchild.h"
#include <xui/xuilib.h>

class Child : public xui::ChildWindow
{
  public:
    Child();
    ~Child();

  private:
    void *OnCreate(xui::WindowMessage msg, void *param, bool &handled);
    void *OnDestroy(xui::WindowMessage msg, void *param, bool &handled);
    void *OnPaint(xui::WindowMessage msg, void *param, bool &handled);

  private:
    Grandchild grandchild_;
};
