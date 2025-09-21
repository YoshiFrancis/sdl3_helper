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
  SDL_Texture *texture;
  std::shared_ptr<SDL_Renderer> renderer = nullptr;

public:
  Texture(std::string_view file_path, Transform _transform,
          std::shared_ptr<SDL_Renderer> _renderer);
  ~Texture();

  void render(position parent_pos);
  void destroy();

  position get_position();

private:
  void load_texture(std::string_view file_path);
};

}; // namespace sdl3_helper

#endif
