#include "MainGame.h"
#include "header.h"

void main()
{
	int start = 0;
	MainGame* mg = new MainGame;

	// 게임을 위한 초기화
	mg->init();
	start = mg->mainMenu();
	if (start == 35)
	{
		// 게임 시작을 누르면 게임 시작
		mg->mainScript();
		mg->gameStart();

	}
	else // 나가기를 선택하면 종료
		exit(0);

	delete mg;
}