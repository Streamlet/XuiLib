#include "child.h"
#include <xui/renderer/renderer.h>
#include <xui/utility/app_util.h>

Child::Child()
{
    using namespace std::placeholders;
    RegisterMessaheHandler(xui::XUI_WM_CREATE, std::bind(&Child::OnCreate, this, _1, _2, _3));
    RegisterMessaheHandler(xui::XUI_WM_DESTROY, std::bind(&Child::OnDestroy, this, _1, _2, _3));
    RegisterMessaheHandler(xui::XUI_WM_PAINT, std::bind(&Child::OnPaint, this, _1, _2, _3));
}

Child::~Child()
{
}

void *Child::OnCreate(xui::WindowMessage msg, void *param, bool &handled)
{
    grandchild_.Create(this, xui::Rect(50, 25, 150, 75));
    return nullptr;
}

void *Child::OnDestroy(xui::WindowMessage msg, void *param, bool &handled)
{
    grandchild_.Destroy();
    return nullptr;
}

void *Child::OnPaint(xui::WindowMessage msg, void *param, bool &handled)
{
    xui::Renderer *renderer = (xui::Renderer *)param;
    renderer->FillRect(ClientRect(), xui::Color::Color(0, 0, 255, 128));
    renderer->FillRect(xui::Rect(100, 50, 200, 150), xui::Color::Color(0, 255, 0, 128));
    return nullptr;
}
