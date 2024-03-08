#include "gdi_renderer_win.h"
#include <atlconv.h>
#include <cassert>
#include <gdiplus.h>

namespace xui
{

GdiRenderer::GdiRenderer() : hdc_(nullptr)
{
    static bool gdi_plus_initialized = false;
    if (!gdi_plus_initialized)
    {
        Gdiplus::GdiplusStartupInput gdiplusStartupInput;
        ULONG_PTR gdiplusToken = 0;
        Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
        gdi_plus_initialized = true;
    }
}

GdiRenderer::~GdiRenderer()
{
    assert(hdc_ == nullptr);
}

void GdiRenderer::AttachDC(HDC hdc)
{
    assert(hdc_ == nullptr);
    hdc_ = hdc;
}

void GdiRenderer::DetachDC()
{
    assert(hdc_ != nullptr);
    hdc_ = nullptr;
}

void GdiRenderer::DrawPoint(Point point, Color color)
{
}

void GdiRenderer::DrawLine(Point from, Point to, Color)
{
}

void GdiRenderer::DrawBezierCurve(Point p0, Point p1, Point p2, Color)
{
}

void GdiRenderer::DrawCubicBezierCurve(Point p0, Point p1, Point p2, Point p3, Color)
{
}

void GdiRenderer::DrawArc(Rect bounding_rect, unsigned short from_angle, unsigned to_angle, Color color)
{
}

void GdiRenderer::DrawRect(Rect rect, Color color)
{
}

void GdiRenderer::DrawEllipse(Rect bounding_rect, Color color)
{
}

void GdiRenderer::FillRect(Rect rect, Color color)
{
    Gdiplus::Graphics graph(hdc_);
    Gdiplus::SolidBrush brush(color.argb);
    graph.FillRectangle(&brush, rect.l, rect.t, rect.W(), rect.H());
}

void GdiRenderer::FillEllipse(Rect bounding_rect, Color color)
{
}

void GdiRenderer::PrintText(const string &text,
                            Rect bounding_rect,
                            Color color,
                            TextAlign x_align,
                            TextAlign y_align,
                            const string &font_face,
                            unsigned short font_size,
                            bool bold,
                            bool italic,
                            bool underlined)
{
}

void GdiRenderer::PrintImage(Image *image, Rect rect, Rect image_region, uint8_t alpha)
{
}

void GdiRenderer::Dump()
{
}

} // namespace xui
