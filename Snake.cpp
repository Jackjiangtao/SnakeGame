#include "Snake.h"
#include "stdfx.h"
#include "Food.h"
#include <algorithm>

Snake::Snake()
{
	InitSnake();
}

std::list<POINT> Snake::GetBody() const
{
	return _bodyList;
}

void Snake::Draw()
{
	
	for (auto it : _bodyList)
	{
		POINT pos = it;
		
		fillrectangle(pos.x * WIDTH + WALL_BEGIN, pos.y * WIDTH, (pos.x + 1) * WIDTH + WALL_BEGIN, (pos.y + 1) * WIDTH);
	}
}

void Snake::InitSnake()
{
	int i =rand() % 20;
	POINT head = { i, 1 };        // ��ͷ��λ���ڵڶ��еڶ��У�C++��0��ʼ��
	_bodyList.push_back(head);

	POINT p1 = { i, 2 };
	POINT p2 = { i, 3 };
	POINT p3 = { i, 4 };
	_bodyList.push_back(p1); // ����ߵ�����
	_bodyList.push_back(p2);

	_bodyList.push_back(p3);

	_dir = Right;

}

void Snake::Update()
{
	int xOffset[4] = { 0, 0, -1, 1 };         // ��Direction��Ӧ��x��λ��
	int yOffset[4] = { -1, 1, 0, 0 };         // ��Direction��Ӧ��x��λ��
	auto it = _bodyList.begin();

	int prevX = it->x; // ��¼ͷ������
	int prevY = it->y;
	it->x += xOffset[_dir]; // �޸�ͷ������
	it->y += yOffset[_dir];

	it++;

	for (; it != _bodyList.end(); ++it)
	{
		// �����ڵ�ȫ���ƶ���ǰ��ڵ��λ��
		int curX = it->x;
		int curY = it->y;

		it->x = prevX;
		it->y = prevY;

		prevX = curX;
		prevY = curY;
	}
	
	Sleep(300);                // �ȴ�30���룬����֡��
}

void Snake::Move(Direction dir)
{
	if (_dir == Direction::Up && dir == Direction::Down
		|| _dir == Direction::Down && dir == Direction::Up
		|| _dir == Direction::Right && dir == Direction::Left
		|| _dir == Direction::Left && dir == Direction::Right)
	{
		return;        // ��Ҫ�ж��߲����򷴷����˶�
	}

	_dir = dir;
}

bool IsEquial(POINT temp)
{

	return true;
}

struct ComparePoint 
{
	ComparePoint(POINT p) :m_p(p)
	{

	}


	bool operator ()(POINT p)
	{
		if (p.x =m_p.x &&p.y ==m_p.y)
		{
			return true;
		}
		return false;
	}
	POINT m_p;
};


void Snake::EatFood(Food* food)
{
	auto it = _bodyList.begin();

	auto _x = it->x;
	auto _y = it->y;

	if (_x == food->GetPoint().x &&_y ==food->GetPoint().y)
	{
		food->InitFood();
		
		POINT tail1 = _bodyList.back();;

		tail1.y = tail1.y + 1;

		POINT tail2 = _bodyList.back();;

		tail2.y = tail2.y + -1;

		

		bool flag = true;
		if (std::find_if(_bodyList.begin(), _bodyList.end(), ComparePoint(tail1))==_bodyList.end())
		{
			_bodyList.push_back(tail1);
			flag = false;
		}
		if (true)
		{
		
		if (std::find_if(_bodyList.begin(), _bodyList.end(), ComparePoint(tail2)) == _bodyList.end())
		{
			_bodyList.push_back(tail2);
		}
		}

	}

}
