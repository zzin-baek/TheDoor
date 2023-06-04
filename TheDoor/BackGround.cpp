#include "BackGround.h"

BackGround::BackGround() : _x(0)
{
}

BackGround::~BackGround()
{
}

void BackGround::showBg(int roomNum, int x)
{
	int bg[40][120];
	int bg_last[40][100];

	// 현재 위치한 방을 x값에 따라 40X45로 출력
	if (roomNum == 1)
		memcpy(bg, room_first, sizeof(room_first));
	else if (roomNum == 2)
		memcpy(bg, room_second, sizeof(room_second));
	else if (roomNum == 3)
		memcpy(bg_last, room_third, sizeof(room_third));

	if (roomNum == 3)
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 45; j++)
			{
				gotoxy(2 * j, i);
				TextColor(bg_last[i][x + j], bg_last[i][x + j]);
				printf("■");
			}
		}
		gotoxy(1, 1);
		TextColor(0, bg_last[1][1]);
		printf(" ESC : 인벤토리");

		TextColor(15, 0);
	}
	else
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 45; j++)
			{
				gotoxy(2 * j, i);
				TextColor(bg[i][x + j], bg[i][x + j]);
				printf("■");
			}
		}
		gotoxy(1, 1);
		TextColor(0, bg[1][1]);
		printf(" ESC : 인벤토리");

		TextColor(15, 0);
	}
}

int BackGround::getPixelColor(int roomNum, int x, int y)
{
	// 입력한 스테이지의 특정 위치 색깔을 받는 함수
	if (roomNum == 1)
		return room_first[x][y];
	else if (roomNum == 2)
		return room_second[x][y];
	else
		return room_third[x][y];
}