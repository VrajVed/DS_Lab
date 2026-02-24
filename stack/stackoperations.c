#include <stdio.h>
#include <stdlib.h>

void push(int st[], int val) {
	
	if (top == MAX - 1){
		
		printf("\n Stack Overflow");
	}
	else {
		top++;
		st[top] = val;	
	}
	
}


int pop(int st[]){
	
	int val;
	
	if (top == -1) {
		printf("\n Stack Underflow");
		return -1;
	}
	else {
		
		val = st[top];
		top--;
		return val;
	}
}


int main () {
	
	int stack[10];
	
	
	
	return 0;
}
 