#include "Item.h"

Item::Item()
{
	// 구조체 배열에 아이템 정보 입력(할당)
	items[0] = { 1, "노랑 열쇠", "상자를 열어서 얻은 열쇠. 어디를 여는 열쇠일까?" };
	items[1] = { 2, "파랑 열쇠", "룰렛에서 얻은 열쇠. 어디를 여는 열쇠일까?" };
	items[2] = { 3, "빨강 열쇠", "게임기에서 나온 열쇠. 어디를 여는 열쇠일까?" };
	items[3] = { 4, "백신", "조 박사님이 개발한 백신인 것 같다." };
}

Item::~Item()
{
}

// 아이템 출력
void Item::showItem(int num)
{
	int items[15][15];
	switch (num)
	{
	case 1:
		memcpy(items, key1, sizeof(key1));
		break;
	case 2:
		memcpy(items, key2, sizeof(key2));
		break;
	case 3:
		memcpy(items, key3, sizeof(key3));
		break;
	case 4:
		memcpy(items, vaccine, sizeof(vaccine));
		break;
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			gotoxy(34 + 2 * j, 8 + i);
			TextColor(items[i][j], items[i][j]);
			printf("■");
		}
	}
}