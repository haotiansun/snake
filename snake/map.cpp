#include "map.h"
#include "print.h"
#include <time.h>
#include<iostream>
using namespace std;

Map::Map()
{
	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
		{
			if (i == 0 || j == 0 || i == 51 || j == 51)
				map[i][j] = '#';
			else
				map[i][j] = ' ';
		}
	eat = true;
}

Map::~Map()
{
}

void Map::set_map(Snake & s0)
{
	//draw the environment
	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 52; j++)
		{
			if (i == 0 || j == 0 || i == 21 || j == 51)
				map[i][j] = '#';
			else if (i == food_x && j == food_y)
				map[i][j] = '$';
			else
				map[i][j] = ' ';
		}
	//draw the snake
	if (food_x == s0.get_snake_x(0) && food_y == s0.get_snake_y(0))
			{
				eat = true;
				s0.update_length();
//				map[food_x][food_y] = '=';
				switch (s0.get_direct())
				{
				case 1:
					s0.set_snake_x(s0.get_length() - 1, food_x + 1);
					s0.set_snake_y(s0.get_length() - 1, food_y);
				case 2:
					s0.set_snake_x(s0.get_length() - 1, food_x - 1);
					s0.set_snake_y(s0.get_length() - 1, food_y);
				case 3:
					s0.set_snake_x(s0.get_length() - 1, food_x);
					s0.set_snake_y(s0.get_length() - 1, food_y + 1);
				case 4:
					s0.set_snake_x(s0.get_length() - 1, food_x);
					s0.set_snake_y(s0.get_length() - 1, food_y - 1);
				default:
					break;
				}
			}

	for (int n = 0; n < 1000; n++)
	{	
		
		if (s0.get_snake_x(n) == -1 || s0.get_snake_y(n) == -1)
			break;
		else
		{
			map[s0.get_snake_x(n)][s0.get_snake_y(n)] = '@';
		}
	}

}

void Map::new_food()
{
	a:		srand((unsigned)time(NULL));
		int x = rand() % (20) + 1;
		srand((unsigned)time(NULL));
		int y = rand() % (50) + 1;

		if (map[x][y] == '@')
			goto a;
		else
		{
			map[x][y] = '$';
			print_food(x, y);
		}

		food_x = x;
		food_y = y;

		eat = false;
	
}

void Map::show_map()
{
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			if (map[i][j] == ' ')
				print_blank(i, j);
			else if (map[i][j] == '#')
				print_wall(i, j);
			else if (map[i][j] == '$')
				print_food(i, j);
			else
				print_snake(i, j);
		}
		cout << endl;
	}
}