#include "Inventory.h"

Inventory::Inventory()
{
	item = new Item;
}

Inventory::~Inventory()
{
	delete item;
}

// �κ��丮 â ���
void Inventory::invenUI()
{
	for (int i = 0; i < 32; i++)
	{
		gotoxy(6, 4 + i);
		TextColor(15, 0);
		printf("%s\n", inventory[i]);
	}
}

// ���Ϳ� ������ ����ü �߰�
void Inventory::addItem(itemInfo item)
{
	inven.push_back(item);
}

// ���Ϳ��� ������ ����
void Inventory::useItem()
{
	inven.pop_back();
}

itemInfo Inventory::getItemNum()
{
	// �κ��丮�� �ִ� ������ ���� ��ȯ
	if (inven.size() != 0)
		return *inven.begin();
}
