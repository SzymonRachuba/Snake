#include "GameBoard.h"

namespace SnakeGame {
	GameBoard::GameBoard(int width, int height) : width{ width }, height{ height } {
		Init();
	}

	GameBoard::~GameBoard() {
		delete[] board;
	}

	void GameBoard::Init() {
		board = new int[size];
		bg = 106;
		for (int i = 0; i < size; i++) {
			board[i] = bg;			// Background color
		}
	}

}