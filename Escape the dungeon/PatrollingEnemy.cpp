#include "PatrollingEnemy.h"

void PatrollingEnemy::moveEnemy()
{
	if (this->entitySprite.getPosition().x < 20) {
		this->speed = -speed;
	}
	else if (this->entitySprite.getPosition().x > 100) {
		this->speed = -speed;
	}
}
