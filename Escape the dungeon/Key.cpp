#include "Key.h"

Key::Key(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y) : Entity(texture, start_x, start_y), player(player) {}

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
