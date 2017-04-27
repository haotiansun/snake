#include "score.h"
#include <iostream>
#include<windows.h>

using namespace std;

void score(Snake & s0)
{
	COORD pos;
	pos.X = 52;
	pos.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "score:	"<<s0.get_length();
}