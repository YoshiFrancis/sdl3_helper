#include "Texture.hpp"

#include <SDL3/SDL_rect.h>
#include <SDL3_image/SDL_image.h>

#include <filesystem>
#include <iostream>

using namespace sdl3_helper;

Texture::Texture(std::string_view file_path, std::shared_ptr<SDL_Renderer> _renderer, Transform _transform) 
    : transform(_transform), width(0), height(0), renderer(_renderer)
{
    load_texture(file_path);
}

Texture::~Texture() {
    destroy();
}

void Texture::render(position parent_pos) {
    position render_pos = parent_pos + transform.pos;
    SDL_FRect dstrect{render_pos.x, render_pos.y, static_cast<float>(width) * transform.scale.x, static_cast<float>(height) * transform.scale.y};
    SDL_RenderTexture(renderer.get(), texture, nullptr, &dstrect);
}

void Texture::destroy() {
    SDL_DestroyTexture(texture);
    texture = nullptr;
    width = 0;
    height = 0;
}

position Texture::get_position() {
    return transform.pos;
}

void Texture::load_texture(std::string_view file_path) {
    destroy();
    if (std::filesystem::exists(file_path)) {
        SDL_Log("File exists: %s", file_path.data());
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "File not found: %s", file_path.data());
    }
    SDL_Surface* loaded_surface = IMG_Load(file_path.data());
    if (loaded_surface == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to load the image %s. SDL_Image error: %s", file_path.data(), SDL_GetError());
        SDL_DestroySurface(loaded_surface);
        return;
    }
    texture = SDL_CreateTextureFromSurface(renderer.get(), loaded_surface);
    if (texture == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to create texture: %s. SDL_Image error: %s", file_path.data(), SDL_GetError());
    } else {
        width = texture->w;
        height = texture->h;
    }
    SDL_DestroySurface(loaded_surface);
}
