#pragma once
#include "header.h"
#include "Item.h"

class Inventory
{
private:
	std::vector<itemInfo> inven;
	// 벡터에 넣을 아이템을 가져온다
	Item* item;

	const char* inventory[MAXCHAR] = {
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

	// 열쇠 소지 여부를 확인하는 변수
	bool hasKey = false;

public:
	Inventory();
	~Inventory();

	void invenUI();

	void addItem(itemInfo item);
	void useItem();
	
	itemInfo getItemNum();
	
	int getSize() { return inven.size(); }
	void setHasKey(bool have) { hasKey = have; }
	bool getHasKey() { return hasKey; }

};

