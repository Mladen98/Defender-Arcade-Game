#pragma once

#include "Enemy.h"
#include "Legend.h"
#include "Bullet.h"

class Pool {

public:
	int level;

	bool gameOver;
	bool startGame;

	Legend* legend;

	Pool(Legend* legend);

	void drawEnemies();
	void moveEnemies();
	void generateNextLevel(int level);
	void BulletCollisionHandler(Bullet* bullet, Enemy* e, Enemy* e1, Enemy* e2);
	void shipCollisionHandler(Ship* ship, Enemy* e, Enemy* e1, Enemy* e2);

	bool allClear(Enemy* e, Enemy* e1, Enemy* e2);

};