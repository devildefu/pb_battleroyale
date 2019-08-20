#pragma once
#include <SFML/Graphics.hpp>

enum KilledType {
	NotKilled,
	Killed
};

class Player
{
public:
	Player();
	~Player();

	void set_x(float n) { position.x = n; }
	void set_y(float n) { position.y = n; }
	float get_x() { return position.x; }
	float get_y() { return position.y; }
	void set_vel_x(float n) { velocity.x = n; }
	void set_vel_y(float n) { velocity.y = n; }
	float get_vel_x() { return velocity.x; }
	float get_vel_y() { return velocity.y; }
	void apply_velocity(float x, float y) {
		velocity.x += x;
		velocity.y += y;
	}
	void apply_velocity(float x, float y, float limitX, float limitY);
	void apply_position(float x, float y) {
		position.x += x;
		position.y += y;
	}
	void set_velocity(float x, float y) {
		velocity.x = x;
		velocity.y = y;
	}
	void set_position(float x, float y) {
		position.x = x;
		position.y = y;
	}
	void kill() { killed = true; killed_type = NotKilled; }
	void set_killed(bool killed) { this->killed = killed; }
	bool is_killed() { return killed; }
	void set_killed_type(KilledType type) { killed_type = type; }
	KilledType get_killed_type() { return killed_type; }
	void hurt(float n);
	void set_hp(float n) { hp = n; }
	float get_hp() { return hp; }
	void set_turn(bool n) { turn = n; }
	bool get_turn() { return turn; }
	int get_jump_time() { return jump_time; }
	void set_jump_time(int n) { jump_time = n; }
	bool get_jump_can() { return jump_can; }
	void set_jump_can(bool n) { jump_can = n; }

	void update();
	void draw(sf::RenderWindow& window);
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	bool killed = false;
	KilledType killed_type = NotKilled;
	float hp = 0;
	bool turn = 0;
	int jump_time = 0;
	bool jump_can = true;

	sf::Sprite sprite;
	sf::Texture texture;
};