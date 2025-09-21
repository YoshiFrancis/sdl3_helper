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

typedef Vec2f position;
typedef std::function<void()> callback;

}

#endif
