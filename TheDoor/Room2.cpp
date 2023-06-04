#include "Room2.h"

Room2::Room2()
{
}

Room2::~Room2()
{
}

void Room2::init()
{
	stop[0] = false;
	stop[1] = false;
	stop[2] = false;
}

int Room2::playRullet()
{
	init();
	int stopNum_copy[3];
	srand(time(NULL));

	while (1)
	{
		if (stop[0])
			stopNum[0] = stopNum_copy[0];
		else
			stopNum[0] = rand() % 5;

		if (stop[1])
			stopNum[1] = stopNum_copy[1];
		else
			stopNum[1] = rand() % 5;
		
		if (stop[2])
			stopNum[2] = stopNum_copy[2];
		else
			stopNum[2] = rand() % 5;
		
		if (stop[0] && stop[1] && stop[2])
			return checkAnswer(stopNum);

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				gotoxy(20 + j * 2, 13 + i);
				TextColor(rulletNum[stopNum[0]][i][j], rulletNum[stopNum[0]][i][j]);
				printf("бс");

				gotoxy(34 + j * 2, 13 + i);
				TextColor(rulletNum[stopNum[1]][i][j], rulletNum[stopNum[1]][i][j]);
				printf("бс");

				gotoxy(48 + j * 2, 13 + i);
				TextColor(rulletNum[stopNum[2]][i][j], rulletNum[stopNum[2]][i][j]);
				printf("бс");
			}
		}
		Sleep(1000);

		if (_kbhit())
		{
			int key = _getch();
			if (key == 97)
			{
				stop[0] = true;
				stopNum_copy[0] = stopNum[0];
			}
			else if (key == 115)
			{
				stop[1] = true;
				stopNum_copy[1] = stopNum[1];
			}
			else if (key == 100)
			{
				stop[2] = true;
				stopNum_copy[2] = stopNum[2];
			}
			else if (key == 27)
				return 0;
		}
	}
}

int Room2::checkAnswer(int* arr)
{
	if ((arr[0] == 2) && (arr[1] == 3) && (arr[2] == 1))
		return 1;
	else
		return 0;
}

void Room2::rulletAnswer()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gotoxy(20 + j * 2, 13 + i);
			TextColor(rulletNum[2][i][j], rulletNum[2][i][j]);
			printf("бс");

			gotoxy(34 + j * 2, 13 + i);
			TextColor(rulletNum[3][i][j], rulletNum[3][i][j]);
			printf("бс");

			gotoxy(48 + j * 2, 13 + i);
			TextColor(rulletNum[1][i][j], rulletNum[1][i][j]);
			printf("бс");
		}
	}
}
