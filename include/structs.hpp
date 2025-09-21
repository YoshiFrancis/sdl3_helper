#ifndef SDL3HELPER_STRUCTS_HPP
#define SDL3HELPER_STRUCTS_HPP

#include <tuple>
#include <functional>

namespace sdl3_helper {

struct Vec2f {
    float x;
    float y;
};

struct Vec2i {
    int x;
    int y;
};

Vec2f operator+(Vec2f v1, Vec2f v2);
Vec2i operator+(Vec2i v1, Vec2i v2);

typedef Vec2f position;
typedef std::function<void()> callback;

}

#endif
