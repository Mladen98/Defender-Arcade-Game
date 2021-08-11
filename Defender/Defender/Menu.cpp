#include "Menu.h"
#include "Glut.h"

Menu::Menu(Legend* legend) {

	option = 0;
	enable = true;
	end = false;
	restart = false;
	Menu::legend = legend;
}

void Menu::drawMenu() {

	char array[] = "DEFENDER";
	char startGameString[] = "START NEW GAME";
	char exitGameString[] = "EXIT GAME";

	glPushMatrix();

	glTranslatef(60, 400, 0);
	glColor3f(1, 1, 0);

	for (int i = 0; i < 9; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, array[i]);
	}

	glPopMatrix();

	glPushMatrix();

	glTranslatef(210, 250, 0);
	glScalef(0.3, 0.3, 1);
	glColor3f(0, 0.5, 1);

	for (int i = 0; i < 14; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, startGameString[i]);
	}

	glPopMatrix();

	glPushMatrix();

	glTranslatef(270, 170, 0);
	glScalef(0.3, 0.3, 1);
	glColor3f(1, 0.5, 0);

	for (int i = 0; i < 9; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, exitGameString[i]);
	}

	glPopMatrix();

	double offsetY = 260;

	if (option == 1)
		offsetY = 175;

	glPushMatrix();
	glTranslatef(140, offsetY, 0);
	glScalef(25, 25, 1);
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2f(-1, -0.5);
	glVertex2f(-1, 0.5);
	glVertex2f(1, 0);
	glEnd();

	glPopMatrix();
}

void Menu::drawEndGameMenu() {

	char array[] = "GAME OVER";
	char playAgainString[] = "PLAY AGAIN";
	char scoreString[] = "SCORE: ";
	char exitString[] = "EXIT";

	glPushMatrix();
	glTranslatef(120, 400, 0);
	glScalef(0.7, 0.7, 1);
	glColor3f(1, 0.5, 0);

	for (int i = 0; i < 9; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, array[i]);
	}

	glPopMatrix();

	glPushMatrix();
	glTranslatef(275, 300, 0);
	glScalef(0.3, 0.3, 1);
	glColor3f(1, 1, 0);

	for (int i = 0; i < 7; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, scoreString[i]);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(460, 300, 0);
	glScalef(0.3, 0.3, 1);
	(*legend).drawScore();

	glPopMatrix();


	glPushMatrix();
	glTranslatef(290, 200, 0);
	glScalef(0.25, 0.25, 1);
	glColor3f(0, 1, 0);

	for (int i = 0; i < 10; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, playAgainString[i]);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(350, 120, 0);
	glScalef(0.25, 0.25, 1);
	glColor3f(1, 0, 0);

	for (int i = 0; i < 4; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, exitString[i]);

	glPopMatrix();

	double offset = 210;

	if (option == 1)
		offset = 130;

	glPushMatrix();
	glTranslatef(200, offset, 0);
	glScalef(25, 25, 1);
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0.5, 0.5);
	glVertex2f(-1, -0.5);
	glVertex2f(-1, 0.5);
	glVertex2f(1, 0);
	glEnd();

	glPopMatrix();

}

void Menu::keyboardKeyFunc(unsigned char key) {

	if (key == 13) {

		if (option == 0) {
			if (enable == true)
				enable = false;

			if (end == true) {
				restart = true;
			}
		}

		if (option == 1 && (enable == true || end == true)) {
			exit(0);
		}
	}
}

void Menu::specialKeyFunc(int key) {

	switch (key)
	{

	case GLUT_KEY_UP:
		option = 0;
		break;

	case GLUT_KEY_DOWN:
		option = 1;
		break;

	}

}


bool Menu::isEnabled() {
	return enable;
}