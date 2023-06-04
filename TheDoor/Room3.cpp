#include "Room3.h"

Room3::Room3()
{
}

Room3::~Room3()
{
}

int Room3::playArcade()
{
	int initEnemy = 20;
	int initPlayer = 20;

	int enemyHP = 10;

	int bulletNum = 0;
	srand(time(NULL));
	while (enemyHP > 0)
	{
		//showArcade();
		showEnemy(1, initEnemy);
		showPlayer(1, initPlayer);

		for (int i = 0; i < bulletNum; i++)
		{
			if (bullet[i].visible)
			{
				gotoxy(bullet[i].x, bullet[i].y);
				printf("  ");
				bullet[i].y--;
			}
		}
		int enemyMove = rand() % 10;
		if (enemyMove % 2 == 0)
		{
			if (initEnemy - 4 < 20)
				continue;
			else
				initEnemy -= 4;
		}
		else
		{
			if (initEnemy + 4 > 50)
				continue;
			else
				initEnemy += 4;
		}

		if (_kbhit())
		{
			int key = _getch();
			if (key == RIGHT)
			{
				if (initPlayer + 2 > 58)
					continue;
				else
					initPlayer += 2;
			}
			else if (key == LEFT)
			{
				if (initPlayer - 2 < 20)
					continue;
				else
					initPlayer -= 2;
			}
			else if (key == 32)
			{
				bullet[bulletNum].x = initPlayer + 4;
				bullet[bulletNum].y = 21;
				bulletNum++;
			}
			else if (key == 27)
				return 0;
		}


		showEnemy(0, initEnemy);
		showPlayer(0, initPlayer);
		for (int i = 0; i < bulletNum; i++)
		{
			if (bullet[i].visible)
			{
				gotoxy(bullet[i].x, bullet[i].y);
				TextColor(14, 0);
				printf("бу");
				if (bullet[i].y + 1 < 12)
				{
					if (bullet[i].x >= initEnemy && bullet[i].x < initEnemy + 18)
						enemyHP--;
					bullet[i].visible = false;
					gotoxy(bullet[i].x, bullet[i].y);
					printf("  ");
				}
			}
		}
		gotoxy(18, 4);
		TextColor(0, 7);
		printf("HP : %d ", enemyHP);
		Sleep(80);
	}
	showClear();
	Sleep(2000);
	return 1;
}

int Room3::insertPassword()
{
	char input[6] = "";
	int count = 0;

	while (count < 5)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key > 96 && key < 123)
			{
				gotoxy(10 + count * 2, 33);
				input[count] = char(key);
				printf("%c", input[count]);
				count++;
			}
			else if (key == 27)
				break;
			else
				continue;
		}
	}

	if (strcmp(password, input) == 0)
		return 1;
	else
		return 0;
}