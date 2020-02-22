#pragma once

#include <map>
#include <filesystem>
#include <tuple>

#include <SFML/Graphics/Texture.hpp>
#include <spdlog/spdlog.h>

#include <texturepacker.hpp>

static char OBSTACLE_PATH[] = "assets/obstacles/";

enum class TextureType {
	Normal,
	Obstacle
};

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

	sf::Texture& get(std::string name);
	sf::Texture& get_obstacles() { return obstacles; }
	sf::IntRect& get_obstacle_rect(uint16_t id) { return obstacle_rects[id]; }

	bool load(std::string name, TextureType type);
	void load_from_memory(sf::Texture* texture, std::string name, TextureType type);

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