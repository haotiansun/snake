#include "print.h"
#include<windows.h>
#include<iostream>
using namespace std;

void print_wall(int x, int y)
{
	COORD pos;
	pos.X = y;
	pos.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << '#';
}

void print_food(int x, int y)
{
	COORD pos;
	pos.X = y;
	pos.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << '$';
}

void print_snake(int x, int y)
{
	COORD pos;
	pos.X = y;
	pos.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << '@';
}

void print_blank(int x, int y)
{
	COORD pos;
	pos.X = y;
	pos.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << ' ';
}

void erase_snake(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << ' ';
}