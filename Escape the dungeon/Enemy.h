#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"



class Enemy : public Entity {
protected:
	unique_ptr<Player> player = make_unique<Player>();
	Enemy(Player player);
	int speed;
	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	virtual void moveEnemy() = 0;
};