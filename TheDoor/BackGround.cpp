#include "BackGround.h"

char front_buffer[40][90];
char back_buffer[40][90];


BackGround::BackGround()
{
}

BackGround::~BackGround()
{
}

void init_buffer()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 90; j++)
		{
			front_buffer[i][j] = NULL;
			back_buffer[i][j] = NULL;
		}
	}
}

void drawBackBuffer(const int i, const int j, const char* dot)
{
	int jx = 0;
	while (1)
	{
		if (dot[jx] == NULL) break;
		back_buffer[i][j + jx] = dot[jx];

		jx+=2;
	}
}

void render()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 90; j++)
		{
			if (back_buffer[i][j] != front_buffer[i][j])
			{
				gotoxy(j, i);
				if (back_buffer[i][j] == NULL)
					printf("%c", ' ');
				else
					printf("%c", back_buffer[i][j]);
			}
		}
	}

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 90; j++)
		{
			front_buffer[i][j] = back_buffer[i][j];
			back_buffer[i][j] = NULL;
		}
	}
}
