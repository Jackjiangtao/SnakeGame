#include "GameBase.h"
#include <time.h>


void GameBase::GameRun()
{

	srand(time(NULL)); /*���ݵ�ǰʱ�����á���������ӡ�*/
	initgraph(640, 480); // ��ʼ��EasyX����
	setbkcolor(WHITE);  // ���ñ���ɫΪ��ɫ
	setlinecolor(BLUE);//��������Ϊ��ɫ
	settextcolor(RED);//��������Ϊ��ɫ
	cleardevice();  // �ñ���ɫ�����Ļ


	while (isGameRunning)
	{
		KeyboardControl(); // ������̲���
		UpdateGame();        // ������Ϸ�߼�
		DrawGame();                    // �������л���
		Sleep(30);                // �ȴ�30���룬����֡��
	}

	closegraph(); // ����EasyX����
}
