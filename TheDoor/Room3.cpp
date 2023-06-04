#include "Room3.h"

Room3::Room3()
{
}

Room3::~Room3()
{
}
// �����̵� ȭ�� ���
void Room3::showArcade()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(arcade[i][j], arcade[i][j]);
			printf("��");
		}
	}
	gotoxy(44, 4);
	TextColor(0, 7);
	printf("SPACE: ����, �� ��: ����Ű");
}
// �����̵� �� ���
void Room3::showEnemy(int num, int x)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			gotoxy(x + j * 2, 7 + i);
			TextColor(enemy[num][i][j], enemy[num][i][j]);
			printf("��");
		}
	}
}
// �����̵� �÷��̾� ���
void Room3::showPlayer(int num, int x)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gotoxy(x + j * 2, 22 + i);
			TextColor(player[num][i][j], player[num][i][j]);
			printf("��");
		}
	}
}
// �����̵带 Ŭ�������� ���� ȭ�� ���
void Room3::showClear()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			gotoxy(22 + j * 2, 12 + i);
			TextColor(clear[i][j], clear[i][j]);
			printf("��");
		}
	}
}
// �ݰ� ���
void Room3::showLocker()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(locker[i][j], locker[i][j]);
			printf("��");
		}
	}
}
// �޸� ���
void Room3::showNote()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(note[i][j], note[i][j]);
			printf("��");
		}
	}

	// ��Ʈ ���� ��Ÿ�� ����� ���
	for (int i = 0; i < 5; i++)
	{
		gotoxy(24, 10 + 3 * i);
		TextColor(0, 14);
		printf("%s", noter[i]);
	}
}

int Room3::playArcade()
{
	// ���� �÷��̾��� ���� ��ġ �ʱ�ȭ
	int initEnemy = 20;
	int initPlayer = 20;

	// �� ü�� �ʱ�ȭ
	int enemyHP = 10;
	// �Ѿ� ����
	int bulletNum = 0; 
	srand(time(NULL));

	while (enemyHP > 0)
	{
		// ���� �÷��̾��� ���� ��ġ�� ����� ���� �Լ�
		showEnemy(1, initEnemy);
		showPlayer(1, initPlayer);

		for (int i = 0; i < bulletNum; i++)
		{
			// ȭ�� ���� ������ �ʰ� ���� ������ ���� �Ѿ��� ���� ��ġ �����
			if (bullet[i].visible)
			{
				gotoxy(bullet[i].x, bullet[i].y);
				printf("  ");
				bullet[i].y--; // �Ѿ��� ��ġ ����
			}
		}

		// ���� (��, ��) �������� �����ϱ� ���� ����
		int enemyMove = rand() % 2;
		if (enemyMove == 0)
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

		// �¿� ����Ű�� �Է¹޾��� �� �÷��̾��� ��ġ ����
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
			// �����̽� �ٸ� �Է¹����� �Ѿ� �ʱ� ��ġ�� ����ü �迭�� ����
			else if (key == 32)
			{
				bullet[bulletNum].x = initPlayer + 4;
				bullet[bulletNum].y = 21;
				bulletNum++;
			}
			else if (key == 27)
				return 0;
		}

		// ���� �÷��̾� ���
		showEnemy(0, initEnemy);
		showPlayer(0, initPlayer);

		// �Ѿ� ���
		for (int i = 0; i < bulletNum; i++)
		{
			if (bullet[i].visible)
			{
				gotoxy(bullet[i].x, bullet[i].y);
				TextColor(14, 0);
				printf("��");
				// ���� ��ų� ȭ�� ������ ��� �Ѿ� �����
				if (bullet[i].y + 1 < 12)
				{
					// ���� ����� �� enemyHP�� ���ҽ�Ų��
					if (bullet[i].x >= initEnemy && bullet[i].x < initEnemy + 18)
						enemyHP--;
					bullet[i].visible = false;
					gotoxy(bullet[i].x, bullet[i].y);
					printf("  ");
				}
			}
		}
		// ���� ü�� ���
		gotoxy(18, 4);
		TextColor(0, 7);
		printf("HP : %d ", enemyHP);
		Sleep(80);
	}
	showClear();
	Sleep(1500);
	return 1;
}

// ���� �ҹ��ڸ� �Է¹����� ��ȣ�� �Էµȴ�. 
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
	// ����� ���Ͽ� ������ 1, Ʋ���� 0 ��ȯ
	if (strcmp(password, input) == 0)
		return 1;
	else
		return 0;
}