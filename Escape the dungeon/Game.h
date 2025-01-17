#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Player.h"
#include <iostream>
#include <vector> 



using namespace std;
using namespace sf;

class Game {
public:
	Game();


	RenderWindow* window;
	Texture allTextures;
	void loadTexture(Texture* texture, string file);
	void run();


};