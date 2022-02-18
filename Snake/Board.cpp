#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#include "Board.h"

using namespace std;

#define STARTLOC (int)(SIZE/2)

Board::Board() {
	int px = WIDTH / 2, py = HEIGHT / 2;
	snake = new Snake(px, py, Index(px, py));
	for (int i = 0; i < SIZE; i++) {
		table[i] = 106;
		tableBuffer[i] = table[i];
	}

	MainLoop();
}

Board::~Board() {
	cout << "Deleting Board";
	delete[] table;
}

void Board::Print() {
	cout << "\u001b[100000D";																				// move cursor left 
	cout << "\u001b[100000A";																				// move cursor up

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			cout << "\u001b[38;5;" << table[Index(x,y)] << "m\u001b[48;5;" << table[Index(x, y)] << "m";	// set bg color
			cout << "#";
		}
		cout << endl;
	}

	cout << "\u001b[0m";																					// reset colors
}

int Board::Index(int x, int y) {
	return x + y * WIDTH;
}

void Board::MainLoop() {
	while (!gameover) {
		GetInput();
		Update();
		Render();
	}
	delete this;
}

char Board::Keypress() {
	if (_kbhit()) {
		char c;
		c = _getch();
		return c;
	}
	else return ' ';
}

void Board::GetInput() {

	int key = Keypress();
	/*
		UP: 1 - 0 = 1
		DOWN: 0 - 1 = -1
		BOTH: 1-1 = 0
		same for horizontal
	*/
	int vertical = (key == 's') - (key == 'w');
	int horizontal = (key == 'd' ) - (key == 'a');

	snake->posx += horizontal;
	snake->posy += vertical;

	snake->id = Index(snake->posx,snake->posy);

}

void Board::Update() {
	for (int i = 0; i < snake->segments->top; i++) {
		tableBuffer[snake->segments->stack[i]] = 0;
	}

	for (int i = 0; i < SIZE; i++) {
		if (table[i] != tableBuffer[i]) table[i] = tableBuffer[i];
	}
}

void Board::Render() {
	Print();
}