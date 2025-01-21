#include "Enemy.h"


Enemy::Enemy(shared_ptr<Player> _player, shared_ptr<Texture> texture, float start_x, float start_y) : player(_player) , Entity(texture , start_x, start_y)
{

}


void Enemy::update(float deltaTime)
{
	moveEnemy();

}

void Enemy::draw(RenderWindow& window)
{
	window.draw(entitySprite);
}

void Enemy::interact(shared_ptr<Player> Player)
{
}

Sprite Enemy::getSprite()
{
	return entitySprite;
}
