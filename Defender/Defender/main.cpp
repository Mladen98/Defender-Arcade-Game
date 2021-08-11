/*
* Napisati kratko uputstvo za koriscenje igrice
*
*/

#include <math.h>		
#include <stdio.h>
#include <stdlib.h>		
#include "Glut.h"
#include "Ship.h"
#include "Enemy.h"
#include "Legend.h"
#include "Menu.h"
#include "Pool.h"

const double Xmin = 0.0, Xmax = 800.0;
const double Ymin = 0.0, Ymax = 600.0;

bool running = false;

Ship ship;
Bullet bullet;
Legend legend;
Menu menu(&legend);
Pool pool(&legend);

void myKeyboardFunc(unsigned char key, int x, int y)
{
	menu.keyboardKeyFunc(key);
	ship.keyboardKeyFunc(key);
}

void mySpecialKeyFunc(int key, int x, int y)
{
	menu.specialKeyFunc(key);
	ship.specialKeyFunc(key);
}


void drawLine() {
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(0, 500);
	glVertex2f(800, 500);
	glEnd();
}

void drawGround() {
	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2f(0, 0);
	glVertex2f(100, 100);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2f(100, 100);
	glVertex2f(200, 80);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2f(200, 80);
	glVertex2f(300, 100);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2f(300, 100);
	glVertex2f(450, 30);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2f(450, 30);
	glVertex2f(550, 70);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2f(550, 70);
	glVertex2f(625, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2f(625, 0);
	glVertex2f(700, 100);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2f(700, 100);
	glVertex2f(750, 50);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2f(750, 50);
	glVertex2f(800, 50);
	glEnd();
}


void drawRect(float x, float y, float w, float h) {
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y - h);
	glVertex2f(x, y - h);
	glEnd();
}

void drawBoundaries() {
	drawRect(0, 600, 800, 3);
	drawRect(0, 3, 800, 3);

	drawRect(0, 600, 3, 600);
	drawRect(797, 600, 3, 600);
}

void drawMinimap() {

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(360, 500, 0);
	glScalef(0.35, 0.2, 0);

	drawBoundaries();
	drawLine();
	drawGround();

	ship.drawShip();

	glPopMatrix();

}

void drawScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	drawBoundaries();

	if (!(pool.startGame)) {
		menu.end = pool.gameOver;

		if (!menu.end)
			menu.drawMenu();
		else
			menu.drawEndGameMenu();
	}

	else {

		drawMinimap();
		drawLine();
		drawGround();

		legend.drawLegend();

		ship.drawShip();
		bullet.drawBullet();
		bullet.moveBullet();

		pool.drawEnemies();
		pool.moveEnemies();

		pool.BulletCollisionHandler(&bullet, &enemy, &enemy1, &enemy2);
		pool.shipCollisionHandler(&ship, &enemy, &enemy1, &enemy2);

	}

	glFlush();
	glutSwapBuffers();

}

void Drawing(int) {

	if (menu.restart) {

		ship = *(new Ship());
		legend = *(new Legend());
		menu = *(new Menu(&legend));
		pool = *(new Pool(&legend));
		running = true;
		pool.startGame = true;
		menu.enable = false;
	}

	if (!menu.isEnabled()) {
		if (running == false) {
			pool.startGame = true;
			running = true;
		}
	}

	glutPostRedisplay();
	glutTimerFunc(1000 / 60, Drawing, 0);
}

void initRendering()
{
	Drawing(0);
	glLineWidth(2);

	/*glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0, 0);
	glClearDepth(1);
	glShadeModel(GL_SMOOTH);*/

}

void resizeWindow(int w, int h)
{
	double scale, center;
	double windowXmin, windowXmax, windowYmin, windowYmax;

	glViewport(0, 0, w, h);

	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;
	if ((Xmax - Xmin) / w < (Ymax - Ymin) / h) {
		scale = ((Ymax - Ymin) / h) / ((Xmax - Xmin) / w);
		center = (Xmax + Xmin) / 2;
		windowXmin = center - (center - Xmin)*scale;
		windowXmax = center + (Xmax - center)*scale;
		windowYmin = Ymin;
		windowYmax = Ymax;
	}
	else {
		scale = ((Xmax - Xmin) / w) / ((Ymax - Ymin) / h);
		center = (Ymax + Ymin) / 2;
		windowYmin = center - (center - Ymin)*scale;
		windowYmax = center + (Ymax - center)*scale;
		windowXmin = Xmin;
		windowXmax = Xmax;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(windowXmin, windowXmax, windowYmin, windowYmax, -1, 1);

	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(10, 60);
	glutInitWindowSize(800, 600);

	glutCreateWindow("Defender Arcade Game");

	initRendering();

	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(mySpecialKeyFunc);


	glutReshapeFunc(resizeWindow);


	glutDisplayFunc(drawScene);

	glutMainLoop();

	return(0);
}