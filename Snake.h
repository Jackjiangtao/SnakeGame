#pragma once
#include "stdfx.h"
#include <graphics.h>
#include <list>

#include "BaseDraw.h"
#include "BaseMove.h"

class Food;

class Snake :public BaseDraw,public BaseMove
{
public:
	Snake();
	
public:
	std::list<POINT> GetBody() const;

	void Draw();
	
	void InitSnake();

	void Update();

	void Move(Direction _dir);

	void EatFood(Food *Food);
private:
	std::list<POINT> _bodyList;

	Direction _dir;
};

