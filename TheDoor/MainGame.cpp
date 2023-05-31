#include "MainGame.h"

stConsole console;

MainGame::MainGame()
{
	bg = new BackGround;
	ch = new Charactor;
	ss = new StartScreen;

	mg = new MiniGames;
}

MainGame::~MainGame()
{
	delete bg;
	delete ch;
	delete ss;
	delete mg;

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
	ch->showChar_front(x);

	while (1)
	{
		if (_kbhit())
		{
			int key = _getch();

			// 벽쪽으로 갈때 움직임 처리 구현하기(내일의 내가,,222)
			if (key == 224)
			{
				key = _getch();
				if (key == RIGHT)
				{
					if (ch->getX() > 105)
						continue;
					else if (ch->getX() > 90)
						ch->setXY(ch->getX() + 1, ch->getY());
					else if (ch->getX() > 30)
					{
						ch->setXY(ch->getX() + 1, ch->getY());
						x += 1;
					}
					else
						ch->setXY(ch->getX() + 1, ch->getY());

					bg->showBg(1, x, 0);
					ch->showChar_front(x);

				}
				else if (key == LEFT)
				{
					if (ch->getX() < 0)
						continue;
					else if (ch->getX() < 32)
						ch->setXY(ch->getX() - 1, ch->getY());
					else
					{
						ch->setXY(ch->getX() - 1, ch->getY());
						x -= 1;
					}
					bg->showBg(1, x, 0);
					ch->showChar_back(x);
				}

				printf("%d", ch->getX());
			}
			else if (key == 32)
			{
				if (ch->getX() > 34 && ch->getX() < 40)
				{
					mg->miniGame1();
				}
				else if (ch->getX() == 55)
					mg->showStatue();
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