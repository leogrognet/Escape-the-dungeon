#include "PatrollingEnemy.h"


PatrollingEnemy::PatrollingEnemy(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y, float speed) : Enemy(player, texture, start_x, start_y)
{
	this->speed = speed;
}

void PatrollingEnemy::moveEnemy()
{
	this->entitySprite.move(speed, 0);
	if (this->entitySprite.getPosition().x < 20) {
		speed = -speed;
	}
	else if (this->entitySprite.getPosition().x > 1000) {
		speed = -speed;
	}
}
