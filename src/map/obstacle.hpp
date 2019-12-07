#pragma once

/**
 * Note: code is from pbloader, so expect unnecessary things.
 */

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

using Vector2c = sf::Vector2<uint8_t>;

class Obstacle {
private:
	uint16_t id = 0;

	bool collision = false;
	bool shadow = false;

	Vector2c pos;
	Vector2c size;
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

	Obstacle(uint16_t id, bool collision = false, bool shadow = false) {

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
	inline uint16_t get_id() { return id; }

	/**
     *  Return obstacle's collision state
     */
	inline bool get_collision_state() { return collision; }

	/**
     *  Return obstacle's shadow state
     */
	inline bool get_shadow_state() { return shadow; }

	inline void set_position(const Vector2c& pos) {
		this->pos.x = pos.x;
		this->pos.y = pos.y;
	}
	inline void set_position(int x, int y) {
		this->pos.x = x;
		this->pos.y = y;
	}

	inline Vector2c get_position() {
		Vector2c vec;
		vec.x = this->pos.x;
		vec.y = this->pos.y;
		return vec;
	}
};
