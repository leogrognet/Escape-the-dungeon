#include "Game.h"



Game::Game()
{
}

void Game::loadTexture(shared_ptr<Texture> texture, string file)
{

		if (!texture->loadFromFile(file)) {
			cout << "La texture" << file << "n'a pas pu être chargée";
		}
	
}



void Game::run()
{
	inGame = true;
	loadTexture(allTextures, "pngwing.png");
	shared_ptr<Player> player_ptr = make_shared<Player>(2.f, allTextures, 800, 700);
	player_ptr->getSprite().setScale(10, 10);
	allEntity.push_back(make_shared<ChaserEnemy>(player_ptr, allTextures, 20.f, 20.f, 1.f));
	allEntity.push_back(make_shared<PatrollingEnemy>(player_ptr, allTextures, 20.f, 20.f, 1.f));

	this->window = make_unique<RenderWindow>(VideoMode(1200, 800), "Enter the Dungeon");
	this->window->setFramerateLimit(60);
	while (inGame) {
		Event gameEvent;
		while (this->window->pollEvent(gameEvent)) {
			if (gameEvent.type == Event::Closed) {
				this->window->close();
			}
		}
		window->clear();


		player_ptr->draw(*window);
		player_ptr->movePlayer();
		for (auto allEnemy : allEntity) {
			allEnemy->draw(*window);
			allEnemy->update(10);
		}
		collisionCheck(player_ptr->getSprite(), allEntity);

		window->display();

	}

}

void Game::collisionCheck(Sprite entity_1, vector<shared_ptr<Enemy>> entity_2)
{
	for (auto allEntity : entity_2) {
		if (entity_1.getGlobalBounds().intersects(allEntity->getSprite().getGlobalBounds())) {
			cout << "Game Over";
			inGame = false;
		}
	}
}



