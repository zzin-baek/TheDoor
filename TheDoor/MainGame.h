#pragma once
#include "header.h"
#include "BackGround.h"
#include "Charactor.h"
#include "StartScreen.h"
#include "Room1.h"
#include "Room2.h"
#include "Inventory.h"

#define		WIDTH		90
#define		HEIGHT		40

#define		UP			72
#define		DOWN		80
#define		RIGHT		77
#define		LEFT		75

struct stRect
{
	int nWidth;
	int nHeight;
};

struct stConsole
{
	// Console Handler
	HANDLE hConsole;
	// Console Rect Data
	stRect rtConsole;
	// Console Buffer Handler
	HANDLE hBuffer[2];
	// Current Console Buffer Index
	int nCurBuffer;

	stConsole()
		: hConsole(nullptr), hBuffer{ nullptr, }, nCurBuffer(0)
	{}
};

class MainGame
{
private:
	BackGround* bg;
	Charactor* ch;
	StartScreen* ss;
	Room1* room1;
	Room2* room2;

	Inventory* inven;

public:
	MainGame();
	~MainGame();

	void init();
	int mainMenu();
	void stageOne();
	void stageTwo();
	void stageThree();

	void gameStart();

	void ClearScreen();
	void BufferFlip();
};

