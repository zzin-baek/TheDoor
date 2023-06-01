#pragma once
#include "header.h"
#include "BackGround.h"


class Charactor
{
private:
	int charactor_1[15][12] = {
		-1,-1,-1,0,0,0,0,0,-1,-1,-1,-1,
		-1,-1,0,15,15,15,15,15,0,-1,-1,-1,
		-1,0,7,15,15,15,15,15,15,0,-1,-1,
		0,7,7,15,15,8,7,7,15,0,-1,-1,
		0,7,7,15,15,8,8,8,15,0,-1,-1,
		-1,0,7,7,15,15,15,15,15,0,-1,-1,
		-1,-1,0,7,7,7,15,15,0,-1,-1,-1,
		-1,0,7,15,15,15,15,15,15,0,-1,-1,
		0,7,15,15,15,15,15,15,15,15,0,-1,
		0,7,15,15,15,15,15,15,7,15,0,-1,
		0,7,15,15,15,15,15,15,7,15,0,-1,
		0,7,7,7,15,15,15,15,15,15,0,-1,
		-1,0,7,7,15,15,15,15,15,0,-1,-1,
		-1,-1,0,7,7,7,15,15,0,-1,-1,-1,
		-1,-1,0,0,0,0,7,7,0,-1,-1,-1,
	};

	int charactor_2[15][12] = {
		-1,-1,-1,0,0,0,0,0,-1,-1,-1,-1,
		-1,-1,0,15,15,15,15,15,0,-1,-1,-1,
		-1,0,7,15,15,15,15,15,15,0,-1,-1,
		0,7,7,15,15,8,7,7,15,0,-1,-1,
		0,7,7,15,15,8,8,8,15,0,-1,-1,
		-1,0,7,7,15,15,15,15,15,0,-1,-1,
		-1,-1,0,7,7,7,15,15,0,0,-1,-1,
		-1,0,7,15,15,15,15,15,15,15,0,-1,
		0,7,15,15,15,15,15,15,15,15,15,0,
		0,7,15,15,15,15,15,15,15,7,15,0,
		0,7,15,15,15,15,15,15,15,7,15,0,
		0,7,7,15,15,15,15,15,15,15,0,-1,
		-1,0,7,7,15,15,15,15,15,0,-1,-1,
		-1,-1,0,7,15,0,0,7,7,7,0,-1,
		-1,-1,0,7,7,0,-1,0,0,0,-1,-1,
	};

	int _posX = 15;
	int _posY = 25;
	bool walk = false;

	BackGround* bg = new BackGround;

public:
	Charactor();
	~Charactor();

	void showChar_front(int roomNum, int x)
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
				if (charactor[i][j] < 0)
					TextColor(bg->getPixelColor(roomNum, _posY + i, x + (_posX + 2 * j) / 2), bg->getPixelColor(roomNum, _posY + i, x + (_posX + 2 * j) / 2));
				else TextColor(charactor[i][j], charactor[i][j]);
				
				printf("бс");
				//drawBackBuffer(_posY + i, _posX + 2 * j, "\433[4;36m""бс");
			}
			cout << endl;
		}
		TextColor(15, 0);
	}
	void showChar_back(int roomNum, int x)
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
				gotoxy((_posX) + 2 * j, _posY + i);
				if (charactor[i][11 - j] < 0)
					TextColor(bg->getPixelColor(roomNum, _posY + i, x + (_posX + 2 * j) / 2), bg->getPixelColor(roomNum, _posY + i, x + (_posX + 2 * j) / 2));
				else TextColor(charactor[i][11-j], charactor[i][11-j]);
				printf("бс");
				//drawBackBuffer(_posY + i, _posX + 3 * j, "\433[4;36m""бс");
			}
			cout << endl;
		}
		TextColor(15, 0);
	}

	void move();
	void setXY(int x, int y) { _posX = x; _posY = y; }
	int getX() { return _posX; }
	int getY() { return _posY; }

	void setWalk(bool w) { walk = w; }
	bool getWalk() { return walk; }

};

