#include "Wall.h"

Wall::Wall(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y) : Entity(texture, start_x, start_y), player(player)
{
    entitySprite.setTextureRect(IntRect(1, 1, 16, 16));
    entitySprite.setScale(2.5f, 2.5f);
}

void Wall::interact(shared_ptr<Player> player)
{

        if (Keyboard::isKeyPressed(Keyboard::Z)) {
            player->entitySprite.move(0, +player->speed);
        }
        else if (Keyboard::isKeyPressed(Keyboard::S)) {
            player->entitySprite.move(0, -player->speed);
        }
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
            player->getSprite()->move(+player->speed, 0);
        }
        else if (Keyboard::isKeyPressed(Keyboard::D)) {
            player->entitySprite.move(-player->speed, 0);
        }
    
}

void Wall::update(float deltaTime)
{
}

void Wall::draw(RenderWindow& window)
{
	window.draw(this->entitySprite);
}
