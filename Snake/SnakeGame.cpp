#include "SnakeGame.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

namespace SnakeGame {

	SnakeGame::SnakeGame() {
		GameOver = false;
		srand(time(NULL));
		MainLoop();
	}

	SnakeGame::~SnakeGame() {
		delete fruit;
	}

	int SnakeGame::RandomInt(int min, int max) {
		return min + rand() % ((max + 1) - min);
	}

	Position SnakeGame::SetFoodPosition() {

		bool ok=false;
		int x_pos, y_pos;

		do {
			x_pos = RandomInt(0, board.width);
			y_pos = RandomInt(0, board.height);
			for (int i = 0; i < snake.len; i++) {
				if (snake.tail[i].x == x_pos && snake.tail[i].y == y_pos) {
					ok = false;
					break;
				}
				ok = true;
			}

		} while (!ok);

		return {x_pos, y_pos};
	}

	void SnakeGame::MainLoop() {
		std::cout << "\x1b[?25l"; // make terminal cursor invisible
		while (!GameOver) {
			Draw();
			HandleInput();
			Update();
		}
		std::cout << "\x1b[0m"; // reset styles
	}

	void SnakeGame::Draw() {
		std::cout << "\x1b[H";
		for (int y = 0; y < board.height; y++) {
			for (int x = 0; x < board.width; x++) {

				int color = board.bg;

				if (fruit->x == x && fruit->y == y) color = fruit->color;

				for (int i = 0; i < snake.len; i++) {
					if (snake.tail[i].x == x && snake.tail[i].y == y) color = snake.tail[i].color;
				}



				std::cout << "\x1b[38;5;" << color << 'm';
				std::cout << "\x1b[48;5;" << color << 'm';
				std::cout << '#';
			}
			std::cout << '\n';
		}
	}

	void SnakeGame::HandleInput() {
		switch (Input.GetInput())
		{
		case InputHandler::KEY::UP_KEY:
			if(snake.direction != Snake::Direction::DOWN) snake.direction = Snake::Direction::UP;
			break;

		case InputHandler::KEY::RIGHT_KEY:
			if (snake.direction != Snake::Direction::LEFT) snake.direction = Snake::Direction::RIGHT;
			break;

		case InputHandler::KEY::DOWN_KEY:
			if (snake.direction != Snake::Direction::UP) snake.direction = Snake::Direction::DOWN;
			break;

		case InputHandler::KEY::LEFT_KEY:
			if (snake.direction != Snake::Direction::RIGHT) snake.direction = Snake::Direction::LEFT;
			break;

		case InputHandler::KEY::EXIT_KEY:
			GameOver = true;
			break;
		default:
			break;
		}
	}

	void SnakeGame::Update() {
		snake.Move();
		if (snake.OutOfBounds(board.width, board.height)) {
			GameOver = true;
			return;
		}
		if (snake.tail[snake.len-1].x == fruit->x && snake.tail[snake.len-1].y == fruit->y) {
			Position pos = SetFoodPosition();
			fruit = new Food(pos.x, pos.y);
			snake.Eat();
		}
		int ammount = snake.SelfEat();
		if (ammount != -1) {
			snake.RemovePieces(ammount);
		}
	}

}
