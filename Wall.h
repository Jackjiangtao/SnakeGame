#pragma once
#include "stdfx.h"
#include <graphics.h>
#include "BaseDraw.h"


class Wall :public BaseDraw
{
public:
	Wall();
	

	void Draw();
	void Update();
};
