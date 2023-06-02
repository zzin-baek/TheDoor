#pragma once
#include "header.h"

struct itemInfo
{
	int roomNum;
	std::string itemName;
	std::string feature;
};

class Item
{
private:
	int key1[15][15] = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,6,6,6,6,6,0,0,0,0,0,
		0,0,0,0,6,6,0,0,0,6,6,0,0,0,0,
		0,0,0,0,6,0,0,0,0,0,6,0,0,0,0,
		0,0,0,0,6,6,0,0,0,6,6,0,0,0,0,
		0,0,0,0,0,6,6,6,6,6,0,0,0,0,0,
		0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,
		0,0,0,0,0,0,0,6,6,6,0,0,0,0,0,
		0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,
		0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};
	int key2[15][15] = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,9,9,9,9,9,0,0,0,0,0,
		0,0,0,0,9,9,0,0,0,9,9,0,0,0,0,
		0,0,0,0,9,0,0,0,0,0,9,0,0,0,0,
		0,0,0,0,9,9,0,0,0,9,9,0,0,0,0,
		0,0,0,0,0,9,9,9,9,9,0,0,0,0,0,
		0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,9,9,0,0,0,0,0,0,
		0,0,0,0,0,0,0,9,9,9,0,0,0,0,0,
		0,0,0,0,0,0,0,9,9,0,0,0,0,0,0,
		0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};
	int key3[15][15] = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,
		0,0,0,0,4,4,0,0,0,4,4,0,0,0,0,
		0,0,0,0,4,0,0,0,0,0,4,0,0,0,0,
		0,0,0,0,4,4,0,0,0,4,4,0,0,0,0,
		0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,
		0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,
		0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,
		0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,
		0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

	int vaccine[15][15] = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,
		0,0,0,0,0,0,0,0,0,0,0,7,8,8,0,
		0,0,0,0,0,0,0,0,0,8,0,7,7,8,0,
		0,0,0,0,0,0,0,0,8,0,8,0,0,0,0,
		0,0,0,0,0,0,0,8,0,0,0,8,0,0,0,
		0,0,0,0,0,0,8,0,0,0,8,0,0,0,0,
		0,0,0,0,0,8,10,10,10,8,0,0,0,0,0,
		0,0,0,0,8,10,10,10,8,0,0,0,0,0,0,
		0,0,0,8,10,10,10,8,0,0,0,0,0,0,0,
		0,0,8,10,10,10,8,0,0,0,0,0,0,0,0,
		0,0,0,8,10,8,0,0,0,0,0,0,0,0,0,
		0,0,7,0,8,0,0,0,0,0,0,0,0,0,0,
		0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

	itemInfo items[4];

public:
	Item();
	~Item();

	itemInfo* getItem() { return items; }
	void showItem()
	{
		
	}
};

