#pragma once
#include <graphics.h>

class GameBase
{
public:
	GameBase()
	{
		isGameRunning = true;
	}
public:
	void GameRun();

protected:
	virtual bool IsKeyDown(int key) =0;


	virtual void DrawGame() =0;


	virtual void KeyboardControl()=0;


	virtual void UpdateGame() =0;

public:
	bool isGameRunning;
};

