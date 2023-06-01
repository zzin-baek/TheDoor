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
		for (int j = 0; j < 45; j++)
		{
			front_buffer[i][j] = '\0';
			back_buffer[i][j] = '\0';
		}
	}
}

void drawBackBuffer(const int i, const int j, const char* dot)
{
	int jx = 0;
	while (1)
	{
		if (dot[jx] == '\0') break;
		back_buffer[i][j + jx] = dot[jx];

		jx++;
	}
}

void render()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 45; j++)
		{
			if (back_buffer[i][j] != front_buffer[i][j])
			{
				gotoxy(j, i);
				if (back_buffer[i][j] == '\0')
					printf("%c", ' ');
				else
					printf("%c", back_buffer[i][j]);
			}
		}
	}

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 45; j++)
		{
			front_buffer[i][j] = back_buffer[i][j];
			back_buffer[i][j] = '\0';
		}
	}
}
