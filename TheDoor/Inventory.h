#pragma once
#include "header.h"
#include "Item.h"

class Inventory
{
private:
	std::map<itemInfo, int> inven;

	Item* item;

public:
	Inventory();
	~Inventory();

public:
	void invenUI();
};

