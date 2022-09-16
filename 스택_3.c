#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

#define MAX 100 + 1

typedef struct Stack {
	char data[MAX];
	int size;
}Stack;

void init(Stack* S) {
	S->size = 0;
}

int isEmpty(Stack* S) {
	return S->size == 0;
}

void push(Stack* S, char data) {
	S->data[S->size] = data;
	S->size++;
}

char pop(Stack* S) {
	if (isEmpty(S))
		return 0;
	S->size--;
	if (S->data[S->size] == '@')
		return S->data[S->size] - '@' + '+';
	else if (S->data[S->size] == '#')
		return S->data[S->size] - '#' + '-';
	return S->data[S->size];
}

char peek(Stack* S) {
	if (isEmpty(S))
		return 0;
	return S->data[S->size - 1];
}
int prior(char c) {
	if (c == '(') return 0;
	else if (c == '|') return 1;
	else if (c == '&') return 2;
	else if (c == '<' || c == '>') return 3;
	else if (c == '+' || c == '-') return 4;
	else if (c == '/' || c == '*') return 5;
	else if (c == '!' || c == '@' || c == '#') return 6;
	else return 7;
}

void intopost(Stack* S, char str[]) {
	char c;
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		c = str[i];

		switch (c) {
		case'+': case'-':
			if (i == 0 || prior(str[i - 1]) != 7) {
				if (c == '+') c = '@';
				else if (c == '-') c = '#';
			}
			while (!isEmpty(S) && prior(peek(S)) >= prior(c))
				printf("%c", pop(S));
			push(S, c);
			break;
		case'>': case'<': case'*': case'/': case'!':
			while (!isEmpty(S) && prior(peek(S)) >= prior(c))
				printf("%c", pop(S));
			push(S, c);
			break;
		case'&': case'|':
			while (!isEmpty(S) && prior(peek(S)) >= prior(c))
				printf("%c", pop(S));
			push(S, c);
			push(S, c);
			i++;
			break;
		case'(':
			push(S, c);
			break;
		case')':
			while (prior(peek(S)) != 0)
				printf("%c", pop(S));
			pop(S);
			break;
		default:
			printf("%c", c);
		}
	}
	while (!isEmpty(S))
		printf("%c", pop(S));
	printf("\n");
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
		intopost(&S, str);
	}
	return 0;
}