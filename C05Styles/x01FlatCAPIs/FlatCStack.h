#pragma once
// Source code: https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
#include <iostream>

#define v1 1
#define v2 2
#define version 2

struct Stack
{
	int* mStack;
	int mTop;
	int mCapacity;
};

#if version == v1
struct Stack* StackCreate(int capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); //Q: What diff malloc & alloc?
	stack->mCapacity = capacity;
	stack->mTop = -1;
	stack->mStack = (int*)malloc(stack->mCapacity * sizeof(int));
	return stack;
}

void StackDestroy(struct Stack * stack)
{
	free(stack);
}

// native C doesn't have bool: https://stackoverflow.com/questions/1608318/is-bool-a-native-c-type
int StackIsFull(struct Stack* stack)
{
	return stack->mTop == stack->mCapacity - 1;
}

int StackIsEmpty(struct Stack* stack)
{
	return stack->mTop == - 1;
}

void StackPush(struct Stack* stack, int val)
{
	if (StackIsFull(stack)) return;
	stack->mStack[++stack->mTop] = val;
}

int StackPop(struct Stack* stack, int val)
{
	if (StackIsEmpty(stack)) return INT_MIN;
	return stack->mStack[stack->mTop--];
}

#elif version == v2
typedef struct Stack* StackPtr;

StackPtr StackCreate(int capacity=2)
{
	StackPtr stack = (StackPtr)malloc(sizeof(struct Stack)); //Q: What diff malloc & alloc?
	stack->mCapacity = capacity;
	stack->mTop = -1;
	stack->mStack = (int*)malloc(stack->mCapacity * sizeof(int));
	return stack;
}

void StackDestroy(StackPtr stack)
{
	free(stack);
}

int StackIsFull(StackPtr stack)
{
	return stack->mTop == stack->mCapacity - 1;
}

int StackIsEmpty(StackPtr stack)
{
	return stack->mTop == -1;
}

void StackPush(StackPtr stack, int val)
{
	if (StackIsFull(stack)) return;
	std::cout << "Push" << std::endl;
	stack->mStack[++stack->mTop] = val;
}

int StackPop(StackPtr stack)
{
	if (StackIsEmpty(stack)) return INT_MIN;
	std::cout << "Pop" << std::endl;
	return stack->mStack[stack->mTop--];
}
#endif


