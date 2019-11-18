#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

#include "obstacle.hpp"
#include <spdlog/spdlog.h>

#include <managers/obstaclemanager.hpp>

#define MAP_WIDTH 32
#define MAP_HEIGHT 18

class Location : public sf::Drawable, public sf::Transformable {
public:
	Location();
	Location(sf::Texture& background, sf::Texture& tileset);
	Location(sf::Texture& background, sf::Texture& tileset, uint16_t map[], int size = 576);

	void set_obstacle(int x, int y, Obstacle* obstacle);
	void create_from_array(uint16_t map[], int size = 576);
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