#include "Room3.h"

Room3::Room3()
{
}

Room3::~Room3()
{
}
// 아케이드 화면 출력
void Room3::showArcade()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(arcade[i][j], arcade[i][j]);
			printf("■");
		}
	}
	gotoxy(44, 4);
	TextColor(0, 7);
	printf("SPACE: 공격, ← →: 방향키");
}
// 아케이드 적 출력
void Room3::showEnemy(int num, int x)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			gotoxy(x + j * 2, 7 + i);
			TextColor(enemy[num][i][j], enemy[num][i][j]);
			printf("■");
		}
	}
}
// 아케이드 플레이어 출력
void Room3::showPlayer(int num, int x)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gotoxy(x + j * 2, 22 + i);
			TextColor(player[num][i][j], player[num][i][j]);
			printf("■");
		}
	}
}
// 아케이드를 클리어했을 때의 화면 출력
void Room3::showClear()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			gotoxy(22 + j * 2, 12 + i);
			TextColor(clear[i][j], clear[i][j]);
			printf("■");
		}
	}
}
// 금고 출력
void Room3::showLocker()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(locker[i][j], locker[i][j]);
			printf("■");
		}
	}
}
// 메모 출력
void Room3::showNote()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(note[i][j], note[i][j]);
			printf("■");
		}
	}

	// 노트 위에 나타날 문장들 출력
	for (int i = 0; i < 5; i++)
	{
		gotoxy(24, 10 + 3 * i);
		TextColor(0, 14);
		printf("%s", noter[i]);
	}
}

int Room3::playArcade()
{
	// 적과 플레이어의 시작 위치 초기화
	int initEnemy = 20;
	int initPlayer = 20;

	// 적 체력 초기화
	int enemyHP = 10;
	// 총알 개수
	int bulletNum = 0; 
	srand(time(NULL));

	while (enemyHP > 0)
	{
		// 적과 플레이어의 이전 위치를 지우기 위한 함수
		showEnemy(1, initEnemy);
		showPlayer(1, initPlayer);

		for (int i = 0; i < bulletNum; i++)
		{
			// 화면 밖을 나가지 않고 적을 맞추지 않은 총알의 이전 위치 지우기
			if (bullet[i].visible)
			{
				gotoxy(bullet[i].x, bullet[i].y);
				printf("  ");
				bullet[i].y--; // 총알의 위치 변경
			}
		}

		// 적의 (좌, 우) 움직임을 구현하기 위한 변수
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

		// 좌우 방향키를 입력받았을 때 플레이어의 위치 변경
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
			// 스페이스 바를 입력받으면 총알 초기 위치를 구조체 배열에 저장
			else if (key == 32)
			{
				bullet[bulletNum].x = initPlayer + 4;
				bullet[bulletNum].y = 21;
				bulletNum++;
			}
			else if (key == 27)
				return 0;
		}

		// 적과 플레이어 출력
		showEnemy(0, initEnemy);
		showPlayer(0, initPlayer);

		// 총알 출력
		for (int i = 0; i < bulletNum; i++)
		{
			if (bullet[i].visible)
			{
				gotoxy(bullet[i].x, bullet[i].y);
				TextColor(14, 0);
				printf("▲");
				// 적과 닿거나 화면 범위를 벗어난 총알 지우기
				if (bullet[i].y + 1 < 12)
				{
					// 적과 닿았을 때 enemyHP를 감소시킨다
					if (bullet[i].x >= initEnemy && bullet[i].x < initEnemy + 18)
						enemyHP--;
					bullet[i].visible = false;
					gotoxy(bullet[i].x, bullet[i].y);
					printf("  ");
				}
			}
		}
		// 적의 체력 출력
		gotoxy(18, 4);
		TextColor(0, 7);
		printf("HP : %d ", enemyHP);
		Sleep(80);
	}
	showClear();
	Sleep(1500);
	return 1;
}

// 영어 소문자를 입력받으면 암호가 입력된다. 
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
	// 정답과 비교하여 맞으면 1, 틀리면 0 반환
	if (strcmp(password, input) == 0)
		return 1;
	else
		return 0;
}