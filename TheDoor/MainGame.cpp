#include "MainGame.h"

MainGame::MainGame()
{
	bg = new BackGround;
	ch = new Charactor;
	ss = new StartScreen;
}

MainGame::~MainGame()
{
	delete bg;
	delete ch;
	delete ss;

}

void MainGame::init()
{
	system("mode con: cols=90 lines=45 | title 더 도어 ");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

int MainGame::mainMenu()
{
	ss->showStartScreen();
	gotoxy(40, 35);
	printf("게임 시작");
	gotoxy(40, 37);
	printf("나가기");
	gotoxy(38, 35);
	printf(">");

	int cursor = 35;

	while (!_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			if (key == UP)
			{
				gotoxy(38, 37);
				printf(" ");
				gotoxy(38, 35);
				printf(">");
				cursor = 35;
			}
			else if (key == DOWN)
			{
				gotoxy(38, 35);
				printf(" ");
				gotoxy(38, 37);
				printf(">");
				cursor = 37;
			}
		}
		else if (key == 13)
		{
			return cursor;
		}
	}


}

void MainGame::stageOne()
{
	int x = 0;
	system("cls");
	bg->showBg(1, x, 0);
	ch->showChar();
	while (!_kbhit())
	{
		int key = _getch();
		bg->showBg(1, x, 0);
		ch->showChar();
		// 벽쪽으로 갈때 움직임 처리 구현하기(내일의 내가,,)
		if (key == 224)
		{
			key = _getch();
			if (key == RIGHT)
			{
				ch->setXY(ch->getX() + 2, ch->getY());
				if (ch->getX() > 30)
					x += 1;
			}
			else if (key == LEFT)
			{
				if (ch->getX() < 1)
					continue;
				else
					ch->setXY(ch->getX() - 2, ch->getY());
			}
		}
		

	}
}

void MainGame::stageTwo()
{
}

void MainGame::stageThree()
{
}

void MainGame::gameStart()
{
	stageOne();
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