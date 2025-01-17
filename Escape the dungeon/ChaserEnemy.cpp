#include "ChaserEnemy.h"

void ChaserEnemy::moveEnemy(int posX, int posY)
{
	if (entitySprite.getPosition().x > posX) {
		this->entitySprite.move(-this->speed, 0);
	}
	else if (entitySprite.getPosition().x < posX) {
		this->entitySprite.move(+this->speed, 0);
	}
	if (entitySprite.getPosition().y > posY) {
		this->entitySprite.move(0, -this->speed);
	}
	else if (entitySprite.getPosition().y < posY) {
		this->entitySprite.move(0, +this->speed);
	}
}
