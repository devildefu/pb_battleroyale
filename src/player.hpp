#pragma once

#include <SFML/Graphics.hpp>

#include <object.hpp>

enum KilledType {
	NotKilled,
	Killed
};

class Player : public Object {
public:
	Player();
	~Player();

	void kill() { killed = true; }
	void set_killed(bool killed) { this->killed = killed; }
	bool is_killed() { return killed; }
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
	bool killed = false;
	float hp = 0;
	bool turn = 0;
	int jump_time = 0;
	bool jump_can = true;
};