#pragma once

#import <Cocoa/Cocoa.h>

@interface NSNativeWindow : NSWindow
{
    NSButton *button_;
}

- (bool)createWithRect:(NSRect)rect title:(NSString *)title;

@end
