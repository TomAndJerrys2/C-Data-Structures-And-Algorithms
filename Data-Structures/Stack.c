// Basic C Stack implementation using Structs

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 64;

typedef struct Stack {
	int capacity;
	int top;
	int* stackArr;
} Stack;

Stack* createStack(unsigned int capacity) {
	Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->stackArr = (int*) malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(Stack* stack) {
	return ((stack->top) == (stack->capacity - 1));
}

int isEmpty(Stack* stack) {
	return (stack->top == -1);
}

void push(Stack* stack, int element) {
	if (isFull(stack)) {
		printf("[!] Overflow\n");
		return;
	}

	stack->stackArr[++stack->top] = element;
	printf("[!] %d : Pushed Successfully!\n", element);
}

int pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("[!] Underflow\n");
		return 0;
	}

	return stack->stackArr[stack->top--];
}

int peek(Stack* stack) {
	if (isEmpty(stack)) {
		printf("[!] Stack is Empty!");
		return 0;
	}

	return stack->stackArr[stack->top];
}

void displayStack(Stack* stack) {
	if (isEmpty(stack)) {
		printf("[!] Stack is Empty!");
		return;
	}

	for (int i = stack->top; i >= 0; i--) {
		printf("%d, ", stack->stackArr[i]);
	}
}
