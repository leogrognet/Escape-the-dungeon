#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"


class Interact {
protected:
	virtual void interact(shared_ptr<Player> Player) = 0;
	virtual ~Interact() {};
};