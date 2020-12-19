#pragma once
#include "stdfx.h"
#include <vector>
#include "BaseDraw.h"
#include "BaseMove.h"
#include "GameBase.h"

class Snake;
class Food;
class UI;
class Wall;


class Game :public GameBase
{
public:
	Game();

private:
	void InitGame();

	bool IsKeyDown(int key);


	void DrawGame();
	
	
	void KeyboardControl();
	

	void UpdateGame();
	
	void IsOver();
private:

	std::vector<BaseDraw*> m_Draw;   //ª≠∞Âπ€≤Ï’ﬂ

	std::vector<BaseMove*> m_Move;
	
	Snake* snake1;
	Snake* snake2;
	Food* food;
	UI* ui;
	Wall* wall;
};

