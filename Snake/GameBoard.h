#pragma once

namespace SnakeGame {
	class GameBoard
	{
	public:
		const int width, height;
		int size = width * height;
		int bg;
		int* board;

		GameBoard(int width, int height);
		~GameBoard();

		int GetIndex(int x, int y) { return x + y * width; }

	private:
		void Init();
	};
}

