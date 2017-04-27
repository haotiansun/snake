#include <iostream>
#include <windows.h>
#include "snake.h"
#include "print.h"
#include <conio.h>

using namespace std;

Snake::Snake()
{
	length = 1;
	direct = 2;
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			snake[i][j] = -1;
	snake[0][0] = 1;
	snake[0][1] = rand() % (20) + 1;
	snake[0][2] = rand() % (50) + 1;
}

Snake::~Snake()
{
}

void Snake::update_length()
{
	this->length++;
}

int Snake::get_snake_x(int n)
{
	return snake[n][1];
}

int Snake::get_snake_y(int n)
{
	return snake[n][2];
}

void Snake::set_snake_x(int n, int x0)
{
	snake[n][1] = x0;
}

void Snake::set_snake_y(int n, int y0)
{
	snake[n][2] = y0;
}

void Snake::move(int d)
{
	switch (d)
	{
	//up
	case 1:
	{
//		erase_snake(snake[length - 1][1], snake[length - 1][2]);
		for (int n = length - 1; n > 0; n--)
		{
			snake[n][2] = snake[n - 1][2];
			snake[n][1] = snake[n - 1][1];
			
		}
		snake[0][1]--;
		
		if (this->bump())
		{
			COORD pos;
			pos.X = 0;
			pos.Y = 22;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "DEAD";
		}
		break;
	}
	//down
	case 2:
	{
		for (int n = length - 1; n > 0; n--)
		{
			snake[n][2] = snake[n - 1][2];
			snake[n][1] = snake[n - 1][1];
		}
		snake[0][1]++;
		if (this->bump())
		{
			COORD pos;
			pos.X = 0;
			pos.Y = 22;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "DEAD";
		}
		break;
	}
	//left
	case 3:
	{
		for (int n = length - 1; n > 0; n--)
		{
			snake[n][2] = snake[n - 1][2];
			snake[n][1] = snake[n - 1][1];
		}
		snake[0][2]--;
		if (this->bump())
		{
			COORD pos;
			pos.X = 0;
			pos.Y = 22;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "DEAD";
		}
		break;
	}
	//right
	case 4:
	{
		for (int n = length - 1; n > 0; n--)
		{
			snake[n][2] = snake[n - 1][2];
			snake[n][1] = snake[n - 1][1];
		}
		snake[0][2]++;
		if (this->bump())
		{
			COORD pos;
			pos.X = 0;
			pos.Y = 22;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "DEAD";
		}
		break;
	}
	default:
		break;
	}
}

void Snake::set_direct()
{
	int key;
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case 72:        //up
		{
			if (direct != 2)
				direct = 1;
			break;
		}
		case 80:        //down
		{
			if (direct != 1)
				direct = 2;
			break;
		}
		case 75:
		{
			if (direct != 4)
				direct = 3;
			break;
		}
		case 77:
		{
			if (direct != 3)
				direct = 4;
			break;
		}
		}
	}
}

bool Snake::bump()
{
	if (snake[0][1] == 0 || snake[0][1] == 21 || snake[0][2] == 0 || snake[0][2] == 51)
		return true;
	for (int n = 1; n < length; n++)
		if (snake[0][1] == snake[n][1] && snake[0][2] == snake[n][2])
			return true;
	return false;
}