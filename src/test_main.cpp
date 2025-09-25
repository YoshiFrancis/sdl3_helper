#include "test.hpp"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <cassert>
#include <iostream>

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;
SDL_Window *window = nullptr;
SDL_Surface *image = nullptr;
SDL_Surface *screenSurface = nullptr;

bool init() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    std::cout << "SDL could not initialize! SDL_Error: %s\n", SDL_GetError();
    return false;
  }
  window = SDL_CreateWindow("SDL Window", SCREEN_WIDTH, SCREEN_HEIGHT,
                            SDL_WINDOW_RESIZABLE);
  if (window == nullptr) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n",
                 SDL_GetError());
    return false;
  }

  screenSurface = SDL_GetWindowSurface(window);
  return true;
}

bool loadMedia() {
  const char *img_path = "files/BananaSplit.png";
  SDL_Surface *tmp_image = IMG_Load(img_path);
  if (tmp_image == nullptr) {
    SDL_Log("Failed to load in image at path: %s", img_path);
    return false;
  }

  image = SDL_ConvertSurface(tmp_image, screenSurface->format);
  if (image == nullptr) {
    SDL_Log("Failed to optimize image %s! SDL error: %s\n", img_path,
            SDL_GetError());
    return false;
    SDL_DestroySurface(tmp_image);
  }

  return true;
}

void close_sdl() {
  SDL_Log("Closing sdl");
  SDL_DestroySurface(image);
  image = nullptr;
  SDL_DestroyWindow(window);
  window = nullptr;
  SDL_Quit();
}

int lol() {
  if (!init()) {
    return EXIT_FAILURE;
  }

  if (!loadMedia()) {
    return EXIT_FAILURE;
  }

  SDL_BlitSurface(image, nullptr, screenSurface, nullptr);
  loadMedia();

  const SDL_PixelFormatDetails *fmt =
      SDL_GetPixelFormatDetails(screenSurface->format);

  SDL_Event e;
  bool quit = false;
  while (quit != true) {
    while (SDL_PollEvent(&e)) {
      SDL_Rect stretchRect;
      stretchRect.x = 0;
      stretchRect.y = 0;
      stretchRect.w = SCREEN_WIDTH;
      stretchRect.h = SCREEN_HEIGHT;
      SDL_BlitSurfaceScaled(image, nullptr, screenSurface, &stretchRect,
                            SDL_SCALEMODE_NEAREST);
      SDL_UpdateWindowSurface(window);
      switch (e.type) {
      case SDL_EVENT_QUIT:
        quit = true;
      case SDL_EVENT_KEY_DOWN:
        if (e.key.key == SDLK_RIGHT) {
          SDL_Log("Going right!");
        } else {
          SDL_Log("some key got pressed");
        }
      }
    }
  }

  close_sdl();
  return 0;
}
