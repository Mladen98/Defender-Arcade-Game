#include "stdlib.h"
#include "Pool.h"
#include "time.h"
#include "math.h"
#include "Enemy.h"
#include <stdio.h>

#define PI 3.1415926535897932

Enemy enemy = Enemy(400, 400, 6, 5);

Enemy enemy1 = Enemy(500, 450, 5, 8);
Enemy enemy2 = Enemy(300, 300, 7, 7);


Pool::Pool(Legend* legend) {
	
	level = 1;
	Pool::legend = legend;
	gameOver = false;
	startGame = false;
	generateNextLevel(2);

}

void Pool::drawEnemies() {

	if (level == 1) {
		if (enemy.isAlive()) {
			enemy.drawEnemy();
		}
		else {
			enemy.alive = false;
		}

		if (enemy1.isAlive()) {
			enemy1.drawEnemy1();
		}
		else {
			enemy1.alive = false;
		}
	}

	else if (level == 2) {
		if (enemy.isAlive()) {
			enemy.drawEnemy();
		}
		else {
			enemy.alive = false;
		}

		if (enemy2.isAlive()) {
			enemy2.drawEnemy2();
		}
		else {
			enemy2.alive = false;
		}
	}

	else if (level == 3) {
		if (enemy1.isAlive()) {
			enemy1.drawEnemy1();
		}
		else {
			enemy1.alive = false;
		}

		if (enemy2.isAlive()) {
			enemy2.drawEnemy2();
		}
		else {
			enemy2.alive = false;
		}
	}

	else if (level == 4) {
		if (enemy.isAlive()) {
			enemy.drawEnemy();
		}
		else {
			enemy.alive = false;
		}

		if (enemy1.isAlive()) {
			enemy1.drawEnemy1();
		}
		else {
			enemy1.alive = false;
		}
		if (enemy2.isAlive()) {
			enemy2.drawEnemy2();
		}
		else {
			enemy2.alive = false;
		}
	}
}

void Pool::moveEnemies() {

	if (level == 1) {
		enemy.moveEnemy();
		enemy1.moveEnemy1();
	}

	else if (level == 2) {
		enemy.moveEnemy();
		enemy2.moveEnemy2();
	}

	else if (level == 3) {
		enemy1.moveEnemy1();
		enemy2.moveEnemy2();
	}

	else if (level == 4) {
		enemy.moveEnemy();
		enemy1.moveEnemy1();
		enemy2.moveEnemy2();
	}

}

void Pool::generateNextLevel(int lvl) {

	if (level == 1) {
		enemy.alive = true;
		enemy1.alive = true;
		enemy2.alive = false;
	}

	else if (level == 2) {
		enemy.alive = true;
		enemy2.alive = true;
		enemy1.alive = false;
	}

	else if (level == 3) {
		enemy1.alive = true;
		enemy2.alive = true;
		enemy.alive = false;
	}

	else if (level == 4) {
		enemy.alive = true;
		enemy1.alive = true;
		enemy2.alive = true;
	}

	else if (level == 5) {
		gameOver = true;
		Pool::startGame = false;
	}

}

bool Pool::allClear(Enemy* e, Enemy* e1, Enemy* e2) {

	if (!e->isAlive() && !e1->isAlive() && !e->isAlive()) {
		return true;
	}
	
	return false;
}

void Pool::BulletCollisionHandler(Bullet* b, Enemy* e, Enemy* e1, Enemy* e2) {
	
	if (e->isAlive()) {

		if (e->bulletCollision(*b)) {

			e->alive = false;
			bullet.distance = 1000;
			(*(legend)).score += 50;

			if (allClear(e, e1, e2)) {
				Pool::level += 1;
				generateNextLevel(Pool::level);
				(*(legend)).level += 1;
				ship.posShipX = 100;
				ship.posShipY = 150;
			}
		}
	}

	if (e1->isAlive()) {

		if (e1->bulletCollision1(*b)) {

			e1->alive = false;
			bullet.distance = 1000;
			(*(legend)).score += 60;

			if (allClear(e, e1, e2)) {
				Pool::level += 1;
				generateNextLevel(Pool::level);
				(*(legend)).level += 1;
				ship.posShipX = 100;
				ship.posShipY = 150;
			}
		}
	}

	if(e2->isAlive()) {

		if (e2->bulletCollision2(*b)) {

			e2->alive = false;
			bullet.distance = 1000;
			(*(legend)).score += 70;

			if (allClear(e, e1, e2)) {
				Pool::level += 1;
				generateNextLevel(Pool::level);
				(*(legend)).level += 1;
				ship.posShipX = 100;
				ship.posShipY = 150;
			}

		}
	}
}

void Pool::shipCollisionHandler(Ship* ship, Enemy* e, Enemy* e1, Enemy* e2) {

	if (e->isAlive()) {

		if (e->shipCollision(*ship)) {
			e->alive = false;

			(*(legend)).lives--;
			(*(ship)).posShipX = 100;
			(*(ship)).posShipY = 150;

			if ((*(legend)).lives == 0) {
				gameOver = true;
				Pool::startGame = false;
			}

			else if (allClear(e, e1, e2)) {
				Pool::level += 1;
				generateNextLevel(Pool::level);
				(*(legend)).level += 1;
			}
		}
	}

	if (e1->isAlive()) {

		if (e1->shipCollision1(*ship)) {
			e1->alive = false;

			(*(legend)).lives--;
			(*(ship)).posShipX = 100;
			(*(ship)).posShipY = 150;

			if ((*(legend)).lives == 0) {
				gameOver = true;
				Pool::startGame = false;
			}

			else if (allClear(e, e1, e2)) {
				Pool::level += 1;
				generateNextLevel(Pool::level);
				(*(legend)).level += 1;
			}
		}
	}

	if (e2->isAlive()) {

		if (e2->shipCollision2(*ship)) {
			e2->alive = false;

			(*(legend)).lives--;
			(*(ship)).posShipX = 100;
			(*(ship)).posShipY = 150;

			if ((*(legend)).lives == 0) {
				gameOver = true;
				Pool::startGame = false;
			}

			else if (allClear(e, e1, e2)) {
				Pool::level += 1;
				generateNextLevel(Pool::level);
				(*(legend)).level += 1;
			}
		}
	}
}