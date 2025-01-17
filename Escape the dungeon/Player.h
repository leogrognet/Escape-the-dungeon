#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"



class Player : public Entity {
protected:
	int	pos_x = this->entitySprite.getPosition().x, pos_y = this->entitySprite.getPosition().y;
	float speed;
public:

	Player(float startSpeed, Texture texture, int posX, int posY);


	void movePlayer();
	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	Sprite getSprite();
};