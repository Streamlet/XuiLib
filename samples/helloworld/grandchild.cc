#include "grandchild.h"
#include <xui/renderer/renderer.h>
#include <xui/utility/app_util.h>

Grandchild::Grandchild()
{
    using namespace std::placeholders;
    RegisterMessaheHandler(xui::XUI_WM_PAINT, std::bind(&Grandchild::OnPaint, this, _1, _2, _3));
}

Grandchild::~Grandchild()
{
}

void *Grandchild::OnPaint(xui::WindowMessage msg, void *param, bool &handled)
{
    xui::Renderer *renderer = (xui::Renderer *)param;
    renderer->FillRect(ClientRect(), xui::Color::Color(255, 255, 0, 128));
    return nullptr;
}
