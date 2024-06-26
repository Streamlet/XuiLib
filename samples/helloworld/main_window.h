#pragma once

#include "child.h"
#include <xui/xuilib.h>

class MainWindow : public xui::RootWindow
{
  public:
    MainWindow();
    ~MainWindow();

  private:
    void *OnCreate(xui::WindowMessage msg, void *param, bool &handled);
    void *OnDestroy(xui::WindowMessage msg, void *param, bool &handled);
    void *OnPaint(xui::WindowMessage msg, void *param, bool &handled);

  private:
    Child child_;
};
