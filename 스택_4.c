#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

#define MAX 100 + 1

typedef struct StackNode {
	int data;
	struct StackNode* next;
}StackNode;

typedef struct {
	StackNode* top;
}Stack;

void init(Stack* S) {
	S->top = NULL;
}

int isEmpty(Stack* S) {
	return S->top == NULL;
}

void push(Stack* S, int data) {
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->data = data;
	node->next = S->top;

	S->top = node;
}

int pop(Stack* S) {
	if (isEmpty(S))
		return 0;

	StackNode* p = S->top;
	int data = p->data;
	S->top = p->next;
	free(p);

	return data;
}
void calculate(Stack* S, char str[]) {
	char c;
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		c = str[i];
		if (c >= '0' && c <= '9')
			push(S, c - '0');
		else {
			int Y = pop(S);
			int X = pop(S);
			switch (c) {
			case'+':
				push(S, X + Y);
				break;
			case'-':
				push(S, X - Y);
				break;
			case'*':
				push(S, X * Y);
				break;
			case'/':
				push(S, X / Y);
				break;
			}
		}
	}
	printf("%d\n", pop(S));
}

int main() {
	Stack S;
	init(&S);

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		getchar();
		char str[MAX];
		scanf("%s", str);
		calculate(&S, str);
	}
	return 0;
}