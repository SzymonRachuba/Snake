#pragma once

namespace SnakeGame {
		class InputHandler
		{
		public:

			enum class KEY {
				UP_KEY,
				RIGHT_KEY,
				DOWN_KEY,
				LEFT_KEY,
				EXIT_KEY,
				NONE
			};

			InputHandler();
			~InputHandler();


			KEY GetInput();
		private:
			char ReadKeyPressed();
		};
}

