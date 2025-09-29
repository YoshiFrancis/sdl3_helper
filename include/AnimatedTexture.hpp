#ifndef SDL3HELPER_ANIMATEXTURE_HPP
#define SDL3HELPER_ANIMATEXTURE_HPP

#include "Texture.hpp"
#include <vector>

namespace sdl3_helper {

class AnimatedTexture : public Texture {
  size_t curr_frame = 0;
  const size_t total_frames = 0;
  size_t frames_per_sprite = 1;
  std::vector<SDL_FRect> sprite_clips;

public:
  AnimatedTexture(std::string_view file_path, size_t _total_frames,
                  size_t _frames_per_sprite,
                  std::shared_ptr<SDL_Renderer> _renderer,
                  Transform _transform = {});
  virtual ~AnimatedTexture();

  // called every frame
  void render(position parent_pos) override;

private:
  std::vector<SDL_FRect> gen_sprite_clips(size_t t_frames, float w,
                                          float h) const;
};

} // namespace sdl3_helper

#endif
