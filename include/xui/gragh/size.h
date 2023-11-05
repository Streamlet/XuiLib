#pragma once

namespace xui
{

struct Size
{
    /**
     * Width
     */
    int w;

    /**
     * Height
     */
    int h;

    Size() : w(0), h(0)
    {
    }

    Size(int w, int h) : w(w), h(h)
    {
    }
};

} // namespace xui
