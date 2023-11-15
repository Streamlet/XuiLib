#pragma once

#include <xui/xuilib.h>

class MainWindow : public xui::RootWindow
{
  public:
    MainWindow();
    ~MainWindow();

  private:
    void *OnDestroy(xui::WindowMessage msg, void *param, bool &handled);
};
