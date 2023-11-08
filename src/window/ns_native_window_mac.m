#import "ns_native_window_mac.h"

@implementation NSNativeWindow

- (bool)createWithRect:(NSRect)rect title:(NSString *)title {
    NSUInteger uiStyle = NSWindowStyleMaskClosable |
                         NSWindowStyleMaskMiniaturizable |
                         NSWindowStyleMaskResizable |
                         NSWindowStyleMaskTitled;
    NSBackingStoreType backingStoreStyle = NSBackingStoreBuffered;
    NSNativeWindow* window = [self initWithContentRect:rect
                                   styleMask:uiStyle
                                   backing:backingStoreStyle
                                   defer:NO];

    [window setTitle:title];
    [window setContentView:[[NSView alloc] init]];
    [window orderFront:nil];

    return true;
}

@end
