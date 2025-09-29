#include "AnimatedTexture.hpp"

using namespace sdl3_helper;

AnimatedTexture::AnimatedTexture(std::string_view file_path,
                                 size_t _total_frames,
                                 size_t _frames_per_sprite,
                                 std::shared_ptr<SDL_Renderer> _renderer,
                                 Transform _transform)
    : Texture(file_path, _renderer, _transform), total_frames(_total_frames),
      frames_per_sprite(_frames_per_sprite) {
  width /= total_frames;
  sprite_clips = gen_sprite_clips(_total_frames, static_cast<float>(width),
                                  static_cast<float>(height));
}

void AnimatedTexture::render(position parent_pos) {
  if (curr_frame / frames_per_sprite >= total_frames) {
    curr_frame = 0;
  }
  SDL_FRect &dstrect = sprite_clips[curr_frame / frames_per_sprite];
  SDL_RenderTexture(renderer.get(), texture, nullptr, &dstrect);
  ++curr_frame;
}

std::vector<SDL_FRect>
AnimatedTexture::gen_sprite_clips(size_t t_frames, float w, float h) const {
  std::vector<SDL_FRect> genSpriteClips(t_frames);
  for (size_t i = 0; i < t_frames; ++i) {
    genSpriteClips[i] = {w * i, 0.f, w, h};
  }
  return genSpriteClips;
}
