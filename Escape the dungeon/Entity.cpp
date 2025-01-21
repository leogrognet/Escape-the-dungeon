#include "Entity.h"

Entity::Entity(shared_ptr<Texture> texture, float start_x, float start_y)
{
	this->entitySprite.setPosition(start_x, start_y);
	this->entitySprite.setTexture(*texture);
}

Sprite Entity::getSprite()
{
	return entitySprite;
}
