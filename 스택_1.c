#include<stdio.h>
#pragma warning(disable : 4996)

typedef struct {
	char* data;
	int top;
}stackType;

void init(stackType* S, int N) {
	S->top = -1;
	S->data = (char*)malloc(sizeof(char) * (N + 1));
}

int isEmpty(stackType* S) {
	return S->top == -1;
}

int isFull(stackType* S, int N) {
	return S->top == N - 1;
}

void push(stackType* S, char data, int N) {
	if (isFull(S, N))
		printf("Stack FULL\n");
	else {
		S->top += 1;
		S->data[S->top] = data;
	}
}

char pop(stackType* S) {
	if (isEmpty(S)) {
		printf("Stack Empty\n");
		return -1;
	}
	int e = S->data[S->top];
	S->top -= 1;
	return e;
}

char peek(stackType* S) {
	if (isEmpty(S)) {
		printf("Stack Empty\n");
		return -1;
	}
	return S->data[S->top];
}

void duplicate(stackType* S, int N) {
	char temp = peek(S);
	if (temp != -1)
		push(S, temp, N);
}

void upRotate(stackType* S, int n) {
	int t = S->top;
	if (n <= t + 1) {
		char temp = S->data[t];
		for (int i = 1; i < n; i++) {
			S->data[t] = S->data[t - 1];
			t--;
		}
		S->data[t] = temp;
	}
}

void downRotate(stackType* S, int n) {
	int t = S->top - n + 1;
	if (n <= S->top + 1) {
		char temp = S->data[t];
		for (int i = 1; i < n; i++) {
			S->data[t] = S->data[t + 1];
			t++;
		}
		S->data[t] = temp;
	}
}

void print(stackType* S) {
	for (int i = S->top; i >= 0; i--) {
		printf("%c", S->data[i]);
	}
	printf("\n");
}

int main() {
	int N, T;

	scanf("%d", &N);
	scanf("%d", &T);

	stackType S;
	init(&S, N);

	for (int i = 0; i < T; i++) {
		char order[6];
		char data;
		int n;

		scanf("%s", order);

		if (strcmp(order, "PUSH") == 0) {
			scanf(" %c", &data);
			push(&S, data, N);
		}
		else if (strcmp(order, "POP") == 0) {
			pop(&S);
		}
		else if (strcmp(order, "PEEK") == 0) {
			if (peek(&S) != -1)
				printf("%c\n", peek(&S));
		}
		else if (strcmp(order, "DUP") == 0) {
			duplicate(&S, N);
		}
		else if (strcmp(order, "UpR") == 0) {
			scanf("%d", &n);
			upRotate(&S, n);
		}
		else if (strcmp(order, "DownR") == 0) {
			scanf("%d", &n);
			downRotate(&S, n);
		}
		else if (strcmp(order, "PRINT") == 0) {
			print(&S);
		}
		getchar();
	}

	return 0;
}