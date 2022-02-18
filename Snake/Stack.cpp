#include "Stack.h"

Stack::Stack(int size) {
	top = 0;
	stack = new int[size];
}

Stack::~Stack() {
	delete[] stack;
}

void Stack::Push(int element) {
	if (top < sizeof(stack)) stack[top++] = element;
	else {
		int* tmp = new int[top+10];

		for (int i = 0; i < sizeof(stack); i++) {
			tmp[i] = stack[i];
		}

		stack = tmp;
		stack[top++] = element;

		delete[] tmp;
	}
}

int Stack::Pop() {
	if (top > 0) return stack[--top];
}