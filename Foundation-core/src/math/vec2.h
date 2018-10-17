#pragma once

#include <iostream>

namespace foundation {
namespace math {

    struct vec2
    {
        float x, y;

        vec2();
        vec2(const vec2 &other);
        vec2(const float& x, const float& y);

        friend vec2 operator+(vec2 a, const vec2& b) { return a.add(b); }
        friend vec2 operator-(vec2 a, const vec2& b) { return a.subtract(b); }
        friend vec2 operator*(vec2 a, const vec2& b) { return a.multiply(b); }
        friend vec2 operator/(vec2 a, const vec2& b) { return a.divide(b); }

        vec2& operator +=(const vec2& b) { return this->add(b); }
        vec2& operator -=(const vec2& b) { return this->subtract(b); }
        vec2& operator *=(const vec2& b) { return this->multiply(b); }
        vec2& operator /=(const vec2& b) { return this->divide(b); }
    
        friend std::ostream& operator<< (std::ostream& out, const vec2& vec);

    private:
        vec2& add(const vec2& b);
        vec2& subtract(const vec2& b);
        vec2& multiply(const vec2& b);
        vec2& divide(const vec2& b);
    };
}
}
