#include "BackGround.h"

char* front_buffer[15][12];
char* back_buffer[15][12];

BackGround::BackGround()
{
}

BackGround::~BackGround()
{
}

void initConsole()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			front_buffer[i][j] = " ";
			back_buffer[i][j] = " ";
		}
	}
}

void drawBackBuffer(const int i, const int j, char* image)
{

	back_buffer[i][j + 1] = image;
}

void render(int x, int y)
{
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 12; j++)
		{
			if (back_buffer[i][j] != front_buffer[i][j])
			{
				gotoxy(x + 2 * j, y + i);

				if (back_buffer[i][j] == "\0")
					printf("%s", "  ");
				else
					printf("%s", back_buffer[i][j]);
			}
		}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			front_buffer[i][j] = back_buffer[i][j];

			back_buffer[i][j] = "\0";
		}
	}
}