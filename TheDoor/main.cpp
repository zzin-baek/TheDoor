#include "MainGame.h"
#include "header.h"

void main()
{
	int start = 0;
	
	MainGame mg;

	mg.init();

	start = mg.mainMenu();
	if (start == 35)
	{
		mg.gameStart();
	}
	else
		exit(0);
}