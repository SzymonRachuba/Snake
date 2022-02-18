#pragma once
class Stack
{
public:
	int top;
	int* stack;

	Stack(int size);

	~Stack();

	void Push(int element);
	int Pop();

private:
};

