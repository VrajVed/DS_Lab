#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_EXPR 512
#define MAX_STACK 512

typedef struct {
	char items[MAX_STACK];
	int top;
} CharStack;

static void stackInit(CharStack *s) {
	s->top = -1;
}

static int stackIsEmpty(const CharStack *s) {
	return s->top == -1;
}

static int stackIsFull(const CharStack *s) {
	return s->top == MAX_STACK - 1;
}

static int stackPush(CharStack *s, char ch) {
	if (stackIsFull(s)) {
		return 0;
	}
	s->items[++s->top] = ch;
	return 1;
}

static char stackPop(CharStack *s) {
	if (stackIsEmpty(s)) {
		return '\0';
	}
	return s->items[s->top--];
}

static char stackPeek(const CharStack *s) {
	if (stackIsEmpty(s)) {
		return '\0';
	}
	return s->items[s->top];
}

static int isOperator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

static int precedence(char op) {
	switch (op) {
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}

static int isRightAssociative(char op) {
	return op == '^';
}

// Returns 1 on success, 0 on error.
static int infixToPostfix(const char *infix, char *postfix, size_t postfixCap) {
	CharStack ops;
	size_t out = 0;

	stackInit(&ops);

	for (size_t i = 0; infix[i] != '\0'; i++) {
		char ch = infix[i];

		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
			continue;
		}

		if (isalnum((unsigned char)ch)) {
			if (out + 1 >= postfixCap) {
				return 0;
			}
			postfix[out++] = ch;
			continue;
		}

		if (ch == '(') {
			if (!stackPush(&ops, ch)) {
				return 0;
			}
			continue;
		}

		if (ch == ')') {
			while (!stackIsEmpty(&ops) && stackPeek(&ops) != '(') {
				if (out + 1 >= postfixCap) {
					return 0;
				}
				postfix[out++] = stackPop(&ops);
			}
			if (stackIsEmpty(&ops)) {
				// No matching '('
				return 0;
			}
			(void)stackPop(&ops); // pop '(' and discard
			continue;
		}

		if (isOperator(ch)) {
			while (!stackIsEmpty(&ops) && stackPeek(&ops) != '(') {
				char topOp = stackPeek(&ops);
				int pTop = precedence(topOp);
				int pCur = precedence(ch);

				if (pTop > pCur || (pTop == pCur && !isRightAssociative(ch))) {
					if (out + 1 >= postfixCap) {
						return 0;
					}
					postfix[out++] = stackPop(&ops);
				} else {
					break;
				}
			}

			if (!stackPush(&ops, ch)) {
				return 0;
			}
			continue;
		}

		// Unknown character
		return 0;
	}

	while (!stackIsEmpty(&ops)) {
		char op = stackPop(&ops);
		if (op == '(') {
			// Unmatched '('
			return 0;
		}
		if (out + 1 >= postfixCap) {
			return 0;
		}
		postfix[out++] = op;
	}

	postfix[out] = '\0';
	return 1;
}

int main(void) {
	char infix[MAX_EXPR];
	char postfix[MAX_EXPR];

	printf("Enter infix expression: ");
	if (!fgets(infix, sizeof(infix), stdin)) {
		printf("Failed to read input.\n");
		return 1;
	}

	// Trim trailing newline (if any)
	infix[strcspn(infix, "\n")] = '\0';

	if (!infixToPostfix(infix, postfix, sizeof(postfix))) {
		printf("Invalid expression (check operators/parentheses/length).\n");
		return 1;
	}

	printf("Postfix: %s\n", postfix);
	return 0;
}
