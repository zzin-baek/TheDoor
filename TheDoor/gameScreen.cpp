#include "gameScreen.h"

gameScreen::gameScreen()
{
}

gameScreen::~gameScreen()
{
}
// 시작화면 출력
void gameScreen::showStartScreen()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 45; j++)
		{
			gotoxy(2 * j, i);
			TextColor(startScreen[i][j], startScreen[i][j]);
			printf("■");
		}
	}
	TextColor(15, 0);
}
// 엔딩화면 출력
void gameScreen::showEndingScreen()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 45; j++)
		{
			gotoxy(2 * j, i);
			TextColor(endingScreen[i][j], endingScreen[i][j]);
			printf("■");
		}
	}
	TextColor(0, 0);
}
// 시작 나레이션 한글자씩 출력
void gameScreen::printIntro()
{
	PlaySound(TEXT("./BGM/키보드.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int introX = 8;
	int introY = 10;
	TextColor(15, 0);
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < strlen(intro[i]); j++)
		{
			// 아무 키나 입력하면 빠르게 출력
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
// 엔딩 나레이션 출력
void gameScreen::printOutro()
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
