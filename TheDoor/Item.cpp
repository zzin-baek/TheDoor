#include "Item.h"

Item::Item()
{
	// ����ü �迭�� ������ ���� �Է�(�Ҵ�)
	items[0] = { 1, "��� ����", "���ڸ� ��� ���� ����. ��� ���� �����ϱ�?" };
	items[1] = { 2, "�Ķ� ����", "�귿���� ���� ����. ��� ���� �����ϱ�?" };
	items[2] = { 3, "���� ����", "���ӱ⿡�� ���� ����. ��� ���� �����ϱ�?" };
	items[3] = { 4, "���", "�� �ڻ���� ������ ����� �� ����." };
}

Item::~Item()
{
}

// ������ ���
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
			printf("��");
		}
	}
}