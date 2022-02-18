#include "Snake.h"

Snake::Snake(int posx, int posy, int id) {
	this->posx = posx;
	this->posy = posy;
	this->id = id;
	segments = new Stack(len);

	for (int i = 0; i < len; i++) {
		segments->Push(id-i);
	}
}

Snake::~Snake() {
	delete[] segments;
}
