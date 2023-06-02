#include "Inventory.h"

Inventory::Inventory()
{
	item = new Item;
}

Inventory::~Inventory()
{
	delete item;
}

void Inventory::invenUI()
{
	const char* invenui[MAXCHAR] = {
		"┏━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ ",
		"┃     인 벤 토 리   ┃    아이템                                              ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃     < 조작법 >    ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃  SPACE : 상호작용 ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃  ← → : 방향키   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┃                   ┃                                                        ┃ ",
		"┣━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫ ",
		"┃                                                                            ┃ ",
		"┃                                                                            ┃ ",
		"┃                                                                            ┃ ",
		"┃                                                                            ┃ ",
		"┃                                                                            ┃ ",
		"┃                                                                            ┃ ",
		"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ ", };

	for (int i = 0; i < 32; i++)
	{
		gotoxy(6, 4 + i);
		printf("%s\n", invenui[i]);
	}

}

void Inventory::addItem(itemInfo item)
{
	inven.push_back(item);
}

void Inventory::useItem()
{
	inven.clear();
}

itemInfo Inventory::getItemNum()
{
	if (inven.size() != 0)
		return *inven.begin();
}
