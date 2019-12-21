#pragma once

#include <algorithm>
#include <iterator>
#include <vector>
#include <cstdio>

#include "obstacle.hpp"
#include <spdlog/spdlog.h>

#include <managers/obstaclemanager.hpp>

constexpr uint8_t LOCATION_WIDTH = 32;
constexpr uint8_t LOCATION_HEIGHT = 18;
constexpr uint32_t LOCATION_BLOCKS_NUMBER = LOCATION_WIDTH*LOCATION_HEIGHT;

class Location : public sf::Drawable, public sf::Transformable {
public:
	Location(Location& loc);
	Location(sf::Texture& background, sf::Texture& tileset);
	Location(sf::Texture& background, sf::Texture& tileset, uint16_t map[], int size = LOCATION_BLOCKS_NUMBER);
	Location(sf::Texture& background, sf::Texture& tileset, const char* fname);

	void set_obstacle(int x, int y, Obstacle* obstacle);
	void create_from_array(uint16_t map[], int size = LOCATION_BLOCKS_NUMBER);
	void save(const char* fname, uint16_t* map, int size = LOCATION_BLOCKS_NUMBER);
	void load(const char* fname);
private:
	sf::Texture background;

	sf::Texture tileset;
	sf::VertexArray vertices;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(sf::Sprite(background));

		states.transform *= getTransform();
		states.texture = &tileset;
		target.draw(vertices, states);
	}
};