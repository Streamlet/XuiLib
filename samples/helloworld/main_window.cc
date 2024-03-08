#include "main_window.h"
#include <xui/renderer/renderer.h>
#include <xui/utility/app_util.h>

MainWindow::MainWindow()
{
    using namespace std::placeholders;
    RegisterMessaheHandler(xui::XUI_WM_DESTROY, std::bind(&MainWindow::OnDestroy, this, _1, _2, _3));
    RegisterMessaheHandler(xui::XUI_WM_PAINT, std::bind(&MainWindow::OnPaint, this, _1, _2, _3));
}

MainWindow::~MainWindow()
{
}

void *MainWindow::OnDestroy(xui::WindowMessage msg, void *param, bool &handled)
{
    xui::app_util::Quit();
    return nullptr;
}

void *MainWindow::OnPaint(xui::WindowMessage msg, void *param, bool &handled)
{
    xui::Renderer *renderer = (xui::Renderer *)param;
    return nullptr;
}
