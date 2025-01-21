#pragma once
#include "SFML/Graphics.hpp"
#include <memory>


using namespace sf;
using namespace std;

class Entity {
public:
	Sprite entitySprite;
	virtual void update(float deltaTime) = 0;
	virtual void draw(RenderWindow& window) = 0;
	Entity(shared_ptr<Texture> texture, float start_x, float start_y);
	Sprite getSprite();
};








