#include "Enemy.h"


Enemy::Enemy(shared_ptr<Player> _player, shared_ptr<Texture> texture, float start_x, float start_y) : player(_player) , Entity(texture , start_x, start_y)
{
	hasTouched = false;
}


void Enemy::update(float deltaTime)
{
	moveEnemy();
	updateAnim();

}




void Enemy::draw(RenderWindow& window)
{
	window.draw(entitySprite);
}

void Enemy::interact(shared_ptr<Player> Player)
{
	hasTouched = true;
}

Sprite Enemy::getSprite()
{
	return entitySprite;
}
