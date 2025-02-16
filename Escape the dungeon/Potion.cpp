#include "Potion.h"

Potion::Potion(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y) : Entity(texture, start_x, start_y), player(player) 
{
	test = IntRect(3, 10, 16, 16);
	entitySprite.setTextureRect(IntRect(3*16, 10*16, 16, 16));
	entitySprite.setScale(2.5f, 2.5f);
}


void Potion::interact(shared_ptr<Player> player)
{
	player->speed = player->speed * 1.1;
	entitySprite.setTextureRect(IntRect(1 * 16, 10 * 16, 16, 16));
}

void Potion::draw(RenderWindow& window)
{
	window.draw(entitySprite);
}

void Potion::update(float deltaTime)
{
}
