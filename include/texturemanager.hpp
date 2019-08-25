#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <spdlog/spdlog.h>

class TextureManager {
private:
    TextureManager() { SPDLOG_INFO("Initialized TextureManager"); }
    TextureManager( const TextureManager & ) {}
    ~TextureManager();

    std::map<std::string, sf::Texture*> textures;
public:
    static TextureManager& i() {
        static TextureManager singleton;
        return singleton;
    }

    sf::Texture& get(std::string texture);
};
