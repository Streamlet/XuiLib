#import <Cocoa/Cocoa.h>
#include <xui/utility/app_util.h>

namespace xui
{

namespace app_util
{

void Quit()
{
    [NSApp terminate:nullptr];
}

} // namespace app_util

} // namespace xui
