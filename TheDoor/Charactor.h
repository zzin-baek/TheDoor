#pragma once
#include "BackGround.h"


class Charactor
{
private:
	int charactor[15][10] = {
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
	};

	int _posX;
	int _posY;

	BackGround* bg = new BackGround;

public:
	Charactor() 
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				gotoxy(10 + 2 * j, 25 + i);
				if (charactor[i][j] < 0)
					TextColor(bg->getPixelColor(25 + i, 10 + j), bg->getPixelColor(25 + i, 10 + j));
				else TextColor(charactor[i][j], charactor[i][j]);
				printf("бс");

			}
			cout << endl;
		}
		TextColor(15, 0);
	}
	~Charactor();

	void move();
	void setXY(int x, int y) { _posX = x; _posY = y; }

	void TextColor(int font, int backGround)
	{
		int Color = font + backGround * 16;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
	}

	void gotoxy(int x, int y)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
};

