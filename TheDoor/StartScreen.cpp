#include "StartScreen.h"

StartScreen::StartScreen()
{
}

StartScreen::~StartScreen()
{
}

void StartScreen::printIntro()
{
	int introX = 8;
	int introY = 10;
	TextColor(15, 0);
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < strlen(intro[i].c_str()); j++)
		{
			Sleep(40);
			gotoxy(introX, introY);	
			if (j == 75)
			{
				introX = 9;
				introY += 3;
			}
			else introX++;

			cout << intro[i][j];
			

			
		}
		introY += 3;
		introX = 8;
	}
	cout << endl;

	Sleep(3000);
}

void StartScreen::printOutro()
{
	int outroX = 8;
	int outroY = 10;
	TextColor(15, 0);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < strlen(outro[i].c_str()); j++)
		{
			Sleep(40);
			gotoxy(outroX, outroY);
			if (j == 75)
			{
				outroX = 9;
				outroY += 3;
			}
			else outroX++;

			cout << outro[i][j];



		}
		outroY += 3;
		outroX = 8;
	}
	cout << endl;
	Sleep(2000);
}
