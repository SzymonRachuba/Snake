#pragma once
#include "Stack.h"
class Snake
{
public:
	int posx, posy;
	int id;
	Stack* segments;


	Snake(int posx, int posy, int id);

	~Snake();

private:
	int len = 8;
};

