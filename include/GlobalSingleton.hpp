#ifndef SDL3HELPER_GLOBALSINGLETON_HPP
#define SDL3HELPER_GLOBALSINGLETON_HPP

#include <SDL3/SDL.h>

namespace sdl3_helper {

class GlobalSingleton {

private:
  SDL_Renderer *renderer{nullptr};
  SDL_Window *window{nullptr};
  int width;
  int height;

  static GlobalSingleton *instance;

public:
  static bool init(int w, int h);
  static GlobalSingleton *get_instance();

  static SDL_Window *get_window();
  static SDL_Renderer *get_renderer();

  virtual ~GlobalSingleton();

private:
  GlobalSingleton(int w, int h);
  bool init_window_and_renderer(int w, int h);
};

}; // namespace sdl3_helper

#endif
