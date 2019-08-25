#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <spdlog/spdlog.h>
/* 
class TextureManager {
private:
    TextureManager() { SPDLOG_INFO("Initialized TextureManager"); }
    ~TextureManager();

    std::map<std::string, sf::Texture*> textures;
public:
    TextureManager(const TextureManager&) = delete;
    TextureManager(TextureManager &&) = delete;
    TextureManager& operator=(TextureManager &&) = delete;

    static TextureManager& instance() {
        static TextureManager singleton;
        return singleton;
    }

    sf::Texture& get(std::string texture);
};

inline TextureManager& tm2() {
    return TextureManager::instance();
}
*/

namespace impl {
    class TextureManager {
    private:
        TextureManager() { SPDLOG_INFO("Initialized TextureManager"); }
        ~TextureManager();

        std::map<std::string, sf::Texture*> textures;
    public:
        TextureManager(const TextureManager&) = delete;
        TextureManager(TextureManager &&) = delete;
        TextureManager& operator=(TextureManager &&) = delete;

        static TextureManager& instance() {
            static TextureManager singleton;
            return singleton;
        }

        sf::Texture& get(std::string texture);
    };
};

inline impl::TextureManager& TextureManager() {
    return impl::TextureManager::instance();
}