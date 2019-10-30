#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <spdlog/spdlog.h>

namespace impl {
class TextureManager {
public:
	TextureManager(const TextureManager&) = delete;
	TextureManager(TextureManager&&) = delete;
	TextureManager& operator=(TextureManager&&) = delete;

	static TextureManager& instance() {
		static TextureManager singleton;
		return singleton;
	}

	sf::Texture& get(std::string texture);
	bool load(std::string texture);
	/** Returns true if can delete or returns false if can't delete or texture isn't loaded */
	bool remove(std::string texture);
	void clear();
	bool exists(std::string texture);
private:
	TextureManager() { SPDLOG_INFO("Initialized TextureManager"); }
	~TextureManager();

	std::map<std::string, sf::Texture*> textures;
};
};

inline impl::TextureManager& TextureManager() {
	return impl::TextureManager::instance();
}