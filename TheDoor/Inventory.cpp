#include "Inventory.h"

Inventory::Inventory()
{
	item = new Item;
}

Inventory::~Inventory()
{
	delete item;
}

// 인벤토리 창 출력
void Inventory::invenUI()
{
	for (int i = 0; i < 32; i++)
	{
		gotoxy(6, 4 + i);
		TextColor(15, 0);
		printf("%s\n", inventory[i]);
	}
}

// 벡터에 아이템 구조체 추가
void Inventory::addItem(itemInfo item)
{
	inven.push_back(item);
}

// 벡터에서 아이템 제거
void Inventory::useItem()
{
	inven.pop_back();
}

itemInfo Inventory::getItemNum()
{
	// 인벤토리에 있는 아이템 정보 반환
	if (inven.size() != 0)
		return *inven.begin();
}
