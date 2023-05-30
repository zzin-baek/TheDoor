#pragma once
#include "BackGround.h"
#include "Charactor.h"
#include "StartScreen.h"

#define WIDTH		90
#define HEIGHT		40

class MainGame
{
private:
	BackGround* bg;
	Charactor* ch;
	StartScreen* ss;


public:
	MainGame();
	~MainGame();

	void mainMenu();
};

