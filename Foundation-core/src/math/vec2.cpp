#include "vec2.h"

namespace foundation {
namespace math {

    vec2::vec2() : vec2(0.0f, 0.0f) {}
    vec2::vec2(const vec2& other) : vec2(other.x, other.y) {}
    vec2::vec2(const float& x, const float& y)
    {
        this->x = x;
        this->y = y;
    }

    vec2& vec2::add(const vec2& b) {
        this->x += b.x;
        this->y += b.y;
        return *this;
    }

    vec2& vec2::subtract(const vec2& b)
    {
        this->x -= b.x;
        this->y -= b.y;
        return *this;
    }

    vec2& vec2::multiply(const vec2& b)
    {
        this->x *= b.x;
        this->y *= b.y;
        return *this;
    }

    vec2& vec2::divide(const vec2& b)
    {
        this->x /= b.x;
        this->y /= b.y;
        return *this;
    }

    std::ostream& operator<< (std::ostream& out, const vec2& vec)
    {
        return out << "(" << vec.x << ", " << vec.y << ")";
    }
}
}