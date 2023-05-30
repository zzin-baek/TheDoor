#include "MainGame.h"

MainGame::MainGame()
{
	bg = new BackGround;
	ch = new Charactor;
	ss = new StartScreen;
}

MainGame::~MainGame()
{
	delete bg;
	delete ch;
	delete ss;

}

void MainGame::mainMenu()
{
	ss->showStartScreen();



}
