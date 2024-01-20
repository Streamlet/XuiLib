#pragma once

#include "../gragh/color.h"
#include "../gragh/image.h"
#include "../gragh/point.h"
#include "../gragh/rect.h"
#include "../gragh/size.h"
#include "../utility/string.h"
#include <cstdint>

namespace xui
{

enum class TextAlign
{
    Start,
    Center,
    End,
};

struct Renderer
{
    virtual ~Renderer()
    {
    }

    virtual void DrawPoint(Point point, Color color) = 0;
    virtual void DrawLine(Point from, Point to, Color color) = 0;
    virtual void DrawBezierCurve(Point p0, Point p1, Point p2, Color color) = 0;
    virtual void DrawCubicBezierCurve(Point p0, Point p1, Point p2, Point p3, Color color) = 0;
    virtual void DrawArc(Rect bounding_rect, unsigned short from_angle, unsigned to_angle, Color color) = 0;
    virtual void DrawRect(Rect rect, Color color) = 0;
    virtual void DrawEllipse(Rect bounding_rect, Color color) = 0;
    virtual void FillRect(Rect rect, Color color) = 0;
    virtual void FillEllipse(Rect bounding_rect, Color color) = 0;
    virtual void PrintText(const string &text,
                           Rect bounding_rect,
                           Color color,
                           TextAlign x_align,
                           TextAlign y_align,
                           const string &font_face,
                           unsigned short font_size,
                           bool bold,
                           bool italic,
                           bool underlined) = 0;
    virtual void PrintImage(Image *image, Rect rect, Rect image_region, uint8_t alpha) = 0;
};

} // namespace xui
