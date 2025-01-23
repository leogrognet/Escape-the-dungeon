#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "InteractInterface.h"
#include <iostream>
class Wall : public Entity, public Interact {
public:
	shared_ptr<Player> player;
	Wall(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y);
	void interact(shared_ptr<Player> player) override;
	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
};
