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
	void run();
	Game();
private:
	int index;
	bool inGame;
	bool state;

	Sprite victory, defeat, start;
	shared_ptr<Player> player_ptr;
    ifstream files;
	
	vector<string> allLevels;
	
	vector<shared_ptr<Entity>> allEntity;
	shared_ptr<Texture> end = make_shared<Texture>();
	shared_ptr<Texture> death = make_shared<Texture>();

	unique_ptr<RenderWindow> window;
	shared_ptr<Texture> allTextures = make_shared<Texture>();
	void loadTexture(shared_ptr<Texture> texture, string file);
	
	void collisionCheck(shared_ptr<Player> entity_1, vector<shared_ptr<Entity>> entity_2);
	void loadMap(string filename);
	void GameState();
	void Finish(bool gameStatus);

};