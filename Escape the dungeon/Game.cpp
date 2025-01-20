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
	allEntity.push_back(make_shared<PatrollingEnemy>());
	allEntity.push_back(make_shared<PatrollingEnemy>());

	this->window = make_unique<RenderWindow>(VideoMode(1200, 800), "Enter the Dungeon");
	while (window->isOpen()) {
		Event gameEvent;
		while (this->window->pollEvent(gameEvent)) {
			if (gameEvent.type == Event::Closed) {
				this->window->close();
			}
		}
		window->clear();

		/*cout << "Sprite position: ("
			<< player.getSprite().getPosition().x << ", "
			<< player.getSprite().getPosition().y << ") "
			<< " | Sprite size: ("
			<< player.getSprite().getTextureRect().width << " x "
			<< player.getSprite().getTextureRect().height << ")"
			<< endl;*/

		player.draw(*window);
		player.movePlayer();

		window->display();

	}

}

void Game::collisionCheck(Sprite entity_1, vector<Entity*> entity_2)
{
	for (auto allEntity : entity_2) {
		if (entity_1.getGlobalBounds().intersects(allEntity->entitySprite.getGlobalBounds())) {
			cout << "Touché"<<endl;
		}
	}
}



