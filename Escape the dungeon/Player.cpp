#include "Player.h"



Player::Player(float startSpeed, shared_ptr<Texture> texture, int posX, int posY) :  speed(startSpeed) {
	entitySprite.setTexture(*texture);
	entitySprite.setPosition(posX, posY);
	entitySprite.setScale(2, 2);

	pos_x = entitySprite.getPosition().x;
	pos_y = entitySprite.getPosition().y;
}


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

void Player::update(float deltaTime)
{
}

void Player::draw(RenderWindow& window)
{
	window.draw(entitySprite);
}

Sprite Player::getSprite()
{
	return entitySprite;
}
