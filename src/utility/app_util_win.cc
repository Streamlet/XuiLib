#include <Windows.h>
#include <xui/utility/app_util.h>

namespace xui
{

namespace app_util
{

void Quit()
{
    ::PostQuitMessage(0);
}

} // namespace app_util

} // namespace xui
