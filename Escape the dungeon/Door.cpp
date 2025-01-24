#include "Door.h"

Door::Door(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y) : Wall(player,texture,start_x,start_y)
{
	entitySprite.setTextureRect(IntRect(2*16, 1*16, 16, 16));
	entitySprite.setScale(2.5f, 2.5f);
}

void Door::openDoor()
{
	if (player->getGotKey()) {
		cout << "victoire";
	}
}
