#include "Charactor.h"

Charactor::Charactor() : _posX(0), _posY(0)
{
	bg = new BackGround;
}

Charactor::~Charactor()
{
	delete bg;
}

// ������(��)���� �ɾ�� ĳ���� ���
void Charactor::showChar_front(int roomNum, int x)
{
	int charactor[15][12];
	// walk�� ���� ���� ĳ������ ��� �Ҵ�
	if (walk)
		memcpy(charactor, charactor_1, sizeof(charactor_1));
	else
		memcpy(charactor, charactor_2, sizeof(charactor_2));

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			gotoxy(_posX + 2 * j, _posY + i);
			// ���� ������ ��ġ�� ����� ���� ���������� ����
			if (charactor[i][j] < 0)
				TextColor(bg->getPixelColor(roomNum, _posY + i, x + (_posX + 2 * j) / 2), bg->getPixelColor(roomNum, _posY + i, x + (_posX + 2 * j) / 2));
			else TextColor(charactor[i][j], charactor[i][j]);

			printf("��");
		}

	}
	TextColor(15, 0);
}

// ����(��)�� �ɾ�� ĳ���� ���
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
			printf("��");
		}
	}
	TextColor(15, 0);
}