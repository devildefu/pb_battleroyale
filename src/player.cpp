#include <player.hpp>

Player::Player() {
}

Player::~Player() {
}

void Player::update() {
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(this->sprite);
	Object::draw(window);
}