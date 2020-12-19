#pragma once
#include "stdfx.h"
#include "BaseDraw.h"
#include <graphics.h>

class Food :public BaseDraw
{
public:
	Food();
	
	void InitFood();
	
	void Draw();
	void Update();
	POINT GetPoint();
private:
	POINT point;
};

