#pragma once
#include "BackGround.h"

class Charactor
{
private:
	int charactor[15][10] = {
		1,1,1,0,0,0,0,1,1,1,
		1,1,0,1,1,1,1,0,1,1,
		1,0,1,1,1,1,1,1,0,1,
		1,0,1,1,1,1,1,1,1,0,
		1,0,1,1,1,1,1,1,1,0,
		1,1,0,1,1,1,1,1,0,1,
		1,1,0,1,1,1,1,1,1,1,
		1,0,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1 
	};

public:
	Charactor() 
	{
		for (int i = 0; i < 15; i++)
		{

			for (int j = 0; j < 10; j++)
			{
				gotoxy(2 * j, i);
				TextColor(charactor[i][j], charactor[i][j]);
				printf("бс");

			}
			cout << endl;
		}
		TextColor(15, 0);
	}

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

