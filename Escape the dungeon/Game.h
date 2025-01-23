#pragma once

#include "SFML/Graphics.hpp"
#include "PatrollingEnemy.h"
#include "Potion.h"
#include "Door.h"
#include <iostream>
#include <vector> 
#include <fstream>
#include <sstream>


using namespace std;
using namespace sf;

class Game {
public:
	shared_ptr<Player> player_ptr;
    ifstream files;
	Game();
	bool inGame;
	vector<shared_ptr<Entity>> allEntity;
	unique_ptr<RenderWindow> window;
	shared_ptr<Texture> allTextures = make_shared<Texture>();
	void loadTexture(shared_ptr<Texture> texture, string file);
	void run();
	void collisionCheck(shared_ptr<Player> entity_1, vector<shared_ptr<Entity>> entity_2);
	void loadMap(string filename, shared_ptr<Player> player);
};