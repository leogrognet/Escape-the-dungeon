#pragma once
#include "Key.h"

class Potion : public Interact, public Entity{
public:
	shared_ptr<Player> player;

	Potion(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y);
	void interact(shared_ptr<Player> player) override;
	void draw(RenderWindow& window) override;
	void update(float deltaTime) override;
};