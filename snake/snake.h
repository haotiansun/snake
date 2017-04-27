#ifndef SNAKE_H_
#define SNAKE_H_

class Snake
{
private:
	int direct;
	int snake[1000][3];
	int length;
public:
	Snake();
	~Snake();
	int get_direct(){ return direct; };
	int get_snake_x(int n);
	int get_snake_y(int n);
	void set_snake_x(int n, int x0);
	void set_snake_y(int n, int y0);
	void set_direct();
	void update_length();
	int get_length(){ return length; };
	void move(int d);
	bool bump();

};

#endif