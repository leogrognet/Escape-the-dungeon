#include "Enemy.h"


Enemy::Enemy(shared_ptr<Player> _player, shared_ptr<Texture> texture, float start_x, float start_y) : player(_player)
{
	this->entitySprite.setPosition(start_x, start_y);
	this->entitySprite.setTexture(*texture);
}


void Enemy::update(float deltaTime)
{
	moveEnemy();

}

void Enemy::draw(RenderWindow& window)
{
	window.draw(entitySprite);
}

Sprite Enemy::getSprite()
{
	return entitySprite;
}
