#ifndef SDL3HELPER_BUTTON_HPP
#define SDL3HELPER_BUTTON_HPP

#include "AudioPlayer.hpp"
#include "IAnimatable.hpp"
#include "IClickable.hpp"
#include "Texture.hpp"
#include "Transform.hpp"

#include "structs.hpp"

#include <string>
#include <string_view>

namespace sdl3_helper {

class Button : public IClickable {

private:
  Transform transform;
  callback onClick;
  std::unique_ptr<Texture> texture = nullptr;
  std::unique_ptr<AudioPlayer> sound = nullptr;

  float width = 0;
  float height = 0;
  std::string text;
  bool enabled = true;

public:
  Button(Transform _transform, float w, float h, std::string_view t,
         callback _onClick = nullptr, std::string_view texture_path = "",
         std::string_view audio_path = "", bool _enabled = true);

  void disable();
  void enable();
  void render();

  // IClickable
  bool clicked(float mx, float my) override;
  bool hovered(float mx, float my) override;

private:
};

}; // namespace sdl3_helper

#endif
