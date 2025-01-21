#pragma once
#include "InteractInterface.h"

class Key : public Interact, public Entity {
public:
	shared_ptr<Player> player;
	Key(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y);
	void interact(shared_ptr<Player> player);
	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
};