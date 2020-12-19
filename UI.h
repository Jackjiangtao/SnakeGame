#pragma once
#include "stdfx.h"
#include <graphics.h>
#include <conio.h>

#include "BaseDraw.h"

class Snake;
class UI :public BaseDraw
{
public:
	UI();
public:
	void Draw();

	void SetSnake(const Snake* temp);
	const Snake* s;
};
