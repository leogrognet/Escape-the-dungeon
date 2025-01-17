#pragma once
#include "Enemy.h"

class PatrollingEnemy : public Enemy {
	void moveEnemy(int posX, int posY) override;
};
