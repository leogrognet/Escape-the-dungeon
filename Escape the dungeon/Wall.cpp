#include "Wall.h"

Wall::Wall(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y) : Entity(texture, start_x, start_y), player(player)
{
    canCollide = true;
    entitySprite.setTextureRect(IntRect(1*16, 1*16, 16, 16));
    entitySprite.setScale(2.5f, 2.5f);
}

void Wall::interact(shared_ptr<Player> player)
{
    if (canCollide) {

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
    
}

void Wall::botCollides(shared_ptr<Entity> enemy) {
    if (enemy->entitySprite.getGlobalBounds().intersects(entitySprite.getGlobalBounds())) {
        if (auto chaser = dynamic_cast <ChaserEnemy*>(enemy.get())) {

            if (chaser->entitySprite.getGlobalBounds().top + chaser->entitySprite.getGlobalBounds().height > entitySprite.getGlobalBounds().top &&
                chaser->entitySprite.getGlobalBounds().top < entitySprite.getGlobalBounds().top + entitySprite.getGlobalBounds().height &&
                chaser->entitySprite.getGlobalBounds().left < entitySprite.getGlobalBounds().left + entitySprite.getGlobalBounds().width &&
                chaser->entitySprite.getGlobalBounds().left + chaser->entitySprite.getGlobalBounds().width > entitySprite.getGlobalBounds().left) {


                if (chaser->entitySprite.getPosition().y + chaser->entitySprite.getGlobalBounds().height > entitySprite.getGlobalBounds().top) {

                    chaser->entitySprite.move(0, -chaser->speed);
                }
            }


            if (chaser->entitySprite.getGlobalBounds().top < entitySprite.getGlobalBounds().top + entitySprite.getGlobalBounds().height &&
                chaser->entitySprite.getGlobalBounds().top + chaser->entitySprite.getGlobalBounds().height > entitySprite.getGlobalBounds().top &&
                chaser->entitySprite.getGlobalBounds().left < entitySprite.getGlobalBounds().left + entitySprite.getGlobalBounds().width &&
                chaser->entitySprite.getGlobalBounds().left + chaser->entitySprite.getGlobalBounds().width > entitySprite.getGlobalBounds().left) {

                if (chaser->entitySprite.getPosition().y < entitySprite.getGlobalBounds().top + entitySprite.getGlobalBounds().height) {

                    chaser->entitySprite.move(0, +chaser->speed);
                }
            }


            if (chaser->entitySprite.getGlobalBounds().left + chaser->entitySprite.getGlobalBounds().width > entitySprite.getGlobalBounds().left &&
                chaser->entitySprite.getGlobalBounds().left < entitySprite.getGlobalBounds().left + entitySprite.getGlobalBounds().width &&
                chaser->entitySprite.getGlobalBounds().top < entitySprite.getGlobalBounds().top + entitySprite.getGlobalBounds().height &&
                chaser->entitySprite.getGlobalBounds().top + chaser->entitySprite.getGlobalBounds().height > entitySprite.getGlobalBounds().top) {

                chaser->entitySprite.move(+chaser->speed, 0);
            }


            if (chaser->entitySprite.getGlobalBounds().left < entitySprite.getGlobalBounds().left + entitySprite.getGlobalBounds().width &&
                chaser->entitySprite.getGlobalBounds().left + chaser->entitySprite.getGlobalBounds().width > entitySprite.getGlobalBounds().left &&
                chaser->entitySprite.getGlobalBounds().top < entitySprite.getGlobalBounds().top + entitySprite.getGlobalBounds().height &&
                chaser->entitySprite.getGlobalBounds().top + chaser->entitySprite.getGlobalBounds().height > entitySprite.getGlobalBounds().top) {

                chaser->entitySprite.move(-chaser->speed, 0);
            }

        }

        if (auto patrol = dynamic_cast <PatrollingEnemy*>(enemy.get())) {

            patrol->speed = -patrol->speed;
        }
    }
    
}

void Wall::update(float deltaTime)
{
}

void Wall::draw(RenderWindow& window)
{
	window.draw(this->entitySprite);
}
