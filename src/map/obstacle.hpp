#pragma once

/**
 * Note: code is from pbloader, so expect unnecessary things.
 */

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

enum ObstacleState {
	HasCollision,
	HasShadow
};

class Obstacle {
public:
	Obstacle() {}

	/**
     *  Create obstacle from other obstacle
     */
	Obstacle(Obstacle& obstacle) {
		this->state = obstacle.get_state();
		this->id = obstacle.get_id();
		this->rect = obstacle.get_rect();
	}

	Obstacle(uint16_t id, sf::IntRect rect, int state) {
		this->state = state;
		this->id = id;
		this->rect = rect;
	}

	inline uint16_t get_id() { return id; }
	inline sf::IntRect get_rect() { return rect; }
	inline int get_state() { return state; }

	inline void set_rect(sf::IntRect& rect) { this->rect = rect; }
private:
	uint16_t id = 0;
	int state;
	sf::IntRect rect;
};
