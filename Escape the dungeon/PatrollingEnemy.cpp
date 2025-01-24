#include "PatrollingEnemy.h"


PatrollingEnemy::PatrollingEnemy(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y, float speed) : Enemy(player, texture, start_x, start_y)
{
	entitySprite.setTextureRect(IntRect(3*16, 9*16, 16, 16));
	entitySprite.setScale(2.5f, 2.5f);
	this->speed = speed;
}

void PatrollingEnemy::moveEnemy()
{
	this->entitySprite.move(speed, 0);
}

void PatrollingEnemy::updateAnim()
{
}
