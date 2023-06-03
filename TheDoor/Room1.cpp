#include "Room1.h"

int Room1::insertPassword()
{
	int input[4] = { 0, };
	int count = 0;

	while (count < 4)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key > 47 && key < 58)
			{
				gotoxy(10 + count * 2, 33);
				input[count] = key - 48;
				printf("%d", input[count]);
				count++;
			}
			else if (key == 27)
				break;
			else
				continue;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (password[i] != input[i])
			return 0;
	}
	return 1;
}

int Room1::miniGame1()
{
	int startX = 25;
	int startY = 4;
	int posX, posY;
	gotoxy(18 + startY, 3 + startX);
	TextColor(6, 4);
	printf("¡Ú");
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
					TextColor(6, 7);
					printf("¡Ú");

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
					TextColor(6, 7);
					printf("¡Ú");

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
					TextColor(6, 7);
					printf("¡Ú");

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
					TextColor(6, 7);
					printf("¡Ú");

					posX = 18 + (startY* 2) - 6;
					startY -= 1;
				}
				break;
			}
		}
		else if (key == 27)
			return 0;
		else if (key == 114)
		{
			showMaze();

			startX = 25;
			startY = 4;
			posX = 18 + startY;
			posY = 3 + startX;

			gotoxy(posX, posY);
			TextColor(6, 4);
			printf("¡Ú");
		}
		
		
	}
}
