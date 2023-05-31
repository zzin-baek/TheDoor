#include "MiniGames.h"

int MiniGames::miniGame1()
{
	int startX = 25;
	int startY = 4;
	int posX, posY;
	gotoxy(18 + startY, 3 + startX);
	TextColor(5, 7);
	printf("бс");
	posX = 18 + startY;
	posY = 3 + startX;
	while (!_kbhit())
	{
		if ((startX == 25 && startY == 25) || (startX == 24 && startY == 25))
		{
			return 1;
		}

		int key = _getch();
		if (key == 224)
		{
			key = _getch();
			switch (key)
			{
			case 72:
				if (room1_minigame1[startX - 1][startY] != 0)
				{
					gotoxy(posX, posY);
					TextColor(5, 7);
					printf("  ");

					gotoxy(posX, 3 + startX - 1);
					TextColor(5, 7);
					printf("бс");

					posY -= 1;
					startX -= 1;
				}
				break;
			case 80:
				if (room1_minigame1[startX + 1][startY] != 0)
				{
					gotoxy(posX, posY);
					TextColor(5, 7);
					printf("  ");

					gotoxy(posX, 3 + startX + 1);
					TextColor(5, 7);
					printf("бс");

					posY += 1;
					startX += 1;
				}
				break;
			case 77:
				if (room1_minigame1[startX][startY + 1] != 0)
				{
					gotoxy(posX, posY);
					TextColor(5, 7);
					printf("  ");

					gotoxy(18 + (startY * 2) - 2, 3 + startX);
					TextColor(5, 7);
					printf("бс");

					posX = 18 + (startY * 2) - 2;
					startY += 1;
				}
				break;
			case 75:
				if (room1_minigame1[startX][startY - 1] != 0)
				{
					gotoxy(posX, posY);
					TextColor(5, 7);
					printf("  ");

					gotoxy(18 + (startY * 2) - 6, 3 + startX);
					TextColor(5, 7);
					printf("бс");

					posX = 18 + (startY* 2) - 6;
					startY -= 1;
				}
				break;
			}
		}
		else if (key == 114)
		{
			showMaze();

			startX = 25;
			startY = 4;
			posX = 18 + startY;
			posY = 3 + startX;

			gotoxy(posX, posY);
			TextColor(5, 7);
			printf("бс");
		}
		else if (key == 27)
			return 0;
		
	}
}
