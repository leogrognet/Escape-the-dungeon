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
	loadTexture(allTextures, "ohmydungeon_v1.1.png");
	shared_ptr<Player> player_ptr = make_shared<Player>(2.f, allTextures, 100, 800);
	player_ptr->getSprite()->setScale(1, 1);
	loadMap("Niveau 1.txt", player_ptr);


	this->window = make_unique<RenderWindow>(VideoMode(1920, 1080), "Enter the Dungeon", Style::Fullscreen);
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
		collisionCheck(player_ptr, allEntity);

		window->display();

	}

}

void Game::collisionCheck(shared_ptr<Player> entity_1, vector<shared_ptr<Entity>> entity_2)
{
	for (auto allEntity : entity_2) {
		if (entity_1->getSprite()->getGlobalBounds().intersects(allEntity->getSprite().getGlobalBounds())) {
			if (auto enemy = dynamic_cast <Enemy*>(allEntity.get())){
				enemy->interact(entity_1);
			}
			else if (auto object = dynamic_cast<Key*>(allEntity.get())) {
				object->interact(entity_1);
			}
			else if (auto object = dynamic_cast<Potion*>(allEntity.get())) {
				object->interact(entity_1);
			}
			else if (auto object = dynamic_cast<Wall*>(allEntity.get())) {
				object->interact(entity_1);
				if (auto door = dynamic_cast<Door*>(allEntity.get())) {
					door->openDoor();
				}
			}
		}
		else {
			entity_1->setCanMove(true);
		}
	}
}


void Game::loadMap(string filename, shared_ptr<Player> player)
{
	ifstream file(filename);
	string line;
	int y = 0;
	while (getline(file, line)) {
		for (int x = 0; x < line.size(); ++x) {
			char tileType = line[x];
			if (tileType == '#') {
				//allEntity.push_back(make_shared<Wall>(player, allTextures, 40.f * x, 40.f * y));
			}
			else if (tileType == 'C') {
				//allEntity.push_back(make_shared<ChaserEnemy>(player, allTextures, 40.f*x, 40.f*y, 1.f));
			}
			else if (tileType == 'R') {
				//allEntity.push_back(make_shared<PatrollingEnemy>(player, allTextures, 40.f * x, 40.f * y, 1.f));
			}
			else if (tileType == 'P') {
				//allEntity.push_back(make_shared<Potion>(player, allTextures, 40.f * x, 40.f * y));
			}
			else if (tileType == 'K') {
				//allEntity.push_back(make_shared<Key>(player, allTextures, 40.f * x, 40.f * y));
			}
			else if (tileType == 'S') {
				//allEntity.push_back(make_shared<Door>(player, allTextures, 40.f * x, 40.f * y));
			}
		}
		++y;
	}
}

