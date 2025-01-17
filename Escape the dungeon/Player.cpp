#include "Player.h"



Player::Player(float startSpeed, Texture texture, int posX, int posY) : speed(startSpeed) {
	entitySprite.setTexture(texture);
	entitySprite.setPosition(posX, posY);
};

void Player::movePlayer() {

	if (Keyboard::isKeyPressed(Keyboard::Z)) {
		this->entitySprite.move(0, -5);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		this->entitySprite.move(0, 5);
	}
	if (Keyboard::isKeyPressed(Keyboard::Q)) {
		this->entitySprite.move(-5, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		this->entitySprite.move(5, 0);
	}
}