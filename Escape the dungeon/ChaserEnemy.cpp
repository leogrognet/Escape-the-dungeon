#include "ChaserEnemy.h"

ChaserEnemy::ChaserEnemy(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y, float speed) : Enemy(player, texture, start_x, start_y)
{
	deltaTexture = 3;
	entitySprite.setTextureRect(IntRect(deltaTexture * 16, 8 * 16, 16, 16));
	entitySprite.setScale(2.5f, 2.5f);
	this->speed = speed;
}

void ChaserEnemy::moveEnemy()
{
 
	Vector2f direction;
    Vector2f playerpos = Vector2f(this->player->getSprite()->getPosition().x + (player->getSprite()->getGlobalBounds().width / 2), player->getSprite()->getPosition().y + (player->getSprite()->getGlobalBounds().height / 2));
    Vector2f selfpos = this->entitySprite.getPosition();
    direction = playerpos - selfpos; 

    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0) {
		direction /= length; 
	}
	this->entitySprite.move(direction.x * speed ,  direction.y * speed);

}
void ChaserEnemy::updateAnim() {
	AnimTime = AnimClock.getElapsedTime();
	if (AnimTime.asMilliseconds() > 100) {
		deltaTexture++;
		cout << deltaTexture<<endl;
		AnimClock.restart();
	}

	if (deltaTexture * 16 >= 6*16) {
		deltaTexture = 3;
	}
	entitySprite.setTextureRect(IntRect(deltaTexture * 16, 8 * 16, 16, 16));
}