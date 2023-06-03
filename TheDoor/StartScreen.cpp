#include "StartScreen.h"

StartScreen::StartScreen()
{
}

StartScreen::~StartScreen()
{
}

void StartScreen::printIntro()
{
	PlaySound(TEXT("./BGM/키보드.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int introX = 8;
	int introY = 10;
	TextColor(15, 0);
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < strlen(intro[i]); j++)
		{
			if (_kbhit())
				Sleep(5);
			else
				Sleep(30);

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
	PlaySound(NULL, 0, 0);
	cout << endl;
	Sleep(3000);
}

void StartScreen::printOutro()
{
	PlaySound(TEXT("./BGM/키보드.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int outroX = 8;
	int outroY = 14;
	TextColor(15, 0);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < strlen(outro[i]); j++)
		{
			Sleep(40);

			gotoxy(outroX, outroY);
			if (j == 75)
			{
				outroX = 9;
				outroY += 3;
			}
			else if (sizeof(outro[i][j]) > 1)
				outroX += 2;
			else outroX++;

			cout << outro[i][j];



		}
		outroY += 3;
		outroX = 8;
	}
	PlaySound(NULL, 0, 0);
	cout << endl;
	Sleep(2000);
}
