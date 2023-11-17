#import "ns_native_window_mac.h"


@implementation NSNativeWindow

- (instancetype)initWithNativeWindow:(xui::NativeWindow *)native_window
{
    native_window_ = native_window;
    return self;
}

- (bool)createWithRect:(NSRect)rect title:(NSString *)title {
    NSUInteger uiStyle = NSWindowStyleMaskClosable |
                         NSWindowStyleMaskMiniaturizable |
                         NSWindowStyleMaskResizable |
                         NSWindowStyleMaskTitled;
    NSBackingStoreType backingStoreStyle = NSBackingStoreBuffered;
    [self initWithContentRect:rect
                                   styleMask:uiStyle
                                   backing:backingStoreStyle
                                   defer:NO];

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(windowWillClose:) name:NSWindowWillCloseNotification object:self];

    [self setTitle:title];
    [self setContentView:[[NSView alloc] init]];
    [self orderFront:nil];

    return true;
}

- (void)windowWillClose:(NSNotification *)notification {
    bool handled = true;
    native_window_->ProcessMessage(xui::XUI_WM_DESTROY, nullptr, handled);
}


@end
