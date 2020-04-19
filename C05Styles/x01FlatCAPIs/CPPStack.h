#pragma once

#include <iostream>

#define STACK_SIZE 2

class Stack
{
public:
	Stack(int size = STACK_SIZE);
	~Stack();
	void Push(int val);
	int Pop();
	bool IsEmpty() const; 
	//Q: Why const at end of method? 
	//A: const means that this function promises not change	*this(does not change class data). Reference source: https://isocpp.org/wiki/faq/const-correctness#overview-const
	bool IsFull() const;

private:
	int* mStack;
	int mTop;
	int mCapacity;
};

Stack::Stack(int size)
{
	mStack = new int[size];
	mCapacity = size;
	mTop = -1;
}

Stack::~Stack()
{
	delete mStack;
}

void Stack::Push(int val)
{
	if (IsFull()) exit(EXIT_FAILURE);
	std::cout << "Push" << std::endl;
	mStack[++mTop] = val;
}

int Stack::Pop()
{
	if (IsEmpty()) exit(EXIT_FAILURE);
	std::cout << "Pop" << std::endl;
	return mStack[mTop--];
}

bool Stack::IsEmpty() const
{
	return mTop == -1;
}

bool Stack::IsFull() const
{
	return mTop == mCapacity - 1;
}