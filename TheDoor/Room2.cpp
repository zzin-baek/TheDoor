#include "Room2.h"

Room2::Room2()
{
}

Room2::~Room2()
{
}

// 시계 출력
void Room2::showClock()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(clock[i][j], clock[i][j]);
			printf("■");
		}
	}
}
// 촛대 출력
void Room2::showCandle()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(candle[i][j], candle[i][j]);
			printf("■");
		}
	}
}
// 룰렛 출력
void Room2::showRullet()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(14 + j * 2, 3 + i);
			TextColor(rullet[i][j], rullet[i][j]);
			printf("■");
		}
	}
	// 안내 문구
	gotoxy(18, 26);
	TextColor(0, 14);
	printf("a, s, d: 룰렛 멈추기");
}

// 룰렛이 다시 랜덤하게 돌아갈 수 있도록 초기화
void Room2::init()
{
	stop[0] = false;
	stop[1] = false;
	stop[2] = false;
}
// 룰렛 구현
int Room2::playRullet()
{
	init();
	// 멈췄을 때 배열 저장
	int stopNum_copy[3];
	srand(time(NULL));
	
	while (1)
	{	
		// 룰렛이 멈췄다면 stop = true 멈췄을 때의 배열저장 그렇지 않으면 다시 랜덤한 룰렛 출력
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
		
		// 룰렛 3개가 다 멈췄을 때 정답인지 판단
		if (stop[0] && stop[1] && stop[2])
			return checkAnswer(stopNum);

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				gotoxy(20 + j * 2, 13 + i);
				TextColor(rulletNum[stopNum[0]][i][j], rulletNum[stopNum[0]][i][j]);
				printf("■");

				gotoxy(34 + j * 2, 13 + i);
				TextColor(rulletNum[stopNum[1]][i][j], rulletNum[stopNum[1]][i][j]);
				printf("■");

				gotoxy(48 + j * 2, 13 + i);
				TextColor(rulletNum[stopNum[2]][i][j], rulletNum[stopNum[2]][i][j]);
				printf("■");
			}
		}

		// 룰렛 속도 조절
		Sleep(1000);

		if (_kbhit())
		{
			// a, s, d를 입력했을 때 각 칸의 출력을 고정하기 위해 stopNum_copy에 배열 저장
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

// 룰렛이 정답인지 판단하는 함수
int Room2::checkAnswer(int* arr)
{
	if ((arr[0] == 2) && (arr[1] == 3) && (arr[2] == 1))
		return 1;
	else
		return 0;
}

// 정답을 맞추고 난 뒤 정답 룰렛만 출력
void Room2::rulletAnswer()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gotoxy(20 + j * 2, 13 + i);
			TextColor(rulletNum[2][i][j], rulletNum[2][i][j]);
			printf("■");

			gotoxy(34 + j * 2, 13 + i);
			TextColor(rulletNum[3][i][j], rulletNum[3][i][j]);
			printf("■");

			gotoxy(48 + j * 2, 13 + i);
			TextColor(rulletNum[1][i][j], rulletNum[1][i][j]);
			printf("■");
		}
	}
}
