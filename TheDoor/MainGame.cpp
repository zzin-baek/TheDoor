#include "MainGame.h"

stConsole console;

MainGame::MainGame()
{
	bg = new BackGround;
	ch = new Charactor;
	ss = new StartScreen;

	room1 = new Room1;
	room2 = new Room2;
	inven = new Inventory;
}

MainGame::~MainGame()
{
	delete bg;
	delete ch;
	delete ss;
	delete room1;
	delete room2;
	delete inven;

	if (console.hBuffer[0] != nullptr)
	{
		CloseHandle(console.hBuffer[0]);
	}

	if (console.hBuffer[1] != nullptr)
	{
		CloseHandle(console.hBuffer[1]);
	}

}

void MainGame::init()
{
	init_buffer();
	system("mode con: cols=90 lines=45 | title 더 도어 ");

	console.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	console.nCurBuffer = 0;

	// 콘솔 관련 설정
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo{ 0, };

	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0; // 커서를 보일지 말지 결정(0이면 안보임, 0제외 숫자 값이면 보임)
	cursorInfo.dwSize = 1; // 커서의 크기를 결정 (1~100 사이만 가능)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	GetConsoleScreenBufferInfo(console.hConsole, &consoleInfo);
	consoleInfo.dwSize.X = WIDTH;    // 콘솔의 Width
	consoleInfo.dwSize.Y = HEIGHT;

	// 콘솔의 크기를 다시 계산 (나중에 그림 그릴때 사용)
	console.rtConsole.nWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
	console.rtConsole.nHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top;

	// 콘솔의 첫번째 화면 버퍼 생성
	console.hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(console.hBuffer[0], consoleInfo.dwSize);    // 화면 버퍼 크기 설정
	SetConsoleWindowInfo(console.hBuffer[0], TRUE, &consoleInfo.srWindow); // 콘솔 설정

	// 콘솔의 두번째 화면 버퍼 생성
	console.hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(console.hBuffer[1], consoleInfo.dwSize);
	SetConsoleWindowInfo(console.hBuffer[1], TRUE, &consoleInfo.srWindow);

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
	ClearScreen();
	bg->showBg(1, x, 0);
	ch->showChar_front(1, x);
	//render();
	char chBuf[90*40] = { 0, };
	COORD coord{ 0,0 };
	DWORD dw = 0;

	while (1)
	{
		//render();
		if (_kbhit())
		{
			int key = _getch();

			if (key == 224)
			{
				key = _getch();
				if (key == RIGHT)
				{
					if (ch->getX() > 65)
						continue;
					else if (ch->getX() > 75)
						ch->setXY(ch->getX() + 1, ch->getY());		
					else if (x > 74)
						ch->setXY(ch->getX() + 1, ch->getY());			
					else if (ch->getX() > 30)
						x += 1;
					else
						ch->setXY(ch->getX() + 1, ch->getY());

					ch->setWalk(!ch->getWalk());
					bg->showBg(1, x, 0);
					ch->showChar_front(1, x);

				}
				else if (key == LEFT)
				{
					if (ch->getX() < 0)
						continue;
					else if (ch->getX() > 30)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (x == 0)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (ch->getX() == 30)
						x -= 1;
					else
						ch->setXY(ch->getX() - 1, ch->getY());
					
					ch->setWalk(!ch->getWalk());
					bg->showBg(1, x, 0);
					ch->showChar_back(1, x);
				}
				printf("%d %d", ch->getX(), x);
			}
			else if (key == 32)
			{
				if (x > 5 && x < 13)
				{
					if (room1->getGameClear())
						room1->showClue1();
					else
					{
						room1->showMaze();
						if (room1->miniGame1())
							room1->setGameClear(true);
					}
				}
				else if (x > 32 && x < 39)
					room1->showStatue();

				else if (x > 60 && x < 72)
					room1->showBox();
			}
			else if (key == 27)
			{
				ClearScreen();
				inven->invenUI();
				key = _getch();
				if (key == 27)
				{
					bg->showBg(1, x, 0);
					ch->showChar_front(1, x);
				}
			}
			else if (key == 99) // 다음 스테이지 작업을 위한 임의 치트키
				break;
			/*
			memset(chBuf, 0, sizeof(chBuf));
			int nLen = sprintf_s(chBuf, sizeof(chBuf), "■");
			SetConsoleCursorPosition(console.hBuffer[console.nCurBuffer], coord);
			WriteFile(console.hBuffer[console.nCurBuffer], chBuf, nLen, &dw, NULL);

			ClearScreen();
			BufferFlip();
			Sleep(1);
			*/
		}
	}
}

