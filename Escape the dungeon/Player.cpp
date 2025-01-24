#include "Player.h"



Player::Player(float startSpeed, shared_ptr<Texture> texture, float posX, float posY) : Entity(texture,posX,posY) {
	entitySprite.setTextureRect(IntRect(1*16,9*16, 16, 16));
	entitySprite.setScale(2.5f, 2.5f);
	speed = startSpeed;
	pos_x = entitySprite.getPosition().x;
	pos_y = entitySprite.getPosition().y;
	gotKey = false;
	canMove = true;
}


void Player::movePlayer() {

		if (Keyboard::isKeyPressed(Keyboard::Z)) {
			this->entitySprite.move(0, -speed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			this->entitySprite.move(0, speed);
		}
		if (Keyboard::isKeyPressed(Keyboard::Q)) {
			this->entitySprite.move(-speed, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			this->entitySprite.move(speed, 0);
		}
}

void Player::update(float deltaTime)
{

}

void Player::draw(RenderWindow& window)
{
	window.draw(entitySprite);
}

Sprite* Player::getSprite()
{
	return &entitySprite;
}

void Player::setGotKey(bool switching)
{
	this->gotKey = switching;
}

void Player::setCanMove(bool switching)
{
	this->canMove = switching;
}

bool Player::getGotKey()
{
	return this->gotKey;
}

