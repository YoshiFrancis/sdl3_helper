#include "SharedCtx.hpp"
#include "Texture.hpp"
#include "structs.hpp"

#include <optional>
#include <string_view>

using namespace sdl3_helper;

renderer_ptr renderer{nullptr};
window_ptr window{nullptr};
SharedCtx ctx;

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
  auto ctx_opt = create_shared_ctx(w, h);
  if (ctx_opt.has_value()) {
    ctx = ctx_opt.value();
    return true;
  }
  return false;
}

void renderTexture(std::string_view file_path) {
  Texture texture(file_path);
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
