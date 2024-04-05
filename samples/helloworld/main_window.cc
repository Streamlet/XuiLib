#include "main_window.h"
#include <xui/renderer/renderer.h>
#include <xui/utility/app_util.h>

MainWindow::MainWindow()
{
    using namespace std::placeholders;
    RegisterMessaheHandler(xui::XUI_WM_CREATE, std::bind(&MainWindow::OnCreate, this, _1, _2, _3));
    RegisterMessaheHandler(xui::XUI_WM_DESTROY, std::bind(&MainWindow::OnDestroy, this, _1, _2, _3));
    RegisterMessaheHandler(xui::XUI_WM_PAINT, std::bind(&MainWindow::OnPaint, this, _1, _2, _3));
}

MainWindow::~MainWindow()
{
}

void *MainWindow::OnCreate(xui::WindowMessage msg, void *param, bool &handled)
{
    child_.Create(this, xui::Rect(100, 100, 300, 200));
    return nullptr;
}

void *MainWindow::OnDestroy(xui::WindowMessage msg, void *param, bool &handled)
{
    child_.Destroy();
    xui::app_util::Quit();
    return nullptr;
}

void *MainWindow::OnPaint(xui::WindowMessage msg, void *param, bool &handled)
{
    xui::Renderer *renderer = (xui::Renderer *)param;
    renderer->FillRect(ClientRect(), xui::Color::Color(255, 255, 255));
    renderer->FillRect(xui::Rect(50, 50, 150, 150), xui::Color::Color(255, 0, 0, 128));
    return nullptr;
}
