#include "snake.h"
#include "map.h"
#include "score.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

const WORD FORE_GREEN = FOREGROUND_GREEN;          //绿色文本属性
const WORD BACK_BLUE = BACKGROUND_BLUE;           //蓝色背景属性  
const WORD BACK_GREEN = BACKGROUND_GREEN;          //绿色背景属性  
const WORD BACK_RED = BACKGROUND_RED;            //绿色背景属性 

int main()
{
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄  
	CONSOLE_SCREEN_BUFFER_INFO csbi;                        //定义窗口缓冲区信息结构体  
	GetConsoleScreenBufferInfo(handle_out, &csbi);

//	SetConsoleTextAttribute(handle_out, FORE_GREEN);
//	SetConsoleTextAttribute(handle_out, FORE_GREEN | BACK_BLUE | BACK_RED | BACK_GREEN);
	
//	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;             // 如果没赋值的话，隐藏光标无效  
	curInfo.bVisible = FALSE;

	SetConsoleCursorInfo(handle_out, &curInfo);

	while (1)
	{
		Snake s;
		Map m;

		int mode = 0;

		while (!s.bump())
		{
			s.set_direct();
			if (m.eatornot())
				m.new_food();
			m.set_map(s);
			m.show_map();
			//		Sleep(mode);
			score(s);
			s.set_direct();
			s.move(s.get_direct());
			s.set_direct();
		}
		cout << "	Press y to restart: " << endl;
		string str;
		getline(cin, str);
		if (str == "y")
		{
			COORD pos;
			pos.X = 0;
			pos.Y = 22;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "                                      " << endl << "                                              ";
			continue;
		}
		else
			break;
	}
	system("pause");
	return 0;
}
