#pragma once
#include "InputHandler.h"
#include "GameBoard.h"
#include "Snake.h"
#include "Food.h"
#include "Position.h"


namespace SnakeGame {
	class SnakeGame
	{
	public:
		bool GameOver;
		
		GameBoard board = GameBoard(80, 25);
		Snake snake = Snake(board.width/2, board.height/2, 10);
		Food* fruit = new Food(40, 5);

		SnakeGame();
		~SnakeGame();


	private:
		InputHandler Input = InputHandler();

		int RandomInt(int min, int max);

		Position SetFoodPosition();

		void MainLoop();
		void Draw();
		void HandleInput();
		void Update();

	};
}

