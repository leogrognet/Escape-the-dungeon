#include "ChaserEnemy.h"

void ChaserEnemy::moveEnemy()
{
	if (entitySprite.getPosition().x > player->getSprite().getPosition().x) {
		this->entitySprite.move(-this->speed, 0);
	}
	else if (entitySprite.getPosition().x < player->getSprite().getPosition().x) {
		this->entitySprite.move(+this->speed, 0);
	}
	if (entitySprite.getPosition().y > player->getSprite().getPosition().y) {
		this->entitySprite.move(0, -this->speed);
	}
	else if (entitySprite.getPosition().y < player->getSprite().getPosition().y) {
		this->entitySprite.move(0, +this->speed);
	}
}
