#pragma once
#include "ChaserEnemy.h"

class PatrollingEnemy : public Enemy {
public:
	PatrollingEnemy(shared_ptr<Player> player, shared_ptr<Texture> texture, float start_x, float start_y, float speed);
	void moveEnemy() override;
	void updateAnim() override;
};
