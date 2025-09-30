#include "GlobalSingleton.hpp"

using namespace sdl3_helper;

GlobalSingleton::~GlobalSingleton() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Log("Global Singletone Destructor called");
}

bool GlobalSingleton::init(int w, int h) {
    bool success{true};
    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                "failed to initialize SDL (test.cpp:init()). SDL error: %s\n",
                SDL_GetError());
        success = false;
    }
    if (success) {
        if (!init_window_and_renderer(w, h)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "failed to create window or renderer (test.cpp:init()). SDL "
                    "error: %s\n",
                    SDL_GetError());
            success = false;
        } 
    }
    return success;
}


SDL_Window* GlobalSingleton::get_window() {
    return instance->window;
}

SDL_Renderer *GlobalSingleton::get_renderer() {
    return instance->renderer;
}

bool GlobalSingleton::init_window_and_renderer(int w, int h) {
  if (SDL_CreateWindowAndRenderer("Testing Window", w, h, 0, &window,
                                  &renderer) == false) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "failed to create window or renderer (GlobalSingleton.cpp:init_window_and_renderer) SDL error: %s\n",
                 SDL_GetError());
    return false;
  }
  return true;
}

