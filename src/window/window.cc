#include <xui/window/window.h>

namespace xui
{

Window::Window()
{
}

Window ::~Window()
{
}

void Window::RegisterMessaheHandler(WindowMessage msg, MsgHandler handler)
{
#ifdef _DEBUG

#endif
    msg_handlers_.emplace(msg, handler);
}

void *Window::ProcessMessage(WindowMessage msg, void *param, bool &handled)
{
    void *result = 0;
    for (auto it = msg_handlers_.lower_bound(msg), end = msg_handlers_.upper_bound(msg); it != end; ++it)
    {
        result = it->second(msg, param, handled);
        if (handled)
        {
            return result;
        }
    }
    handled = false;
    return result;
}

} // namespace xui