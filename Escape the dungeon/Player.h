#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"



class Player : public Entity {
protected:
	int	pos_x = this->entitySprite.getPosition().x, pos_y = this->entitySprite.getPosition().y;
	bool gotKey;
public:
	float speed;
	Player(float startSpeed, shared_ptr<Texture> texture, float posX, float posY);
	//Player();

	void movePlayer();
	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	Sprite getSprite();
	void setGotKey(bool switching);
	bool getGotKey();
};