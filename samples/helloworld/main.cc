#include "main_window.h"
#include <tchar.h>
#include <Windows.h>

int WINAPI _tWinMain(__in HINSTANCE hInstance,
                     __in_opt HINSTANCE hPrevInstance,
                     __in LPTSTR lpCmdLine,
                     __in int nShowCmd)
{
    MainWindow mainWindow;
    mainWindow.Create(nullptr, xui::Rect(0, 0, 400, 300));

    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
