#include "MainGame.h"

MainGame::MainGame()
{
	bg = new BackGround;
	ch = new Charactor;
	ss = new gameScreen;

	room1 = new Room1;
	room2 = new Room2;
	room3 = new Room3;

	inven = new Inventory;
	item = new Item;
}

MainGame::~MainGame()
{
	delete bg;
	delete ch;
	delete ss;
	delete room1;
	delete room2;
	delete room3;
	delete inven;
	delete item;
}

// ���� ������ ���� �ܼ� â ũ�� ������ Ŀ�� �Ⱥ��� ����
void MainGame::init()
{
	system("mode con: cols=90 lines=45 | title �� ���� ");

	// �ܼ� ���� ����
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo{ 0, };

	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0; // Ŀ���� ������ ���� ����(0�̸� �Ⱥ���, 0���� ���� ���̸� ����)
	cursorInfo.dwSize = 1; // Ŀ���� ũ�⸦ ���� (1~100 ���̸� ����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// ����ȭ�� ���
int MainGame::mainMenu()
{
	PlaySound(TEXT("./BGM/����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	ss->showStartScreen();

	gotoxy(40, 35);
	printf("���� ����");
	gotoxy(40, 37);
	printf("������");
	gotoxy(38, 35);
	printf(">");

	int cursor = 35;

	// ������ �������� �������� ����
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
			PlaySound(NULL, 0, 0);
			return cursor;
		}
	}
	PlaySound(NULL, 0, 0);
	return 0;
}

void MainGame::mainScript()
{
	system("cls");
	ss->printIntro();
}

// ù ��° ��������
void MainGame::stageOne()
{
	PlaySound(TEXT("./BGM/��1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int x = 0;
	// �ɾ�� ��� �ӵ� ������ ���� ����
	int walkSpeed = 0;
	// ���ڰ� ���ȴ��� Ȯ���ϱ� ���� ����
	int unlock = false;

	system("cls");
	ch->setXY(15, 25);
	bg->showBg(1, x);
	ch->showChar_front(1, x);

	while (1)
	{
		if (_kbhit())
		{
			int key = _getch();

			// ����Ű(��, ��) �Է� �޾��� ��
			if (key == 224)
			{
				walkSpeed++;
				key = _getch();
				// ������(��)���� �� �� ������
				if (key == RIGHT)
				{
					// ĳ������ ��ġ�� ���� ����� �������� ĳ���͸� �������� ����
					if (ch->getX() > 65)
						continue;
					else if (ch->getX() > 75)
						ch->setXY(ch->getX() + 2, ch->getY());		
					else if (x > 74)
						ch->setXY(ch->getX() + 2, ch->getY());			
					else if (ch->getX() > 30)
						x += 1;
					else
						ch->setXY(ch->getX() + 2, ch->getY());

					// �ȴ� ��� ����
					if (walkSpeed % 5 == 0)
						ch->setWalk(!ch->getWalk());
					
					bg->showBg(1, x);
					ch->showChar_front(1, x);
				}
				// ����(��)�� �� �� ������
				else if (key == LEFT)
				{
					if (ch->getX() < 1)
						continue;
					else if (ch->getX() > 30)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (x == 0)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (ch->getX() == 30)
						x -= 1;
					else
						ch->setXY(ch->getX() - 1, ch->getY());
					
					if (walkSpeed % 5 == 0)
						ch->setWalk(!ch->getWalk());

					bg->showBg(1, x);
					ch->showChar_back(1, x);
				}
			}
			// ��ȣ�ۿ� Ű�� ������ �� ó��
			else if (key == 32)
			{
				if (x > 5 && x < 13)
				{
					// �̷θ� Ż�� ���� ���� ������ ��
					if (room1->getGameClear())
						room1->showClue();
					else
					{
						room1->showMaze();
						if (room1->playMaze())
						{
							room1->setGameClear(true);
							message("�׸��� �ٲ���١�");
						}
					}
				}
				else if (x > 32 && x < 39)
				{
					room1->showStatue();
					message("������ �ǰ� �帥�١�");
				}

				else if (x > 60 && x < 72)
				{
					if (unlock)
						message("��");
					else
					{
						room1->showBox();
						message("_ _ _ _");
						gotoxy(72, 36);
						printf("HINT : ����");

						// ��й�ȣ�� ������ �� ���
						if (room1->insertPassword())
						{
							message("�ڹ��谡 ���ȴ�");
							Sleep(2000);
							message("���踦 �����");
							Sleep(2000);
							// ���踦 �κ��丮�� �߰�
							inven->addItem(item->getItem()[0]);
							inven->setHasKey(true);
							unlock = true;

							bg->showBg(1, x);
							ch->showChar_front(1, x);
						}
						else
						{
							message("�ƹ� �ϵ� �Ͼ�� �ʾҴ١�");
							Sleep(2000);

							bg->showBg(1, x);
							ch->showChar_front(1, x);
						}
					}
				}
				else if (ch->getX() > 60 && ch->getX() < 65)
				{
					// Ű�� ���� ���ο� ���� �ൿ
					if (inven->getHasKey())
					{
						message("���踦 ����Ͽ� ���� ����? (Y: �� / N: �ƴϿ�)");
						while (!_kbhit())
						{
							key = _getch();
							if (key == 89 || key == 121)
							{
								message("���踦 ����Ͽ� ���� ������");
								PlaySound(NULL, 0, 0);
								PlaySound(TEXT("./BGM/��.wav"), NULL, SND_ASYNC);
								Sleep(1000);

								// �������� ��� (�κ��丮���� ������)
								inven->useItem();
								inven->setHasKey(false);
			
								return;
							}
							else if (key == 78 || key == 110)
							{
								bg->showBg(1, x);
								ch->showChar_front(1, x);
								break;
							}
						}
					}
					else
					{
						message("���谡 �ʿ��� �� ���١�");
						Sleep(2000);

						bg->showBg(1, x);
						ch->showChar_front(1, x);
					}
				}
			}
			else if (key == 27)
			{
				// �κ��丮 â ���
				inven->invenUI();
				// �κ��丮�� �������� ���� ���
				if (inven->getSize() > 0)
				{
					// �����۰� �������� ������ ���
					item->showItem(inven->getItemNum().itemNum);
					gotoxy(30, 7);
					TextColor(15, 0);
					printf("<%s>", inven->getItemNum().itemName.c_str());
					gotoxy(10, 31);
					printf("%s", inven->getItemNum().feature.c_str());
				}
				key = _getch();
				if (key == 27)
				{
					bg->showBg(1, x);
					ch->showChar_front(1, x);
				}
			}
		}
	}
}
// �� ��° ��������
void MainGame::stageTwo()
{
	PlaySound(TEXT("./BGM/��2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	int x = 0;
	int walkSpeed = 0;
	// �귿�� Ŭ���� �ߴ����� ���� ����
	bool clear = false;
	
	system("cls");
	ch->setXY(15, 25);
	bg->showBg(2, x);
	ch->showChar_front(2, x);
	
	while (1)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key == 224)
			{
				walkSpeed++;
				key = _getch();
				if (key == RIGHT)
				{
					if (ch->getX() > 65)
						continue;
					else if (ch->getX() > 75)
						ch->setXY(ch->getX() + 2, ch->getY());
					else if (x > 74)
						ch->setXY(ch->getX() + 2, ch->getY());
					else if (ch->getX() > 30)
						x += 1;
					else
						ch->setXY(ch->getX() + 2, ch->getY());

					if (walkSpeed % 5 == 0)
						ch->setWalk(!ch->getWalk());

					bg->showBg(2, x);
					ch->showChar_front(2, x);

				}
				else if (key == LEFT)
				{
					if (ch->getX() < 1)
						continue;
					else if (ch->getX() > 30)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (x == 0)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (ch->getX() == 30)
						x -= 1;
					else
						ch->setXY(ch->getX() - 1, ch->getY());

					if (walkSpeed % 5 == 0)
						ch->setWalk(!ch->getWalk());

					bg->showBg(2, x);
					ch->showChar_back(2, x);
				}
			}
			// ��ȣ�ۿ� Ű �Է� ��
			else if (key == 32)
			{
				if (x > 11 && x < 15)
				{
					room2->showClock();
					message("�ð谡 12�� 25���� ����Ű�� �ִ١�");
				}
				else if (x > 39 && x < 46)
					room2->showCandle();
				else if (x > 68 && x < 72)
				{
					room2->showRullet();
					if (clear)
					{
						room2->rulletAnswer();
						message("��");
					}
					else
					{
						if (room2->playRullet())
						{
							message("�귿���� ���谡 �������١�");
							clear = true;
							Sleep(2000);
							inven->addItem(item->getItem()[1]);
							inven->setHasKey(true);
							bg->showBg(2, x);
							ch->showChar_front(2, x);
							continue;
						}
						else
						{
							message("�ƹ� �ϵ� �Ͼ�� �ʾҴ١�");
							Sleep(2000);
							bg->showBg(2, x);
							ch->showChar_front(2, x);
						}
					}
				}
				else if (ch->getX() > 60 && ch->getX() < 65)
				{
					// ���� ���� ���ο� ���� �ൿ
					if (inven->getHasKey())
					{
						message("���踦 ����Ͽ� ���� ����? (Y: �� / N: �ƴϿ�)");
						while (!_kbhit())
						{
							key = _getch();
							if (key == 89 || key == 121)
							{
								message("���踦 ����Ͽ� ���� ������");

								inven->useItem();
								inven->setHasKey(false);

								PlaySound(NULL, 0, 0);
								PlaySound(TEXT("./BGM/��.wav"), NULL, SND_ASYNC);
								Sleep(1000);
								return;
							}
							else if (key == 78 || key == 110)
							{
								bg->showBg(2, x);
								ch->showChar_front(2, x);
								break;
							}
						}
					}
					else
					{
						message("���谡 �ʿ��� �� ���١�");
						Sleep(2000);
						bg->showBg(2, x);
						ch->showChar_front(2, x);
					}
				}
			}
			else if (key == 27)
			{
				inven->invenUI();
				if (inven->getSize() > 0)
				{
					item->showItem(inven->getItemNum().itemNum);					
					gotoxy(30, 7);
					TextColor(15, 0);
					printf("<%s>", inven->getItemNum().itemName.c_str());
					gotoxy(10, 31);
					printf("%s", inven->getItemNum().feature.c_str());
				}
				key = _getch();
				if (key == 27)
				{
					bg->showBg(2, x);
					ch->showChar_front(2, x);
				}
			}
		}
	}
}
// �� ��° ��������
void MainGame::stageThree()
{
	PlaySound(TEXT("./BGM/��3.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	int x = 0;
	int walkSpeed = 0;
	// �����̵� ���� Ŭ���� ����
	bool gameClear = false;
	// �ݰ� ���� ����
	bool boxOpen = false;

	system("cls");
	ch->setXY(15, 25);
	bg->showBg(3, x);
	ch->showChar_front(3, x);

	while (1)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key == 224)
			{
				walkSpeed++;
				key = _getch();
				if (key == RIGHT)
				{
					if (ch->getX() > 65)
						continue;
					else if (x > 54)
						ch->setXY(ch->getX() + 2, ch->getY());
					else if (ch->getX() > 30)
						x += 1;
					else
						ch->setXY(ch->getX() + 2, ch->getY());

					if (walkSpeed % 5 == 0)
						ch->setWalk(!ch->getWalk());

					bg->showBg(3, x);
					ch->showChar_front(3, x);
				}
				else if (key == LEFT)
				{
					if (ch->getX() < 1)
						continue;
					else if (ch->getX() > 30)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (x == 0)
						ch->setXY(ch->getX() - 1, ch->getY());
					else if (ch->getX() == 30)
						x -= 1;
					else
						ch->setXY(ch->getX() - 1, ch->getY());

					if (walkSpeed % 5 == 0)
						ch->setWalk(!ch->getWalk());

					bg->showBg(3, x);
					ch->showChar_back(3, x);
				}
			}
			else if (key == 32)
			{
				if (x > 12 && x < 18)
				{
					room3->showArcade();
					if (gameClear)
					{
						room3->showClear();
						message("��");
					}
					else
					{
						if (room3->playArcade())
						{
							message("���ӱ⿡�� ���谡 �������١�");
							// �κ��丮�� ���� �߰�
							inven->addItem(item->getItem()[2]);
							inven->setHasKey(true);
							Sleep(2000);

							gameClear = true;

							bg->showBg(3, x);
							ch->showChar_front(3, x);
						}
						else
						{
							bg->showBg(3, x);
							ch->showChar_front(3, x);
						}
					}
				}
				else if (x > 42 && x < 50)
				{
					if (boxOpen)
					{
						room3->showNote();
						if (_getch() == 27)
						{
							bg->showBg(3, x);
							ch->showChar_front(3, x);
						}
					}
					else
					{
						room3->showLocker();
						if (inven->getHasKey())
						{
							message("���踦 ����Ͽ� ���ڸ� ������");
							// �κ��丮���� ���� ����
							inven->useItem();
							inven->setHasKey(false);
							Sleep(2000);
							
							room3->showNote();
							message("��Ű� ������ �߰��ߴ�");
							// �κ��丮�� ��� �߰�
							inven->addItem(item->getItem()[3]);
							boxOpen = true;
							continue;
						}
						else
						{
							message("���谡 �ʿ��� �� ���١�");
							Sleep(2000);

							bg->showBg(3, x);
							ch->showChar_front(3, x);
						}
					}
				}
				else if (ch->getX() > 60 && ch->getX() < 64)
				{
					message("_ _ _ _ _");
					gotoxy(72, 36);
					printf("HINT : ����");

					// ��ȣ�� ���� ���ο� ���� �ൿ
					if (room3->insertPassword())
					{
						message("���� ���ȴ�");
						PlaySound(NULL, 0, 0);
						PlaySound(TEXT("./BGM/��.wav"), NULL, SND_ASYNC);
						Sleep(2000);
						
						return;
					}
					else
					{
						message("�ƹ� �ϵ� �Ͼ�� �ʾҴ١�");
						Sleep(2000);

						bg->showBg(3, x);
						ch->showChar_front(3, x);
					}
				}
			}
			else if (key == 27)
			{
				inven->invenUI();
				if (inven->getSize() > 0)
				{
					item->showItem(inven->getItemNum().itemNum);
					gotoxy(30, 7);
					TextColor(15, 0);
					printf("<%s>", inven->getItemNum().itemName.c_str());
					gotoxy(10, 31);
					printf("%s", inven->getItemNum().feature.c_str());
				}
				key = _getch();
				if (key == 27)
				{
					bg->showBg(3, x);
					ch->showChar_front(3, x);
				}
			}
		}
	}
}
// �Է¹��� ����� �Բ� �޽��� â�� ���
void MainGame::message(std::string str)
{
	for (int i = 0; i < 8; i++)
	{
		gotoxy(6, 30 + i);
		TextColor(15, 0);
		printf("%s", msg[i]);
	}
	gotoxy(10, 33);
	printf("%s", str.c_str());
}

// �������� ���� ����
void MainGame::gameStart()
{
	stageOne();
	stageTwo();
	stageThree();

	ending();
}

// ���� �����̼� �� ȭ�� ���
void MainGame::ending()
{
	system("cls");
	ss->printOutro();
	PlaySound(TEXT("./BGM/����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	ss->showEndingScreen();

	// �ƹ� Ű�� �Է¹����� ����
	while (!_kbhit())
	{
		int key = _getch();
		if (key > 0)
			break;
	}

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