#pragma once

#import <Cocoa/Cocoa.h>
#include "native_window_mac.h"

@interface NSNativeWindow : NSWindow
{
    xui::NativeWindow *native_window_;
}

- (instancetype)initWithNativeWindow:(xui::NativeWindow *)native_window;
- (bool)createWithRect:(NSRect)rect title:(NSString *)title;

@end
