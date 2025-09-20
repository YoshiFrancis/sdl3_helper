#ifndef SDL3HELPER_STRUCTS_HPP
#define SDL3HELPER_STRUCTS_HPP

#include <tuple>
#include <functional>

namespace sdl3_helper {

typedef std::tuple<float, float> position;
typedef std::tuple<float, float> Vec2f;
typedef std::tuple<int, int> Vec2i;
typedef std::function<void()> callback;

}

#endif
