#pragma once

#include <SFML/Graphics.hpp>

#include <object.hpp>

enum KilledType {
	None,
	Normal,
	Drown,
};

class Player : public Object {
public:
	Player();
	~Player();

	void set_pos(sf::Vector2f vec) { pos = vec; }
	void apply_pos(sf::Vector2f vec) { pos += vec; }
	sf::Vector2f get_pos() { return pos; }

	void set_vel(sf::Vector2f vec) { vel = vec; }
	void apply_vel(sf::Vector2f vec) { vel += vec; }
	sf::Vector2f get_vel() { return vel; }

	void kill() { killed = true; }
	void set_killed(bool killed) { this->killed = killed; }
	bool is_killed() { return killed; }
	void set_killed_type(KilledType type) { killed_type = type; }
	KilledType get_killed_type() { return killed_type; }

	void set_hp(float n) { hp = n; }
	float get_hp() { return hp; }

	void set_turn(bool n) { turn = n; }
	bool get_turn() { return turn; }

	int get_jump_time() { return jump_time; }
	void set_jump_time(int n) { jump_time = n; }
	bool get_jump_can() { return jump_can; }
	void set_jump_can(bool n) { jump_can = n; }

	virtual void update();
	virtual void draw(sf::RenderWindow& window);

private:
	sf::Vector2f pos;
	sf::Vector2f vel;
	bool killed = false;
	KilledType killed_type;
	float hp = 0;
	bool turn = 0;
	int jump_time = 0;
	bool jump_can = true;
};