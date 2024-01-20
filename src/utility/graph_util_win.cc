#include "graph_util_win.h"

namespace xui
{

namespace graph_util
{

HBITMAP CreateBitmap(int width, int height, LPVOID *data)
{
    BITMAPINFO bmp = {};
    bmp.bmiHeader.biSize = sizeof(BITMAPINFO);
    bmp.bmiHeader.biWidth = width;
    bmp.bmiHeader.biHeight = -height;
    bmp.bmiHeader.biPlanes = 1;
    bmp.bmiHeader.biBitCount = 32;
    bmp.bmiHeader.biCompression = BI_RGB;

    HWND hWnd = GetDesktopWindow();
    HDC hDC = GetDC(hWnd);
    HBITMAP hBitmap = CreateDIBSection(hDC, &bmp, DIB_RGB_COLORS, data, nullptr, 0);
    ReleaseDC(hWnd, hDC);

    return hBitmap;
}

} // namespace graph_util

} // namespace xui
