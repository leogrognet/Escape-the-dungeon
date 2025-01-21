#include "Potion.h"

Potion::Potion(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y) : Entity(texture, start_x, start_y), player(player) 
{
}


void Potion::interact(shared_ptr<Player> player)
{
	player->speed = 50;
}

void Potion::draw(RenderWindow& window)
{
	window.draw(entitySprite);
}

void Potion::update(float deltaTime)
{
}
