#ifndef SDL3HELPER_TRANSFORM_HPP
#define SDL3HELPER_TRANSFORM_HPP

#include "structs.hpp"

namespace sdl3_helper {

class Transform {

public:
  position pos;
  Vec2f scale;
  float angle;

  Transform(position _pos = {0, 0}, Vec2f _scale = {1, 1}, float _angle = 0);
  Transform(float x, float y, Vec2f _scale = {1, 1}, float _angle = 0);

  void transform(float x, float y);
  void transform(Vec2f offset);

  void rotate(float a);
  void scaleX(float amount);
  void scaleY(float amount);
  void scaleXY(Vec2f amount);
};

}; // namespace sdl3_helper

#endif
