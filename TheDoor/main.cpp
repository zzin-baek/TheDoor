#include "BackGround.h"
#include "Charactor.h"
#include "StartScreen.h"

using namespace std;


void main()
{
	int x = 0;
	int y = 0;
	system("mode con: cols=90 lines=45");
	
	BackGround* bg = new BackGround;

	while (1)
	{
		bg->showBg(2, x, y);
		Sleep(100);
		x++;
	}

	//Charactor* ch = new Charactor;

	delete bg;
	//delete ch;
	
	//StartScreen sc;

}