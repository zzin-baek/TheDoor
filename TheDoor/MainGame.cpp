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

// 게임 시작을 위한 콘솔 창 크기 설정과 커서 안보임 설정
void MainGame::init()
{
	system("mode con: cols=90 lines=45 | title 더 도어 ");

	// 콘솔 관련 설정
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo{ 0, };

	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0; // 커서를 보일지 말지 결정(0이면 안보임, 0제외 숫자 값이면 보임)
	cursorInfo.dwSize = 1; // 커서의 크기를 결정 (1~100 사이만 가능)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// 시작화면 출력
int MainGame::mainMenu()
{
	PlaySound(TEXT("./BGM/시작.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	ss->showStartScreen();

	gotoxy(40, 35);
	printf("게임 시작");
	gotoxy(40, 37);
	printf("나가기");
	gotoxy(38, 35);
	printf(">");

	int cursor = 35;

	// 게임을 시작할지 종료할지 선택
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

// 첫 번째 스테이지
void MainGame::stageOne()
{
	PlaySound(TEXT("./BGM/방1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int x = 0;
	// 걸어가는 모션 속도 조절을 위한 변수
	int walkSpeed = 0;
	// 상자가 열렸는지 확인하기 위한 변수
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

			// 방향키(좌, 우) 입력 받았을 때
			if (key == 224)
			{
				walkSpeed++;
				key = _getch();
				// 오른쪽(앞)으로 갈 때 움직임
				if (key == RIGHT)
				{
					// 캐릭터의 위치에 따라 배경을 움직일지 캐릭터를 움직일지 선택
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

					// 걷는 모션 변경
					if (walkSpeed % 5 == 0)
						ch->setWalk(!ch->getWalk());
					
					bg->showBg(1, x);
					ch->showChar_front(1, x);
				}
				// 왼쪽(뒤)로 갈 때 움직임
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
			// 상호작용 키를 눌렀을 때 처리
			else if (key == 32)
			{
				if (x > 5 && x < 13)
				{
					// 미로를 탈출 했을 때와 안했을 때
					if (room1->getGameClear())
						room1->showClue();
					else
					{
						room1->showMaze();
						if (room1->playMaze())
						{
							room1->setGameClear(true);
							message("그림이 바뀌었다…");
						}
					}
				}
				else if (x > 32 && x < 39)
				{
					room1->showStatue();
					message("눈에서 피가 흐른다…");
				}

				else if (x > 60 && x < 72)
				{
					if (unlock)
						message("…");
					else
					{
						room1->showBox();
						message("_ _ _ _");
						gotoxy(72, 36);
						printf("HINT : 숫자");

						// 비밀번호를 맞췄을 때 출력
						if (room1->insertPassword())
						{
							message("자물쇠가 열렸다");
							Sleep(2000);
							message("열쇠를 얻었다");
							Sleep(2000);
							// 열쇠를 인벤토리에 추가
							inven->addItem(item->getItem()[0]);
							inven->setHasKey(true);
							unlock = true;

							bg->showBg(1, x);
							ch->showChar_front(1, x);
						}
						else
						{
							message("아무 일도 일어나지 않았다…");
							Sleep(2000);

							bg->showBg(1, x);
							ch->showChar_front(1, x);
						}
					}
				}
				else if (ch->getX() > 60 && ch->getX() < 65)
				{
					// 키의 소지 여부에 따른 행동
					if (inven->getHasKey())
					{
						message("열쇠를 사용하여 문을 열까? (Y: 예 / N: 아니오)");
						while (!_kbhit())
						{
							key = _getch();
							if (key == 89 || key == 121)
							{
								message("열쇠를 사용하여 문을 열었다");
								PlaySound(NULL, 0, 0);
								PlaySound(TEXT("./BGM/문.wav"), NULL, SND_ASYNC);
								Sleep(1000);

								// 아이템을 사용 (인벤토리에서 빠진다)
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
						message("열쇠가 필요한 것 같다…");
						Sleep(2000);

						bg->showBg(1, x);
						ch->showChar_front(1, x);
					}
				}
			}
			else if (key == 27)
			{
				// 인벤토리 창 출력
				inven->invenUI();
				// 인벤토리에 아이템이 있을 경우
				if (inven->getSize() > 0)
				{
					// 아이템과 아이템의 정보를 출력
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
// 두 번째 스테이지
void MainGame::stageTwo()
{
	PlaySound(TEXT("./BGM/방2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	int x = 0;
	int walkSpeed = 0;
	// 룰렛을 클리어 했는지에 대한 여부
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
			// 상호작용 키 입력 시
			else if (key == 32)
			{
				if (x > 11 && x < 15)
				{
					room2->showClock();
					message("시계가 12시 25분을 가리키고 있다…");
				}
				else if (x > 39 && x < 46)
					room2->showCandle();
				else if (x > 68 && x < 72)
				{
					room2->showRullet();
					if (clear)
					{
						room2->rulletAnswer();
						message("…");
					}
					else
					{
						if (room2->playRullet())
						{
							message("룰렛에서 열쇠가 떨어졌다…");
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
							message("아무 일도 일어나지 않았다…");
							Sleep(2000);
							bg->showBg(2, x);
							ch->showChar_front(2, x);
						}
					}
				}
				else if (ch->getX() > 60 && ch->getX() < 65)
				{
					// 열쇠 소지 여부에 따른 행동
					if (inven->getHasKey())
					{
						message("열쇠를 사용하여 문을 열까? (Y: 예 / N: 아니오)");
						while (!_kbhit())
						{
							key = _getch();
							if (key == 89 || key == 121)
							{
								message("열쇠를 사용하여 문을 열었다");

								inven->useItem();
								inven->setHasKey(false);

								PlaySound(NULL, 0, 0);
								PlaySound(TEXT("./BGM/문.wav"), NULL, SND_ASYNC);
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
						message("열쇠가 필요한 것 같다…");
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
// 세 번째 스테이지
void MainGame::stageThree()
{
	PlaySound(TEXT("./BGM/방3.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	int x = 0;
	int walkSpeed = 0;
	// 아케이드 게임 클리어 여부
	bool gameClear = false;
	// 금고 오픈 여부
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
						message("…");
					}
					else
					{
						if (room3->playArcade())
						{
							message("게임기에서 열쇠가 떨어졌다…");
							// 인벤토리에 열쇠 추가
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
							message("열쇠를 사용하여 상자를 열었다");
							// 인벤토리에서 열쇠 삭제
							inven->useItem();
							inven->setHasKey(false);
							Sleep(2000);
							
							room3->showNote();
							message("백신과 쪽지를 발견했다");
							// 인벤토리에 백신 추가
							inven->addItem(item->getItem()[3]);
							boxOpen = true;
							continue;
						}
						else
						{
							message("열쇠가 필요할 것 같다…");
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
					printf("HINT : 영어");

					// 암호의 정답 여부에 따른 행동
					if (room3->insertPassword())
					{
						message("문이 열렸다");
						PlaySound(NULL, 0, 0);
						PlaySound(TEXT("./BGM/문.wav"), NULL, SND_ASYNC);
						Sleep(2000);
						
						return;
					}
					else
					{
						message("아무 일도 일어나지 않았다…");
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
// 입력받은 문장과 함께 메시지 창을 출력
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

// 본격적인 게임 시작
void MainGame::gameStart()
{
	stageOne();
	stageTwo();
	stageThree();

	ending();
}

// 엔딩 나레이션 및 화면 출력
void MainGame::ending()
{
	system("cls");
	ss->printOutro();
	PlaySound(TEXT("./BGM/엔딩.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	ss->showEndingScreen();

	// 아무 키나 입력받으면 종료
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