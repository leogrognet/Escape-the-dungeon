#include "Game.h"



Game::Game()
{
	inGame = true;
	index = 1;
	allLevels.push_back("Niveau 1.txt");
	allLevels.push_back("Niveau 2.txt");
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
	loadTexture(end, "Gagné.jpg");
	loadTexture(death, "vous etes mort.jpg");

	victory.setTexture(*end);
	victory.setScale(2,2);
	defeat.setTexture(*death);
	defeat.setScale(2, 2);

	loadMap(allLevels.at(0));

	this->window = make_unique<RenderWindow>(VideoMode(1920, 1080), "Enter the Dungeon", Style::Fullscreen);

	this->window->setFramerateLimit(60);
	while (window->isOpen()) {
		while (inGame) {
			Event gameEvent;
			while (this->window->pollEvent(gameEvent)) {
				if (gameEvent.type == Event::Closed) {
					this->window->close();
				}
			}


			window->clear();
			if (player_ptr != nullptr) {
				player_ptr->draw(*window);
				player_ptr->movePlayer();
				for (auto Entity : allEntity) {

					if (auto object = dynamic_cast<Wall*>(Entity.get())) {
						for (auto aliveEntity : allEntity) {
							object->botCollides(aliveEntity);
						}
					}
				}
				for (auto allEnemy : allEntity) {
					allEnemy->draw(*window);
					allEnemy->update(10);

				}
				collisionCheck(player_ptr, allEntity);
			}
			window->display();

		}
		window->clear();
		Finish(state);
		window->display();
	}

}

void Game::collisionCheck(shared_ptr<Player> entity_1, vector<shared_ptr<Entity>> entity_2)
{
	for (auto allEntities : entity_2) {
		if (entity_1->getSprite()->getGlobalBounds().intersects(allEntities->getSprite().getGlobalBounds())) {
			if (auto enemy = dynamic_cast <Enemy*>(allEntities.get())){
				enemy->interact(entity_1);
				if (enemy->hasTouched) {
					GameState();
					state = true;
				}
			}
			else if (auto object = dynamic_cast<Key*>(allEntities.get())) {
				object->interact(entity_1);
			}
			else if (auto object = dynamic_cast<Potion*>(allEntities.get())) {
				object->interact(entity_1);
			}
			else if (auto object = dynamic_cast<Wall*>(allEntities.get())) {
				object->interact(entity_1);
				if (auto door = dynamic_cast<Door*>(allEntities.get())) {
					door->canCollide = false;
					if (player_ptr->getGotKey() && index < allLevels.size()) {
						allEntity.clear();
						player_ptr.reset();
						loadMap(allLevels.at(index));
						index++;
						player_ptr->setGotKey(false);
					}
					else if (player_ptr->getGotKey() && index >= allLevels.size()) {
						GameState();
						state = false;
					}
				}
			}
		}
	}
}


void Game::loadMap(string filename)
{
	ifstream file(filename);
	ifstream file2(filename);
	string line;
	string line2;
	int y = 0;
	while (getline(file, line)) {
		for (int x = 0; x < line.size(); ++x) {
			char tileType = line[x];
			if (tileType == 'J') {
				player_ptr = make_shared<Player>(2.f, allTextures, 40.f * x, 40.f * y);
				break;

			}
		}
		y++;
	}
	y = 0;
	while (getline(file2, line2)) {
		for (int x = 0; x < line2.size(); ++x) {
			char tileType = line2[x];
			if (tileType == '#') {
				allEntity.push_back(make_shared<Wall>(player_ptr, allTextures, 40.f * x, 40.f * y));
			}
			else if (tileType == 'C') {
				allEntity.push_back(make_shared<ChaserEnemy>(player_ptr, allTextures, 40.f*x, 40.f*y, 1.f));
			}
			else if (tileType == 'R') {
				allEntity.push_back(make_shared<PatrollingEnemy>(player_ptr, allTextures, 40.f * x, 40.f * y, 1.f));
			}
			else if (tileType == 'P') {
				allEntity.push_back(make_shared<Potion>(player_ptr, allTextures, 40.f * x, 40.f * y));
			}
			else if (tileType == 'K') {
				allEntity.push_back(make_shared<Key>(player_ptr, allTextures, 40.f * x, 40.f * y));
			}
			else if (tileType == 'S') {
				allEntity.push_back(make_shared<Door>(player_ptr, allTextures, 40.f * x, 40.f * y));
			}
		}
		++y;
	}
}



void Game::GameState() {
		allEntity.clear();
		player_ptr.reset();
		inGame = false;
}

void Game::Finish(bool gameStatus) {
	if (!gameStatus) {
		window->draw(victory);
	}
	if (gameStatus) {
		window->draw(defeat);
	}
}