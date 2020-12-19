#include "Food.h"
#include "stdfx.h"
Food::Food()
{
	InitFood();
}

void Food::InitFood()
{
	point.x = rand() % (SCREEN_WIDTH/WIDTH);
	point.y = rand() % ((WALL_END-WALL_BEGIN)/WIDTH);

}

void Food::Draw()
{
	auto _x = point.x;
	auto _y = point.y;
	circle(_x * WIDTH + 160+WIDTH/2 , _y * WIDTH+WIDTH/2 , WIDTH/2);
}

void Food::Update()
{

}

POINT Food::GetPoint()
{
	return point;
}
