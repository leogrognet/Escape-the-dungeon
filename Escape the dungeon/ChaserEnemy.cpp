#include "ChaserEnemy.h"

ChaserEnemy::ChaserEnemy(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y, float speed) : Enemy(player, texture, start_x, start_y)
{
	this->speed = speed;
}

void ChaserEnemy::moveEnemy()
{
 
	Vector2f direction;
    Vector2f playerpos = Vector2f(this->player->getSprite().getPosition().x + (player->getSprite().getGlobalBounds().width / 2), player->getSprite().getPosition().y + (player->getSprite().getGlobalBounds().height / 2));
    Vector2f selfpos = this->entitySprite.getPosition();
    direction = playerpos - selfpos; 

    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0) {
		direction /= length; 
	}
   
	this->entitySprite.move(direction.x * speed ,  direction.y * speed);

}
