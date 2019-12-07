#pragma once

#include <algorithm>
#include <iterator>
#include <vector>
#include <cstdio>

#include "obstacle.hpp"
#include <spdlog/spdlog.h>

#include <managers/obstaclemanager.hpp>

#define MAP_WIDTH 32
#define MAP_HEIGHT 18
#define MAP_BLOCKS_NUMBER MAP_WIDTH*MAP_HEIGHT

class Location : public sf::Drawable, public sf::Transformable {
public:
	Location();
	Location(sf::Texture& background, sf::Texture& tileset);
	Location(sf::Texture& background, sf::Texture& tileset, uint16_t map[], int size = MAP_BLOCKS_NUMBER);
	Location(sf::Texture& background, sf::Texture& tileset, const char* fname);

	void set_obstacle(int x, int y, Obstacle* obstacle);
	void create_from_array(uint16_t map[], int size = MAP_BLOCKS_NUMBER);
	void save(const char* fname, uint16_t* map, int size = MAP_BLOCKS_NUMBER);
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