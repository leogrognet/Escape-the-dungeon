#pragma once

#include "SFML/Graphics.hpp"
#include "PatrollingEnemy.h"
#include <iostream>
#include <vector> 



using namespace std;
using namespace sf;

class Game {
public:
	Game();
	bool inGame;
	vector<shared_ptr<Enemy>> allEntity;
	unique_ptr<RenderWindow> window;
	shared_ptr<Texture> allTextures = make_shared<Texture>();
	void loadTexture(shared_ptr<Texture> texture, string file);
	void run();
	void collisionCheck(Sprite entity_1, vector<shared_ptr<Enemy>> entity_2);


};