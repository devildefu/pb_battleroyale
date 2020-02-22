#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <spdlog/spdlog.h>
#include <filesystem>

#include <texturepacker.hpp>

static char OBSTACLE_PATH[] = "assets/obstacles/";

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
	sf::Texture& get_obstacles() { return obstacles; }
	sf::IntRect& get_obstacle_rect(uint16_t id);

	bool load(std::string texture);
	void load_obstacle(std::string texture);

	/** 
	 * Returns true if can delete or returns false if can't delete or texture isn't loaded 
	 */
	bool remove(std::string texture);

	void clear();
	bool exists(std::string texture);
private:
	TextureManager();
	~TextureManager();

	TexturePacker* obstacle_packer = nullptr;
	sf::Texture obstacles;
	std::vector<sf::IntRect> obstacle_rects;

	std::map<std::string, sf::Texture*> textures;
};
};

inline impl::TextureManager& TextureManager() {
	return impl::TextureManager::instance();
}