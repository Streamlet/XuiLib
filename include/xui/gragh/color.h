#pragma once

#include <cstdint>

namespace xui
{

union Color {

    /**
     * hex literals: 0xAARRGGBB
     */
    uint32_t argb;

    struct
    {
        /**
         * Green
         */
        uint8_t b;

        /**
         * Green
         */
        uint8_t g;

        /**
         * Red
         */
        uint8_t r;

        /**
         * Alpha
         */
        uint8_t a;
    };

    Color() : argb(0)
    {
    }

    Color(uint32_t argb) : argb(argb)
    {
    }

    Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b), a(255)
    {
    }

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a)
    {
    }
};

} // namespace xui
