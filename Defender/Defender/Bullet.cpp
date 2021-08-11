#include "Glut.h"
#include "Bullet.h"
#include <math.h>
#include "Ship.h"

#define PI 3.14159

Bullet::Bullet() {
	distance = 1000;
}

Bullet::Bullet(double r, double bs) {
	posBulletX = ship.posShipX;
	posBulletY = ship.posShipY + 6;
	radius = r;
	bulletSpeed = bs;
}

void Bullet::drawBullet() {

	glPushMatrix();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);

	double centerX, centerY, a;

	for (int i = 0; i < 20; i++) {
		a = 2 * PI * i / 20;
		centerX = posBulletX + radius * cos(a);
		centerY = posBulletY + radius * sin(a);
		glVertex2f(centerX, centerY);
	}

	glEnd();

	glPopMatrix();
}

void Bullet::moveBullet() {
	posBulletX += bulletSpeed;
}

bool Bullet::outOfRange() {
	return distance > 1000;
}