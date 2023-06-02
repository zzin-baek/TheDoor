#pragma once
#include "header.h"
#include "Item.h"

class Inventory
{
private:
	std::vector<itemInfo> inven;

	Item* item;

	bool hasKey = false; //¿­¼è

public:
	Inventory();
	~Inventory();

public:

	void invenUI();

	void addItem(itemInfo item);
	void useItem();
	itemInfo getItemNum();
	int getSize() { return inven.size(); }

	void setHasKey(bool have) { hasKey = have; }
	bool getHasKey() { return hasKey; }

};

