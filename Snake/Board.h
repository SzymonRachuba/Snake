#pragma once
#include "Snake.h"

#define WIDTH 80
#define HEIGHT 25
#define SIZE WIDTH*HEIGHT

class Board
{
public:
	int* table = new int[SIZE];
	bool gameover = false;

	Snake* snake;

	Board();

	~Board();

private:
	char* tableBuffer = new char[SIZE];
	bool update;

	void MainLoop();
	void GetInput();
	void Render();
	void Update();

	void Print();

	int Index(int x, int y);
	char Keypress();
};

