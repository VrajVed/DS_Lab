#include <stdio.h>
#include <stdlib.h>

#define MAX 10

static int top = -1;

int isEmpty(void) {
	return top == -1;
}

int isFull(void) {
	return top == MAX - 1;
}

int size(void) {
	return top + 1;
}

void push(int st[], int val) {
	if (isFull()) {
		printf("\nStack Overflow");
		return;
	}

	top++;
	st[top] = val;
}


int peek(int st[]) {
	if (isEmpty()) {
		printf("\nStack is empty");
		return -1;
	}
	return st[top];
}


int pop(int st[]){
	int val;

	if (isEmpty()) {
		printf("\nStack Underflow");
		return -1;
	}

	val = st[top];
	top--;
	return val;
}


int main () {
	int stack[MAX];

	push(stack, 10);
	push(stack, 20);
	printf("Top: %d (size=%d)\n", peek(stack), size());
	printf("Popped: %d\n", pop(stack));
	printf("Top: %d (size=%d)\n", peek(stack), size());

	return 0;
}
 