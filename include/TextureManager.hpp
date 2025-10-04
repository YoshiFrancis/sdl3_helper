#ifndef YOSHISDL3_TEXTUREMANAGER_HPP
#define YOSHISDL3_TEXTUREMANAGER_HPP

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "Texture.hpp"

#include <unordered_map>
#include <string>
#include <string_view>
#include <optional>

/*
 * Responsible for loading in the textures for files then managing them.
 * Take away responsibility from individual textures so we can have global
 * tracking of all textures already. This prevents redundant loading.
 * TextureManager ac ts as a factory.
 */

namespace yoshi_sdl3 {

class TextureManager {

    struct TexStruct {
        SDL_Texture* texture = nullptr;
        unsigned int rendered_so_far = 0;
    };

    private:
        std::unordered_map<std::string, TexStruct> texture_map;

    public:

        std::optional<Texture> new_texture(std::string_view file_path);
        bool load_textures(std::vector<std::string>& file_paths);
    private:
        bool load_texture(std::string_view file_path);
};

};

#endif
