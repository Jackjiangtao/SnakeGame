#include "stdfx.h"
#include "UI.h"
#include "Snake.h"
#include <string>
UI::UI()
{

}

void UI::Draw()
{
	RECT scoreRect = { 10, 10, 140, 50 };
	drawtext(_T("分数"), &scoreRect, DT_CENTER);

	RECT numRect = { 10,120 , 140, 290 };

	if (s)
	{
		auto length =s->GetBody().size();

		auto wstr = std::to_wstring(length);
		drawtext(wstr.c_str(), &numRect, DT_CENTER);
	}
	

	RECT levelRect = { 10, 240, 140, 290 };
	drawtext(_T("难度"), &levelRect, DT_CENTER);
}

void UI::SetSnake(const Snake* temp)
{
	s = temp;
}
