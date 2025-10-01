#include "SharedCtx.hpp"

using namespace sdl3_helper;

#include <optional>
#include <string_view>

using namespace sdl3_helper;

std::optional<SharedCtx> create_shared_ctx(int w, int h) {
    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                "failed to initialize SDL (test.cpp:init()). SDL error: %s\n",
                SDL_GetError());
        return std::nullopt;
    }

    SharedCtx new_ctx;

    if (SDL_CreateWindowAndRenderer("Testing Window", w, h, 0, &(new_ctx.window),
                &(new_ctx.renderer)) == false) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                "failed to create window or renderer (test.cpp:init()). SDL "
                "error: %s\n",
                SDL_GetError());
        return std::nullopt;
    }
    return new_ctx;
}

void destroy_shared_ctx(SharedCtx ctx) {
    SDL_DestroyRenderer(ctx.renderer);
    SDL_DestroyWindow(ctx.window);
}
