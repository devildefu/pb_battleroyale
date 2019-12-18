#pragma once

/**
 * Note: code is from pbloader, so expect unnecessary things.
 */

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

class Obstacle {
private:
	uint16_t id = 0;

	bool collision = false;
	bool shadow = false;

	sf::IntRect rect;
public:
	Obstacle() {}

	/**
     *  Create obstacle from other obstacle
     */
	Obstacle(Obstacle& obstacle) {
		this->collision = collision;
		this->shadow = shadow;
		this->id = obstacle.get_id();
		this->rect = obstacle.get_rect();
	}

	Obstacle(uint16_t id, bool collision, bool shadow, sf::IntRect rect) {
		this->collision = collision;
		this->shadow = shadow;
		this->id = id;
		this->rect = rect;
	}

	~Obstacle() {
		//delete sprite;
	}

	/**
     *  Return obstacle's id
     */
	inline uint16_t get_id() { return id; }

	/**
     *  Return obstacle's collision state
     */
	inline bool get_collision_state() { return collision; }

	/**
     *  Return obstacle's shadow state
     */
	inline bool get_shadow_state() { return shadow; }

	inline void set_rect(sf::IntRect& rect) {
		this->rect = rect;
	}

	inline sf::IntRect get_rect() {
		return rect;
	}
};
