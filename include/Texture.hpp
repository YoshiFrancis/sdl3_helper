#ifndef SDL3HELPER_TEXTURE_HPP
#define SDL3HELPER_TEXTURE_HPP

#include "Transform.hpp"
#include "structs.hpp"

#include <memory>
#include <string_view>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace sdl3_helper {

class Texture {

private:
  Transform transform;
  int width;
  int height;
  std::unique_ptr<SDL_Texture> texture;

public:
  Texture(std::string_view file_path, Transform _transform);
  position get_position();
  Transform &get_transform_ref();
  const Transform &get_transform_const_ref();
};

}; // namespace sdl3_helper

#endif
