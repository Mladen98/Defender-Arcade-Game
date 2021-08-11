#include "Enemy.h"
#include "Glut.h"
#include <math.h>


#define PI 3.14159

Enemy::Enemy() {
	alive = false;
}

Enemy::Enemy(double PosX, double PosY, double r, double s) {

	enemyPosX = PosX;
	enemyPosY = PosY;
	radius = r;
	speed = s;
	alive = true;
	direction = 1;
}

void Enemy::drawEnemy() {

	glLoadIdentity();
	glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	double x, y, angle;

	for (int i = 0; i < 20; i++) {
		angle = 2.0 * PI * i / 20;
		x = enemyPosX + radius * cos(angle);
		y = enemyPosY + radius * sin(angle);
		glVertex2f(x, y);
	}

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2f(enemyPosX - 2, enemyPosY);
	glVertex2f(enemyPosX + 2, enemyPosY);
	glVertex2f(enemyPosX + 2, enemyPosY - 10);
	glVertex2f(enemyPosX - 2, enemyPosY - 10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2f(enemyPosX - 4, enemyPosY);
	glVertex2f(enemyPosX - 6, enemyPosY);
	glVertex2f(enemyPosX - 6, enemyPosY - 10);
	glVertex2f(enemyPosX - 10, enemyPosY - 10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2f(enemyPosX + 4, enemyPosY);
	glVertex2f(enemyPosX + 6, enemyPosY);
	glVertex2f(enemyPosX + 6, enemyPosY - 10);
	glVertex2f(enemyPosX + 10, enemyPosY - 10);
	glEnd();

	glPopMatrix();

}

void Enemy::drawEnemy1() {

	glLoadIdentity();
	glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	double x, y, angle;

	for (int i = 0; i < 20; i++) {
		angle = 2.0 * PI * i / 20;
		x = enemyPosX + radius * cos(angle);
		y = enemyPosY + radius * sin(angle);
		glVertex2f(x, y);
	}

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2f(enemyPosX - 2, enemyPosY);
	glVertex2f(enemyPosX + 2, enemyPosY);
	glVertex2f(enemyPosX + 2, enemyPosY - 10);
	glVertex2f(enemyPosX - 2, enemyPosY - 10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2f(enemyPosX - 4, enemyPosY);
	glVertex2f(enemyPosX - 6, enemyPosY);
	glVertex2f(enemyPosX - 6, enemyPosY - 10);
	glVertex2f(enemyPosX - 10, enemyPosY - 10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2f(enemyPosX + 4, enemyPosY);
	glVertex2f(enemyPosX + 6, enemyPosY);
	glVertex2f(enemyPosX + 6, enemyPosY - 10);
	glVertex2f(enemyPosX + 10, enemyPosY - 10);
	glEnd();

	glPopMatrix();

}

void Enemy::drawEnemy2() {

	glLoadIdentity();
	glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	double x, y, angle;

	for (int i = 0; i < 20; i++) {
		angle = 2.0 * PI * i / 20;
		x = enemyPosX + radius * cos(angle);
		y = enemyPosY + radius * sin(angle);
		glVertex2f(x, y);
	}

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(enemyPosX - 2, enemyPosY);
	glVertex2f(enemyPosX + 2, enemyPosY);
	glVertex2f(enemyPosX + 2, enemyPosY - 10);
	glVertex2f(enemyPosX - 2, enemyPosY - 10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(enemyPosX - 4, enemyPosY);
	glVertex2f(enemyPosX - 6, enemyPosY);
	glVertex2f(enemyPosX - 6, enemyPosY - 10);
	glVertex2f(enemyPosX - 10, enemyPosY - 10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(enemyPosX + 4, enemyPosY);
	glVertex2f(enemyPosX + 6, enemyPosY);
	glVertex2f(enemyPosX + 6, enemyPosY - 10);
	glVertex2f(enemyPosX + 10, enemyPosY - 10);
	glEnd();

	glPopMatrix();

}

void Enemy::moveEnemy() {

	if (direction == 1) {
		enemy.enemyPosX += speed * cos(0);
	}

	else if (direction == 0) {
		enemy.enemyPosX -= speed * cos(0);
	}

	if (enemyPosX + radius >= 800) {
		direction = 0;
	}

	else if (enemyPosX - radius <= 0) {
		direction = 1;
	}
}

void Enemy::moveEnemy1() {

	if (direction == 1) {
		enemy1.enemyPosX += speed * cos(0);
	}

	else if (direction == 0) {
		enemy1.enemyPosX -= speed * cos(0);
	}

	if (enemyPosX + radius >= 800) {
		direction = 0;
	}

	else if (enemyPosX - radius <= 0) {
		direction = 1;
	}
}

void Enemy::moveEnemy2() {

	if (direction == 1) {
		enemy2.enemyPosX += speed * cos(0);
	}

	else if (direction == 0) {
		enemy2.enemyPosX -= speed * cos(0);
	}

	if (enemyPosX + radius >= 800) {
		direction = 0;
	}

	else if (enemyPosX - radius <= 0) {
		direction = 1;
	}
}

bool Enemy::isAlive() {
	return alive;
}

bool collision(double x1, double y1, double r1, double x2, double y2, double r2) {

	double d = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return d <= r1 + r2;
}


bool Enemy::bulletCollision(Bullet bullet) {
	return collision(bullet.posBulletX, bullet.posBulletY, bullet.radius,
		enemy.enemyPosX, enemy.enemyPosY, enemy.radius);
}

bool Enemy::bulletCollision1(Bullet bullet) {
	return collision(bullet.posBulletX, bullet.posBulletY, bullet.radius,
		enemy1.enemyPosX, enemy1.enemyPosY, enemy1.radius);
}

bool Enemy::bulletCollision2(Bullet bullet) {
	return collision(bullet.posBulletX, bullet.posBulletY, bullet.radius,
		enemy2.enemyPosX, enemy2.enemyPosY, enemy2.radius);
}

bool Enemy::shipCollision(Ship ship) {
	return collision(ship.posShipX, ship.posShipY, 8, enemy.enemyPosX, enemy.enemyPosY, enemy.radius);
}

bool Enemy::shipCollision1(Ship ship) {
	return collision(ship.posShipX, ship.posShipY, 8, enemy1.enemyPosX, enemy1.enemyPosY, enemy1.radius);
}

bool Enemy::shipCollision2(Ship ship) {
	return collision(ship.posShipX, ship.posShipY, 8, enemy2.enemyPosX, enemy2.enemyPosY, enemy2.radius);
}