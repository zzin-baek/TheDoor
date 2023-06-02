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

	void setHasKey(bool have) { hasKey = have; }
	bool getHasKey() { return hasKey; }

};

