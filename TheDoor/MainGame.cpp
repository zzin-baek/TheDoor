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
	system("mode con: cols=90 lines=45 | title �� ���� ");

	console.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	console.nCurBuffer = 0;

	// �ܼ� ���� ����
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo{ 0, };

	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0; // Ŀ���� ������ ���� ����(0�̸� �Ⱥ���, 0���� ���� ���̸� ����)
	cursorInfo.dwSize = 1; // Ŀ���� ũ�⸦ ���� (1~100 ���̸� ����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	GetConsoleScreenBufferInfo(console.hConsole, &consoleInfo);
	consoleInfo.dwSize.X = WIDTH;    // �ܼ��� Width
	consoleInfo.dwSize.Y = HEIGHT;

	// �ܼ��� ũ�⸦ �ٽ� ��� (���߿� �׸� �׸��� ���)
	console.rtConsole.nWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
	console.rtConsole.nHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top;

	// �ܼ��� ù��° ȭ�� ���� ����
	console.hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(console.hBuffer[0], consoleInfo.dwSize);    // ȭ�� ���� ũ�� ����
	SetConsoleWindowInfo(console.hBuffer[0], TRUE, &consoleInfo.srWindow); // �ܼ� ����

	// �ܼ��� �ι�° ȭ�� ���� ����
	console.hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(console.hBuffer[1], consoleInfo.dwSize);
	SetConsoleWindowInfo(console.hBuffer[1], TRUE, &consoleInfo.srWindow);

}

int MainGame::mainMenu()
{
	ss->showStartScreen();
	gotoxy(40, 35);
	printf("���� ����");
	gotoxy(40, 37);
	printf("������");
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

			// �������� ���� ������ ó�� �����ϱ�(������ ����,,222)
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

	// �ܼ� ȭ�� ��ü�� ���⸦ �־� �� ȭ��ó�� ����ϴ�.
	FillConsoleOutputCharacter(console.hConsole, ' ', size, pos, &dwWritten);
	SetConsoleCursorPosition(console.hConsole, pos);
}

void MainGame::BufferFlip()
{
	// ȭ�� ���� ����
	SetConsoleActiveScreenBuffer(console.hBuffer[console.nCurBuffer]);
	// ȭ�� ���� �ε����� ��ü
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