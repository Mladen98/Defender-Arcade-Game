#pragma once

#include "Ship.h"
#include "Bullet.h"

class Enemy {

public:
	double enemyPosX;
	double enemyPosY;
	double radius;
	int direction;

	double speed;
	bool alive;

	Enemy();
	Enemy(double PosX, double PosY, double r, double speed);


	void drawEnemy();
	void drawEnemy1();
	void drawEnemy2();

	void moveEnemy();
	void moveEnemy1();
	void moveEnemy2();

	bool isAlive();
	bool bulletCollision(Bullet bullet);
	bool bulletCollision1(Bullet bullet);
	bool bulletCollision2(Bullet bullet);

	bool shipCollision(Ship ship);
	bool shipCollision1(Ship ship);
	bool shipCollision2(Ship ship);

};

extern Enemy enemy;
extern Enemy enemy1;
extern Enemy enemy2;