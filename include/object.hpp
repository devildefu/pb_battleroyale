#pragma once

#include <SFML/Graphics.hpp>

class Object {
public:
	Object() { }
	~Object() { }

	virtual void set_x(float n) { position.x = n; }
	virtual void set_y(float n) { position.y = n; }
	virtual float get_x() { return position.x; }
	virtual float get_y() { return position.y; }
	virtual void set_vel_x(float n) { velocity.x = n; }
	virtual void set_vel_y(float n) { velocity.y = n; }
	virtual float get_vel_x() { return velocity.x; }
	virtual float get_vel_y() { return velocity.y; }
	virtual void apply_velocity(float x, float y) {
		velocity.x += x;
		velocity.y += y;
	}
	virtual void apply_velocity(float x, float y, float limitX, float limitY) = 0;
	virtual void apply_position(float x, float y) {
		position.x += x;
		position.y += y;
	}
	virtual void set_velocity(float x, float y) {
		velocity.x = x;
		velocity.y = y;
	}
	virtual void set_position(float x, float y) {
		position.x = x;
		position.y = y;
	}

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
protected:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Sprite sprite;
	sf::Texture texture;
};