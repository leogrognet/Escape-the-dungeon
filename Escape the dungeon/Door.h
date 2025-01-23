#pragma once
#include "SFML/Graphics.hpp"
#include "Wall.h"

class Door : public Wall {
public:
	Door(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y);
	void openDoor();

};