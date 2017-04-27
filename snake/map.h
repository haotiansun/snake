#include "snake.h"

class Map
{
public:
	Map();
	~Map();
	void set_map(Snake & s0);
	void new_food();
	void show_map();
	bool eatornot(){ return eat; };
private:
	char map[52][52];
	bool eat;
	int food_x;
	int food_y;
};