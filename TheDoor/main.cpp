#include "MainGame.h"
#include "header.h"

void main()
{
	int start = 0;
	MainGame* mg = new MainGame;

	// ������ ���� �ʱ�ȭ
	mg->init();
	start = mg->mainMenu();
	if (start == 35)
	{
		// ���� ������ ������ ���� ����
		mg->mainScript();
		mg->gameStart();

	}
	else // �����⸦ �����ϸ� ����
		exit(0);

	delete mg;
}