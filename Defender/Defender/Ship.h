#pragma once
#include "Bullet.h"

class Ship {

public:
	double posShipX;
	double posShipY;

	int direction; //0 -left 1-right

	bool alive;

	Ship();

	void drawShip();
	void specialKeyFunc(int key);
	void keyboardKeyFunc(unsigned char key);

	double getX();
	double getY();

};

extern Ship ship;

