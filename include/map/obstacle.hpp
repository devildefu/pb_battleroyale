#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

/**
 * Note: code is from pbloader, so expect unnecessary things.
 */

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

class Obstacle {
private:
	int id = 0;

	bool collision = false;
	bool shadow = false;

	int x;
	int y;

public:
	Obstacle() {}

	/**
     *  Create obstacle from other obstacle
     */
	Obstacle(Obstacle& obstacle) {
		this->collision = collision;
		this->shadow = shadow;
		this->id = obstacle.get_id();
	}

	Obstacle(int id, bool collision = false, bool shadow = false) {

		this->collision = collision;
		this->shadow = shadow;
		this->id = id;
	}

	~Obstacle() {
		//delete sprite;
	}

	/**
     *  Return obstacle's id
     */
	inline int get_id() { return id; }

	/**
     *  Return obstacle's collision state
     */
	inline bool get_collision_state() { return collision; }

	/**
     *  Return obstacle's shadow state
     */
	inline bool get_shadow_state() { return shadow; }

	inline void set_position(const sf::Vector2f& pos) {
		x = pos.x;
		y = pos.y;
	}
	inline void set_position(int x, int y) {
		this->x = x;
		this->y = y;
	}

	inline sf::Vector2f get_position() {
		sf::Vector2f vec;
		vec.x = x;
		vec.y = y;
		return vec;
	}
};

#endif
