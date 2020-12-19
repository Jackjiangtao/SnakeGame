#include "GameBase.h"
#include <time.h>


void GameBase::GameRun()
{

	srand(time(NULL)); /*根据当前时间设置“随机数种子”*/
	initgraph(640, 480); // 初始化EasyX环境
	setbkcolor(WHITE);  // 设置背景色为白色
	setlinecolor(BLUE);//设置线条为黑色
	settextcolor(RED);//设置文字为黑色
	cleardevice();  // 用背景色清空屏幕


	while (isGameRunning)
	{
		KeyboardControl(); // 处理键盘操作
		UpdateGame();        // 处理游戏逻辑
		DrawGame();                    // 处理所有绘制
		Sleep(30);                // 等待30毫秒，控制帧率
	}

	closegraph(); // 清理EasyX环境
}
