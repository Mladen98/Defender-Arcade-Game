#pragma once

#pragma once

class Bullet {

public:
	double posBulletX;
	double posBulletY;

	double radius;
	double bulletSpeed;
	double distance;

	Bullet();
	Bullet(double radius, double bulletSpeed);

	void drawBullet();
	void moveBullet();

	bool outOfRange();
};

extern Bullet bullet;