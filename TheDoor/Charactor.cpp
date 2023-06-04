#include "Charactor.h"

Charactor::Charactor() : _posX(0), _posY(0)
{
	bg = new BackGround;
}

Charactor::~Charactor()
{
	delete bg;
}

// 오른쪽(앞)으로 걸어가는 캐릭터 출력
void Charactor::showChar_front(int roomNum, int x)
{
	int charactor[15][12];
	// walk의 값에 따라 캐릭터의 모습 할당
	if (walk)
		memcpy(charactor, charactor_1, sizeof(charactor_1));
	else
		memcpy(charactor, charactor_2, sizeof(charactor_2));

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			gotoxy(_posX + 2 * j, _posY + i);
			// 값이 음수인 위치는 배경의 색을 가져오도록 설정
			if (charactor[i][j] < 0)
				TextColor(bg->getPixelColor(roomNum, _posY + i, x + (_posX + 2 * j) / 2), bg->getPixelColor(roomNum, _posY + i, x + (_posX + 2 * j) / 2));
			else TextColor(charactor[i][j], charactor[i][j]);

			printf("■");
		}

	}
	TextColor(15, 0);
}

// 왼쪽(뒤)로 걸어가는 캐릭터 출력
void Charactor::showChar_back(int roomNum, int x)
{
	int charactor[15][12];
	if (walk)
		memcpy(charactor, charactor_1, sizeof(charactor_1));
	else
		memcpy(charactor, charactor_2, sizeof(charactor_2));

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			gotoxy(_posX + 2 * j, _posY + i);
			if (charactor[i][11 - j] < 0)
				TextColor(bg->getPixelColor(roomNum, _posY + i, x + (_posX + 2 * j) / 2), bg->getPixelColor(roomNum, _posY + i, x + (_posX + 2 * j) / 2));
			else TextColor(charactor[i][11 - j], charactor[i][11 - j]);
			printf("■");
		}
	}
	TextColor(15, 0);
}