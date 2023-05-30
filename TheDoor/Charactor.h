#pragma once
#include "header.h"
#include "BackGround.h"


class Charactor
{
private:
	int charactor[15][12] = {
		-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		-1,0,4,0,0,-1,-1,0,0,-1,-1,-1,
		-1,0,4,4,4,0,0,4,4,0,-1,-1,
		-1,-1,0,4,4,4,4,4,4,4,0,-1,
		-1,-1,0,4,4,4,4,4,4,4,0,-1,
		-1,0,4,4,4,4,4,4,4,0,0,-1,
		-1,0,4,4,4,4,4,4,4,0,0,-1,
		-1,-1,0,4,4,4,4,4,4,4,0,-1,
		-1,0,4,4,4,4,4,4,4,0,-1,-1,
		-1,0,4,4,4,4,4,4,4,0,-1,-1,
		0,4,4,4,4,4,4,4,4,4,0,-1,
		0,4,4,4,4,4,4,4,4,4,0,-1,
		0,4,4,4,4,4,4,0,0,0,-1,-1,
		-1,0,0,0,4,4,0,0,4,0,-1,-1,
		-1,-1,-1,-1,0,0,-1,-1,0,0,-1,-1,
	};

	int _posX = 15;
	int _posY = 25;

	BackGround* bg = new BackGround;

public:
	Charactor();
	~Charactor();

	void showChar()
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				gotoxy(_posX + 2 * j, _posY + i);
				if (charactor[i][j] < 0)
					TextColor(bg->getPixelColor(_posY + i, (_posX + 2 * j) / 2), bg->getPixelColor(_posY + i, (_posX + 2 * j) / 2));
				else TextColor(charactor[i][j], charactor[i][j]);
				printf("бс");

			}
			cout << endl;
		}
		TextColor(15, 0);
	}

	void move();
	void setXY(int x, int y) { _posX = x; _posY = y; }
	int getX() { return _posX; }
	int getY() { return _posY; }

};

