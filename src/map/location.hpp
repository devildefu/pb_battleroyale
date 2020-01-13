#pragma once

#include <algorithm>
#include <cstdio>
#include <iterator>
#include <vector>

#include "obstacle.hpp"
#include <spdlog/spdlog.h>

#include <managers/obstaclemanager.hpp>

constexpr uint8_t LOCATION_WIDTH = 32;
constexpr uint8_t LOCATION_HEIGHT = 18;
constexpr uint32_t LOCATION_BLOCKS_NUMBER = LOCATION_WIDTH * LOCATION_HEIGHT;
constexpr int OBSTACLE_SCALE = 10;

class Location : public sf::Drawable, public sf::Transformable {
public:
	Location(Location& loc);
	Location(sf::Texture& background, sf::Texture& tileset);
	Location(sf::Texture& background, sf::Texture& tileset, uint16_t map[], int size = LOCATION_BLOCKS_NUMBER);
	Location(sf::Texture& background, sf::Texture& tileset, const char* fname);

	Obstacle* get_obstacle(int x, int y);
	uint16_t get_obstacle_id(int x, int y);
	void set_obstacle(int x, int y, Obstacle* current_obstacle);
	void set_obstacle(int x, int y, uint16_t id);
	void create_from_array(uint16_t map[], int size = LOCATION_BLOCKS_NUMBER);
	void save(const char* fname, uint16_t* map, int size = LOCATION_BLOCKS_NUMBER);
	void load(const char* fname);

	void setScale(float factorX, float factorY) {
		sf::Transformable::setScale(factorX, factorY);
		background.setScale(factorX, factorY);
	}

	void setPosition(float x, float y) {
		sf::Transformable::setPosition(x, y);
		background.setPosition(x, y);
	}
private:
	sf::Texture bg;
	sf::Sprite background;

	sf::Texture tileset;
	sf::VertexArray vertices;
	uint16_t id[LOCATION_BLOCKS_NUMBER];

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(background);

		states.transform *= getTransform();
		states.texture = &tileset;
		target.draw(vertices, states);
	}

	void init() {
		vertices.setPrimitiveType(sf::Quads);
		vertices.resize(LOCATION_WIDTH * LOCATION_HEIGHT * 4);

		background.setTexture(bg);
		std::fill(id, id+LOCATION_BLOCKS_NUMBER, 0);
	}
};