#pragma once
#include "SFML/Graphics.hpp"
#include "InteractInterface.h"
#include <iostream>



class Enemy : public Entity, public Interact {
protected:
	shared_ptr<Player> player;
	int speed;
	
public:
	Enemy(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y);
	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	void interact(shared_ptr<Player> Player) override;

	virtual void moveEnemy() = 0;
	Sprite getSprite();
};