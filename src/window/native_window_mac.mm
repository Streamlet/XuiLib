#import "native_window_mac.h"
#import "ns_native_window_mac.h"

namespace xui
{

NativeWindow::NativeWindow(Window *window) : window_(window), ns_window_((__bridge void *) [NSNativeWindow alloc] ) {
    [(__bridge NSNativeWindow *)ns_window_ initWithNativeWindow:this];
}

NativeWindow::~NativeWindow() {

}

bool NativeWindow::Create(const Rect &rect, const char *title) {
    NSRect screenRect = [[NSScreen mainScreen] visibleFrame];
    NSRect nsRect = NSMakeRect(rect.l, screenRect.size.height - rect.t, rect.W(), rect.H());
    NSString *nsTitle = [[NSString alloc] initWithUTF8String:title];
    return [(__bridge NSNativeWindow *)ns_window_ createWithRect:nsRect title:nsTitle];
}

bool NativeWindow::Destroy() {
    return true;
}

void *NativeWindow::ProcessMessage(WindowMessage msg, void *param, bool &handled)
{
    return window_->ProcessMessage(msg, param, handled);
}


} // namespace xui
