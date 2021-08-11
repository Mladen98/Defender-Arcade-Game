#include "Ship.h"
#include "Glut.h"
#include <math.h>
#include <stdio.h>

#define PI 3.14159

Ship::Ship() {

	alive = true;
	posShipX = 100;
	posShipY = 150;
	direction = 1;
}

void Ship::drawShip() {

	glPushMatrix();

	if (direction == 0) {

		glTranslatef(posShipX + 44, posShipY, 0);
		glRotatef(180, 0, 1, 0);
		glTranslatef(-posShipX, -posShipY, 0);

	}


	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2f(posShipX + 4, posShipY + 4);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 4, posShipY + 14);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 9, posShipY + 14);
	glColor3f(1, 0, 1);
	glVertex2f(posShipX + 9, posShipY + 4);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2f(posShipX + 9, posShipY);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 9, posShipY + 18);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 14, posShipY + 18);
	glColor3f(1, 0, 1);
	glVertex2f(posShipX + 14, posShipY);
	glScalef(0, 0, -2.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2f(posShipX + 14, posShipY);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 14, posShipY + 18);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 19, posShipY + 18);
	glColor3f(1, 0, 1);
	glVertex2f(posShipX + 19, posShipY);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2f(posShipX + 19, posShipY);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 19, posShipY + 14);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 24, posShipY + 14);
	glColor3f(1, 0, 1);
	glVertex2f(posShipX + 24, posShipY);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2f(posShipX + 24, posShipY);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 24, posShipY + 10);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 29, posShipY + 10);
	glColor3f(1, 0, 1);
	glVertex2f(posShipX + 29, posShipY);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 29, posShipY + 4);
	glColor3f(0, 0, 1);
	glVertex2f(posShipX + 29, posShipY + 8);
	glColor3f(0, 0, 1);
	glVertex2f(posShipX + 39, posShipY + 8);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(posShipX + 39, posShipY + 4);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex2f(posShipX + 39, posShipY + 4);
	glVertex2f(posShipX + 39, posShipY + 6);
	glColor3f(0, 1, 0);
	glVertex2f(posShipX + 44, posShipY + 6);
	glVertex2f(posShipX + 44, posShipY + 4);
	glEnd();

	glPopMatrix();


}

void Ship::specialKeyFunc(int key) {

	switch (key)
	{

	case GLUT_KEY_RIGHT:

		if (ship.direction == 1) {
			if (ship.posShipX + 50 >= 800) {
				ship.posShipX += 0;
			}

			else {
				ship.posShipX += 10;
			}
		}

		else
			ship.direction = 1;

		break;

	case GLUT_KEY_LEFT:

		if (ship.direction == 0) {
			if (ship.posShipX - 10 <= 0) {
				ship.posShipX -= 0;
			}

			else {
				ship.posShipX -= 10;
			}
		}

		else
			ship.direction = 0;

		break;

	case GLUT_KEY_UP:

		if (ship.posShipY + 18 >= 490) {
			ship.posShipY += 0;
		}

		else {
			ship.posShipY += 10;
		}

		break;

	case GLUT_KEY_DOWN:

		if (ship.posShipY - 18 <= 100) {
			ship.posShipY -= 0;
		}

		else {
			ship.posShipY -= 10;
		}

		break;
	}
}

void Ship::keyboardKeyFunc(unsigned char key) {

	if (key == ' ') {
		if (ship.direction == 1) {
			bullet = Bullet(2, 15);

		}


		if (ship.direction == 0) {
			bullet = Bullet(2, -15);
		}
	}

}

double Ship::getX() {
	return posShipX;
}

double Ship::getY() {
	return posShipY;
}