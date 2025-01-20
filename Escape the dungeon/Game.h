#pragma once

#include "SFML/Graphics.hpp"
#include "PatrollingEnemy.h"
#include "ChaserEnemy.h"
#include <iostream>
#include <vector> 



using namespace std;
using namespace sf;

class Game {
public:
	Game();
	vector<shared_ptr<Entity>> allEntity;
	unique_ptr<RenderWindow> window;
	Texture allTextures;
	void loadTexture(Texture* texture, string file);
	void run();
	void collisionCheck(Sprite entity_1, vector<Entity*> entity_2);


};