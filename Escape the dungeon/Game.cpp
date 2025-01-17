#include "Game.h"



Game::Game()
{
}

void Game::loadTexture(Texture* texture, string file)
{

		if (!texture->loadFromFile(file)) {
			cout << "La texture" << file << "n'a pas pu être chargée";
		}
	
}



void Game::run()
{
	
	loadTexture(&allTextures, "pngwing.png");
	Player player(2, allTextures,10,10);
	player.getSprite().setScale(1, 1);
	this->window = new RenderWindow(VideoMode(1200, 800), "Enter the Dungeon");
	while (window->isOpen()) {
		Event gameEvent;
		while (this->window->pollEvent(gameEvent)) {
			if (gameEvent.type == Event::Closed) {
				this->window->close();
			}
		}
		window->clear();

		cout << "Sprite position: ("
			<< player.getSprite().getPosition().x << ", "
			<< player.getSprite().getPosition().y << ") "
			<< " | Sprite size: ("
			<< player.getSprite().getTextureRect().width << " x "
			<< player.getSprite().getTextureRect().height << ")"
			<< endl;

		player.draw(*window);
		player.movePlayer();

		window->display();

	}

}



