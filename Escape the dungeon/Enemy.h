#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"



class Enemy : public Entity {
protected:
	shared_ptr<Player> player;
	int speed;
	
public:
	Enemy(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y);
	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;

	virtual void moveEnemy() = 0;
	Sprite getSprite();
};