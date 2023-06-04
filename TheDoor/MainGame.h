#pragma once
#include "header.h"
#include "BackGround.h"
#include "Charactor.h"
#include "gameScreen.h"
#include "Room1.h"
#include "Room2.h"
#include "Room3.h"
#include "Inventory.h"
#include "Item.h"

class MainGame
{
private:
	BackGround* bg;
	Charactor* ch;
	gameScreen* ss;
	Room1* room1;
	Room2* room2;
	Room3* room3;

	Inventory* inven;
	Item* item;

	const char* msg[MAXCHAR] = {
		"������������������������������������������������������������������������������������������������������������������������������������������������������������ ",
		"��                                                                            �� ",
		"��                                                                            �� ",
		"��                                                                            �� ",
		"��                                                                            �� ",
		"��                                                                            �� ",
		"��                                                                            �� ",
		"������������������������������������������������������������������������������������������������������������������������������������������������������������ ", };

public:
	MainGame();
	~MainGame();

	void init();

	int mainMenu();
	void mainScript();

	void stageOne();
	void stageTwo();
	void stageThree();

	void message(std::string str);

	void gameStart();

	void ending();
};