#include "structs.hpp"

using namespace sdl3_helper;

Vec2f sdl3_helper::operator+(Vec2f v1, Vec2f v2) {
  return {v1.x + v2.x, v1.y + v2.y};
}

Vec2i operator+(Vec2i v1, Vec2i v2) { return {v1.x + v2.x, v1.y + v2.y}; }
