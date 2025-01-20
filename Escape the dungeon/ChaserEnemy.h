#pragma once
#include "Enemy.h"
#include "math.h"

class ChaserEnemy : public Enemy {
public:
	ChaserEnemy(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y, float speed);
	void moveEnemy() override;
};
