#include "Snake.h"

namespace SnakeGame {

	Snake::Snake(int x, int y, int len) : len{ len } {
		growCounter = 0;
		for (int i = 0; i < len; i++) {
			tail.push_back({ (x - len) + i, y, tailColor });
		}
		tail[len - 1].color = headColor;
	}

	Snake::~Snake() {

	}


	void Snake::Eat() {
		growCounter = 5;
	}

	int Snake::SelfEat() {
		int count = 0;
		for (int i = 0; i < len-1; i++) {
			count++;
			if (tail[i].x == tail[len - 1].x && tail[i].y == tail[len - 1].y) return count;
		}
		return -1;
	}

	void Snake::RemovePieces(int count) {
		for (int i = 0; i < count; i++) {
			tail.erase(tail.begin());
			len--;
		}
	}

	bool Snake::OutOfBounds(int width, int height) {
		if (tail[len - 1].x < 0 || tail[len - 1].x > width || tail[len - 1].y < 0 || tail[len - 1].y > height) return true;
		return false;
	}

	void Snake::Move() {
		switch (direction)
		{
		case Direction::UP:
			MoveUp();
			break;

		case Direction::RIGHT:
			MoveRight();
			break;

		case Direction::DOWN:
			MoveDown();
			break;

		case Direction::LEFT:
			MoveLeft();
			break;

		default:
			break;
		}
	}

	void Snake::MoveUp() {
		Position head = tail[len - 1];
		Position newpos = { head.x, head.y-1, headColor };

		tail.push_back(newpos);
		tail[len - 1].color = tailColor;

		if (growCounter > 0) {
			len++;
			growCounter--;
		}
		else {
			tail.erase(tail.begin());
		}

	}

	void Snake::MoveRight() {
		Position head = tail[len - 1];
		Position newpos = { head.x+1, head.y, headColor };

		tail.push_back(newpos);
		tail[len - 1].color = tailColor;

		if (growCounter > 0) {
			len++;
			growCounter--;
		}
		else {
			tail.erase(tail.begin());
		}
	}

	void Snake::MoveDown() {
		Position head = tail[len - 1];
		Position newpos = { head.x, head.y+1, headColor };

		tail.push_back(newpos);
		tail[len - 1].color = tailColor;

		if (growCounter > 0) {
			len++;
			growCounter--;
		}
		else {
			tail.erase(tail.begin());
		}
	}

	void Snake::MoveLeft() {
		Position head = tail[len - 1];
		Position newpos = { head.x - 1, head.y, headColor };

		tail.push_back(newpos);
		tail[len - 1].color = tailColor;

		if (growCounter > 0) {
			len++;
			growCounter--;
		}
		else {
			tail.erase(tail.begin());
		}
	}
}