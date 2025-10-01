#ifndef SDL3HELPER_SHAREDCTX_HPP
#define SDL3HELPER_SHAREDCTX_HPP

#include <SDL3/SDL.h>
#include <optional>

namespace sdl3_helper {

struct SharedCtx {
  SDL_Window *window {nullptr};
  SDL_Renderer *renderer {nullptr};
};

std::optional<SharedCtx> create_shared_ctx(int w, int h);
void destroy_shared_ctx(SharedCtx ctx);

};


#endif
