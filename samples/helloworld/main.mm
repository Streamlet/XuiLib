#import <Cocoa/Cocoa.h>
#import "main_window.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        MainWindow mainWindow;
        mainWindow.Create(nullptr, xui::Rect(0, 0, 400, 300), _T("Hello, world!"));

        NSApplication *app = [NSApplication sharedApplication];
        [app run];
    }
    
    return 0;
}
