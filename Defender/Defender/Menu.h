#pragma once

#include "Legend.h"

class Menu {

public:
	int option;
	Legend* legend;


	bool enable;
	bool restart;
	bool end;

	Menu(Legend* legend);

	void drawMenu();
	void drawEndGameMenu();
	void specialKeyFunc(int key);
	void keyboardKeyFunc(unsigned char key);

	bool isEnabled();
};