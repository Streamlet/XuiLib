#pragma once

#include "point.h"
#include "size.h"

namespace xui
{

struct Rect
{
    /**
     * Left
     */
    int l;

    /**
     * Top
     */
    int t;

    /**
     * Right
     */
    int r;

    /**
     * Bottom
     */
    int b;

    Rect() : l(0), t(0), r(0), b(0)
    {
    }

    Rect(int l, int t, int r, int b) : l(l), t(t), r(r), b(b)
    {
    }

    Rect(const Point &p, const Size &s) : l(p.x), t(p.y), r(p.x + s.w), b(p.y + s.h)
    {
    }

    /**
     * Width
     */
    inline int W() const
    {
        return r - l;
    }

    /**
     * Height
     */
    inline int H() const
    {
        return b - t;
    }

    /**
     * Size
     */
    inline Size Size() const
    {
        return xui::Size(r - l, b - t);
    }

    /**
     * Top left
     */
    inline Point TL() const
    {
        return Point(l, t);
    }

    /**
     * Top right
     */
    inline Point TR() const
    {
        return Point(r, t);
    }

    /**
     * Bottom left
     */
    inline Point BL() const
    {
        return Point(l, b);
    }

    /**
     * Bottom right
     */
    inline Point BR() const
    {
        return Point(r, b);
    }
};

} // namespace xui
