#include "Player.h"

void Player::createPlayer(std::string n, int s, int h)
{
	name = n;
	sunlight = s;
	health = h;
}


void Player::setName(std::string n) {
	name = n;
}

std::string Player::getName() {
	return name;
}

void Player::setSunlight(int s) {
	sunlight = s;
}

void Player::updateSunlight(int us) {
	sunlight += us;
}

int Player::getSunlight() {
	return sunlight;
}

void Player::setHealth(int h) {
	health = h;
}

int Player::getHealth() {
	return health;
}

void Player::killPlayer() {
	isAlive = false;
}

bool Player::getStatus() {
	return isAlive;
}