void MainGame::stageTwo()
{
	int x = 0;
	ch->setXY(15, 25);
	ClearScreen();
	bg->showBg(2, x, 0);
	ch->showChar_front(2, x);
	
	while (1)
	{
		//render();
		if (_kbhit())
		{
			int key = _getch();

			if (key == 224)
			{
				key = _getch();
				if (key == RIGHT)
				{
					if (ch->getX() > 65)
						continue;
					else if (ch->getX() > 75)
						ch->setXY(ch->getX() + 1, ch->getY());
					else if (x > 74)
						ch->setXY(ch->getX() + 1, ch->getY());
					else if (ch->getX() > 30)
						x += 1;
					else
						ch->setXY(ch->getX() + 1, ch->getY());

					ch->setWalk(!ch->getWalk());
					bg->showBg(2, x, 0);
					ch->showChar_front(2, x);

				}
				else if (key == LEFT)
				{
					if (ch->getX() < 0)
						continue;
					else if (ch->getX() > 30)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (x == 0)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (ch->getX() == 30)
						x -= 1;
					else
						ch->setXY(ch->getX() - 1, ch->getY());

					ch->setWalk(!ch->getWalk());
					bg->showBg(2, x, 0);
					ch->showChar_back(2, x);
				}
				printf("%d %d", ch->getX(), x);
			}
			else if (key == 32)
			{
				if (x > 5 && x < 13)
					room2->showClock();
				else if (x > 39 && x < 46)
					room1->showStatue();

				else if (x > 68 && x < 72)
					room2->showRullet();
			}
			else if (key == 27)
			{
				ClearScreen();
				inven->invenUI();
				key = _getch();
				if (key == 27)
				{
					bg->showBg(2, x, 0);
					ch->showChar_front(2, x);
				}
			}
			else if (key == 99) // 다음 스테이지 작업을 위한 임의 치트키
				break;
		}
	}
}

void MainGame::stageThree()
{
	int x = 0;
	ch->setXY(15, 25);
	ClearScreen();
	bg->showBg(3, x, 0);
	ch->showChar_front(3, x);

	while (1)
	{
		//render();
		if (_kbhit())
		{
			int key = _getch();

			if (key == 224)
			{
				key = _getch();
				if (key == RIGHT)
				{
					if (ch->getX() > 65)
						continue;
					else if (ch->getX() > 75)
						ch->setXY(ch->getX() + 1, ch->getY());
					else if (x > 74)
						ch->setXY(ch->getX() + 1, ch->getY());
					else if (ch->getX() > 30)
						x += 1;
					else
						ch->setXY(ch->getX() + 1, ch->getY());

					ch->setWalk(!ch->getWalk());
					bg->showBg(3, x, 0);
					ch->showChar_front(3, x);

				}
				else if (key == LEFT)
				{
					if (ch->getX() < 0)
						continue;
					else if (ch->getX() > 30)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (x == 0)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (ch->getX() == 30)
						x -= 1;
					else
						ch->setXY(ch->getX() - 1, ch->getY());

					ch->setWalk(!ch->getWalk());
					bg->showBg(3, x, 0);
					ch->showChar_back(3, x);
				}
				printf("%d %d", ch->getX(), x);
			}
			else if (key == 32)
			{
				if (ch->getX() > 34 && ch->getX() < 40)
				{
					if (room1->getGameClear())
						room1->showClue1();
					else
					{
						room1->showMaze();
						if (room1->miniGame1())
							room1->setGameClear(true);
					}
				}
				else if (ch->getX() == 55)
					room1->showStatue();

				else if (ch->getX() == 65)
					room1->showBox();
			}
			else if (key == 27)
			{
				ClearScreen();
				inven->invenUI();
				key = _getch();
				if (key == 27)
				{
					bg->showBg(2, x, 0);
					ch->showChar_front(2, x);
				}
			}
			else if (key == 99) // 다음 스테이지 작업을 위한 임의 치트키
				break;
		}
	}
}

void MainGame::gameStart()
{
	stageOne();
	stageTwo();
	stageThree();
}

void MainGame::ClearScreen()
{
	COORD pos{ 0, };
	DWORD dwWritten = 0;
	unsigned size = console.rtConsole.nWidth * console.rtConsole.nHeight;

	// 콘솔 화면 전체를 띄어쓰기를 넣어 빈 화면처럼 만듭니다.
	FillConsoleOutputCharacter(console.hConsole, ' ', size, pos, &dwWritten);
	SetConsoleCursorPosition(console.hConsole, pos);
}

void MainGame::BufferFlip()
{
	// 화면 버퍼 설정
	SetConsoleActiveScreenBuffer(console.hBuffer[console.nCurBuffer]);
	// 화면 버퍼 인덱스를 교체
	console.nCurBuffer = console.nCurBuffer ? 0 : 1;
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