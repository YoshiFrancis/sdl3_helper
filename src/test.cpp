#include "Texture.hpp"
#include "structs.hpp"

#include <optional>
#include <string_view>

using namespace sdl3_helper;

renderer_ptr renderer{nullptr};
window_ptr window{nullptr};

static std::optional<std::tuple<window_ptr, renderer_ptr>>
initWindowAndRenderer(int w, int h) {
  // both window and renderer used for initialization of shared ptr
  SDL_Window *lwindow{nullptr};     // local window
  SDL_Renderer *lrenderer{nullptr}; // local renderer

  if (SDL_CreateWindowAndRenderer("Testing Window", w, h, 0, &lwindow,
                                  &lrenderer) == false) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "failed to create window or renderer (test.cpp:init()). SDL "
                 "error: %s\n",
                 SDL_GetError());
    return std::nullopt;
  }

  window_ptr new_window = std::shared_ptr<SDL_Window>(
      lwindow, [](SDL_Window *_window) { SDL_DestroyWindow(_window); });
  renderer_ptr new_renderer =
      std::shared_ptr<SDL_Renderer>(lrenderer, [](SDL_Renderer *_renderer) {
        SDL_DestroyRenderer(_renderer);
      });

  return std::tuple{new_window, new_renderer};
}

bool init(int w, int h) {
  bool success{true};
  if (SDL_Init(SDL_INIT_VIDEO) == false) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "failed to initialize SDL (test.cpp:init()). SDL error: %s\n",
                 SDL_GetError());
    success = false;
  }
  if (success) {
    auto window_and_renderer_opt = initWindowAndRenderer(w, h);
    if (window_and_renderer_opt == std::nullopt) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                   "failed to create window or renderer (test.cpp:init()). SDL "
                   "error: %s\n",
                   SDL_GetError());
      success = false;
    } else {
      std::tie(window, renderer) = window_and_renderer_opt.value();
    }
  }
  return success;
}

void renderTexture(std::string_view file_path) {
  constexpr int width = 800;
  constexpr int height = 400;
  if (!init(width, height)) {
    SDL_Log("failed to initialize SDL in test.cpp:renderTexture");
    SDL_Quit();
    return;
  }
  Texture texture(file_path, renderer);
  if (!texture.is_loaded()) {
    SDL_Log("failed to load texture");
    return;
  }
  bool quit = false;
  SDL_Event e;
  SDL_zero(e);

  while (!quit) {
    while (SDL_PollEvent(&e) == true) {
      if (e.type == SDL_EVENT_QUIT) {
        quit = true;
      }
    }
    SDL_SetRenderDrawColor(renderer.get(), 0xFF, 0x00, 0xFF, 0xFF);
    SDL_RenderClear(renderer.get());
    texture.render({0, 0});
    SDL_RenderPresent(renderer.get());
  }
}
