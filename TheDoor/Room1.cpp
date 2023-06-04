#include "Room1.h"

Room1::Room1()
{
}

Room1::~Room1()
{
}

// �̷� ���
void Room1::showMaze()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(maze[i][j], maze[i][j]);
			printf("��");
		}
	}
	gotoxy(16, 4);
	TextColor(0, 14);
	printf(" r : reset");
}

// �̷θ� Ǯ�� �� �ܼ� ���
void Room1::showClue()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(mazeClear[i][j], mazeClear[i][j]);
			printf("��");
		}
	}
}

// ���� ���
void Room1::showStatue()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(statue[i][j], statue[i][j]);
			printf("��");
		}
	}
}
// �ڹ��� ���
void Room1::showBox()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(box[i][j], box[i][j]);
			printf("��");
		}
	}
}
// �̷� ����
int Room1::playMaze()
{
	int startX = 25;
	int startY = 4;
	int posX, posY;

	gotoxy(18 + startY, 3 + startX);
	TextColor(6, 4);
	printf("��");

	// player�� ���� ��ġ �ʱ�ȭ
	posX = 18 + startY;
	posY = 3 + startX;

	// ����Ű�� �Է¹��� �� player�� ������ ����
	while (!_kbhit())
	{
		// �ⱸ�� �����ϸ� 1��ȯ
		if ((startX == 25 && startY == 25) || (startX == 24 && startY == 25))
			return 1;

		int key = _getch();
		if (key == 224)
		{
			key = _getch();
			// ��ġ�� ������ ������ �����̱� ���� ��ġ�� ����� ������ ���� ��ġ�� posX, posY�� ����
			switch (key)
			{
			case UP:
				if (maze[startX - 1][startY] != 0)
				{
					gotoxy(posX, posY);
					TextColor(5, 7);
					printf("  ");

					gotoxy(posX, 3 + startX - 1);
					TextColor(6, 7);
					printf("��");

					posY -= 1;
					startX -= 1;
				}
				break;
			case DOWN:
				if (maze[startX + 1][startY] != 0)
				{
					gotoxy(posX, posY);
					TextColor(5, 7);
					printf("  ");

					gotoxy(posX, 3 + startX + 1);
					TextColor(6, 7);
					printf("��");

					posY += 1;
					startX += 1;
				}
				break;
			case RIGHT:
				if (maze[startX][startY + 1] != 0)
				{
					gotoxy(posX, posY);
					TextColor(5, 7);
					printf("  ");

					gotoxy(18 + (startY * 2) - 2, 3 + startX);
					TextColor(6, 7);
					printf("��");

					posX = 18 + (startY * 2) - 2;
					startY += 1;
				}
				break;
			case LEFT:
				if (maze[startX][startY - 1] != 0)
				{
					gotoxy(posX, posY);
					TextColor(5, 7);
					printf("  ");

					gotoxy(18 + (startY * 2) - 6, 3 + startX);
					TextColor(6, 7);
					printf("��");

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
			// r Ű�� ������ player�� ��ġ�� �ʱ�ȭ�Ѵ�.
			showMaze();

			startX = 25;
			startY = 4;
			posX = 18 + startY;
			posY = 3 + startX;

			gotoxy(posX, posY);
			TextColor(6, 4);
			printf("��");
		}
	}
}

// �ڹ����� ��й�ȣ�� �Է¹޴� �Լ�
int Room1::insertPassword()
{
	int input[4] = { 0, };
	int count = 0;

	while (count < 4)
	{
		// ���ڸ� ������ �Էµ� �� �ֵ��� ����
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

	// ���ڸ� �� �Է¹����� �������� �ƴ��� return
	for (int i = 0; i < 4; i++)
	{
		if (password[i] != input[i])
			return 0;
	}
	return 1;
}