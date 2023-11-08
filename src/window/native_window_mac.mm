#import "native_window_mac.h"
#import "ns_native_window_mac.h"

namespace xui
{

NativeWindow::NativeWindow() : oc_window_((__bridge void *) [NSNativeWindow alloc] ) {

}

NativeWindow::~NativeWindow() {

}

bool NativeWindow::Create(const Rect &rect, const char *title) {
    NSRect screenRect = [[NSScreen mainScreen] visibleFrame];
    NSRect nsRect = NSMakeRect(rect.l, screenRect.size.height - rect.t, rect.W(), rect.H());
    NSString *nsTitle = [[NSString alloc] initWithUTF8String:title];
    return [(__bridge NSNativeWindow *)oc_window_ createWithRect:nsRect title:nsTitle];
}
bool NativeWindow::Destroy() {
    return true;
}

} // namespace xui
