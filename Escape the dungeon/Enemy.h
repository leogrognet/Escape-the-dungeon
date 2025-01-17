#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"

class Enemy : public Entity {
protected:
	int speed;
	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	virtual void moveEnemy(int posX, int posY) = 0;
};