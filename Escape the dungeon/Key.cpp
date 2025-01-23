#include "Key.h"

Key::Key(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y) : Entity(texture, start_x, start_y), player(player) 
{
	entitySprite.setTextureRect(IntRect(3, 7, 16, 16));
	entitySprite.setScale(2.5f, 2.5f);
}

void Key::interact(shared_ptr<Player> player)
{
	player->setGotKey(true);
}

void Key::update(float deltaTime)
{
}

void Key::draw(RenderWindow& window)
{
	window.draw(entitySprite);
}
