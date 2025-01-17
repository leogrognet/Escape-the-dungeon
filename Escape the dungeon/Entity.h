#pragma once

#include "SFML/Graphics.hpp"



using namespace sf;

class Entity {
protected:
	Sprite entitySprite;
	virtual void update(float deltaTime) = 0;
	virtual void draw(RenderWindow& window) = 0;
	Entity();
};








