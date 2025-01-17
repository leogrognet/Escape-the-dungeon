#pragma once
#include "SFML/Graphics.hpp"
#include <memory>


using namespace sf;
using namespace std;

class Entity {
protected:
	Sprite entitySprite;
	virtual void update(float deltaTime) = 0;
	virtual void draw(RenderWindow& window) = 0;
	Entity();
};








