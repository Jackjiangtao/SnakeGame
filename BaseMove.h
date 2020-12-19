#pragma once
#include "stdfx.h"

class BaseMove
{
public:
	BaseMove()
	{

	}
	virtual void Move(Direction dir) = 0;
};

