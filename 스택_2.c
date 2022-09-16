#include<stdio.h>
#pragma warning(disable : 4996)

#define N 1000

typedef struct stackNode {
	char data;
	struct stackNode* next;
}stackNode;

typedef struct {
	stackNode* top;
	int size;
}stackType;

void init(stackType* S) {
	S->top = NULL;
	S->size = 0;
}

int isEmpty(stackType* S) {
	return S->size == 0;
}


void push(stackType* S, char e) {
	stackNode* node = (stackNode*)malloc(sizeof(stackNode));
	node->data = e;
	node->next = S->top;
	S->top = node;

	S->size++;
}

char pop(stackType* S) {
	if (isEmpty(S)) {
		printf("stack is Empty\n");
		return -1;
	}
	stackNode* p = S->top;
	char e = p->data;
	p = p->next;

	S->top = p;
	S->size--;

	return e;
}
int check(char str[], int* cnt) {
	stackType S;
	init(&S);

	int Flag = 1;
	char c, t;
	int n = strlen(str);

	for (int i = 0; i < n; i++) {
		c = str[i];
		if (c == '(' || c == '{' || c == '[') {
			*cnt = *cnt + 1;
			push(&S, c);
		}
		else if (c == ')' || c == '}' || c == ']') {
			*cnt = *cnt + 1;
			if (isEmpty(&S))
				Flag = 0;
			else {
				t = pop(&S);
				if ((t == '(' && c != ')') || (t == '{' && c != '}') || (t == '[' && c != ']'))
					Flag = 0;
			}
		}
	}
	if (Flag != 0)
		Flag = isEmpty(&S);
	return Flag;
}


int main() {

	char str[N];
	int cnt = 0;
	fgets(str, sizeof(str), stdin);

	if (check(str, &cnt))
		printf("OK_%d\n", cnt);
	else
		printf("Wrong_%d\n", cnt);

	return 0;
}