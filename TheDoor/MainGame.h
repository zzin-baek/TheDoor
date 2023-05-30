#pragma once
#include "BackGround.h"
#include "Charactor.h"
#include "StartScreen.h"
#include "header.h"

#define WIDTH		90
#define HEIGHT		40

#define		UP		72
#define		DOWN	80
#define		RIGHT	77
#define		LEFT	75

class MainGame
{
private:
	BackGround* bg;
	Charactor* ch;
	StartScreen* ss;


public:
	MainGame();
	~MainGame();

	void init();
	int mainMenu();
	void stageOne();
	void stageTwo();
	void stageThree();

	void gameStart();
};

