#include "stdfx.h"
#include "Game.h"
#include "Food.h"
#include "Snake.h"
#include "UI.h"
#include "Wall.h"
#include <time.h>
#include <iostream>

Game::Game()
{
	InitGame();
}



void Game::InitGame()
{
	ui = new UI();
	wall = new Wall();
	snake1 = new Snake();
	snake2 = new Snake();

	food = new Food();
	ui->SetSnake(snake1);

	m_Draw.push_back(dynamic_cast<BaseDraw*>(ui));
	m_Draw.push_back(dynamic_cast<BaseDraw*>(wall));
	m_Draw.push_back(dynamic_cast<BaseDraw*>(snake1));
	m_Draw.push_back(dynamic_cast<BaseDraw*>(snake2));
	m_Draw.push_back(dynamic_cast<BaseDraw*>(food));

	BaseMove* move = dynamic_cast<BaseMove*>(snake1);
	m_Move.push_back(move);
	BaseMove* move1 = dynamic_cast<BaseMove*>(snake2);
	m_Move.push_back(move1);
	//isGameRunning = true;
}

bool Game::IsKeyDown(int key)
{

	return false;
}

void Game::DrawGame()
{
	cleardevice();
	for (auto it :m_Draw)
	{
		it->Draw();
	}
}

void Game::KeyboardControl()
{
	if (_kbhit())
	{//如果有按键按下，则_kbhit()函数返回真
		char ch = _getch();//使用_getch()函数获取按下的键值
		
		switch (ch)
		{
		case VK_ESCAPE:
		{
			isGameRunning = false;
			return;
		}break;

		case 'a':
		{
			for (auto it : m_Move)
			{
				it->Move(Direction::Left);
			}
		}break;

		case 'd':
		{
			for (auto it : m_Move)
			{
				it->Move(Direction::Right);
			}
		}break;

		case 'w':
		{
			for (auto it : m_Move)
			{
				it->Move(Direction::Up);
			}
		}break;
		case 's':
		{
			for (auto it : m_Move)
			{
				it->Move(Direction::Down);
			}
		}break;

		default:
			break;
		}

		std::cout << ch << std::endl;
	}
}
void Game::UpdateGame()
{
	
	for (auto it : m_Draw)
	{
		it->Update();
	}

	snake1->EatFood(food);

	snake2->EatFood(food);

	IsOver();
}

void Game::IsOver()
{
	auto snakeBody = snake1->GetBody();
	for (auto it =snakeBody.begin();it!=snakeBody.end();it++)
	{
		//撞墙
		if (it->x <0 || it->x >WALL_END ||it->y<0 ||it->y>SCREEN_WIDTH)
		{
			isGameRunning = false;
		}

		//撞自己
		for (auto it2 = snakeBody.begin(); it2 != snakeBody.end(); it2++)
		{
			if (it2!=it && (it->x ==it2->x && it->y ==it2->y))
				isGameRunning = false;
		}

	}
}
