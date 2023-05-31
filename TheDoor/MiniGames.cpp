#include "MiniGames.h"

void MiniGames::miniGame1()
{
	showMaze();

	while (1)
	{
		if (_kbhit())
		{
			int key = _getch();
			showMaze();

			if (key == 32)
				gameClear = true;

			if (gameClear)
			{
				showClue1();
			}
		}
	}
}
