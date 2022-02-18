#include "InputHandler.h"

#include <conio.h>

#include <string>

namespace SnakeGame {
	InputHandler::InputHandler() {

	}

	InputHandler::~InputHandler() {

	}

	char InputHandler::ReadKeyPressed() {
		char key = _getch();
		return tolower(key);
	}

	InputHandler::KEY InputHandler::GetInput() {
		if (_kbhit()) {
			switch (ReadKeyPressed())
			{
			case 'w':
				return KEY::UP_KEY;
				break;
			case 'd':
				return KEY::RIGHT_KEY;
				break;
			case 's':
				return KEY::DOWN_KEY;
				break;
			case 'a':
				return KEY::LEFT_KEY;
				break;
			case 'x':
				return KEY::EXIT_KEY;
				break;
			default:
				break;
			}
		}
		return KEY::NONE;
	}
}