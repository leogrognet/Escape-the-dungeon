#include "Enemy.h"



Enemy::Enemy(Player player) : player(&player) 
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
