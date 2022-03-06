#pragma once
#include "Position.h"

#include <vector>

namespace SnakeGame {

	class Snake
	{
	public :

		enum class Direction {
			UP, RIGHT, DOWN, LEFT
		};

		int len;
		std::vector<Position> tail;
		Direction direction = Direction::RIGHT;

		Snake(int x, int y, int len);
		~Snake();

		void Move();
		void Eat();
		void RemovePieces(int count);
		bool OutOfBounds(int width, int height);
		int SelfEat();

	private :
		int headColor = 214, tailColor = 220;
		int growCounter;

		void MoveUp();
		void MoveRight();
		void MoveDown();
		void MoveLeft();
	};
}

