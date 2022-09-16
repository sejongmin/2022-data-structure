#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


typedef struct SetNode{
	int data;
	struct SetNode* next;
}SetNode;

typedef struct {
	SetNode* H;
}SetType;

void init(SetType* S) {
	S->H = NULL;
}

void addLast(SetType* S, int data) {
	SetNode* node = (SetNode*)malloc(sizeof(SetNode));
	node->data = data;
	node->next = NULL;

	SetNode* p = S->H;
	if (p == NULL)
		S->H = node;
	else {
		while (p->next != NULL)
			p = p->next;

		p->next = node;
	}
}
int member(SetType* S, int e) {
	if (S->H == NULL)
		return 0;

	SetNode* p = S->H;

	while (1) {
		int a = p->data;
		if (a < e) {
			if (p->next == NULL)
				return 0;
			else
				p = p->next;
		}
		else if (a > e)
			return 0;
		else
			return 1;
	}
}

int subSet(SetType* S1, SetType* S2, int* failResult) {
	if (S1->H == NULL)
		return 1;

	SetNode* p = S1->H;

	while (1) {
		if (member(S2, p->data)) {
			if (p->next == NULL)
				return 1;
			else
				p = p->next;
		}
		else {
			*failResult = p->data;
			return 0;
		}
	}
}

int main() {
	SetType S1, S2;
	init(&S1);
	init(&S2);

	int n, e, failResult = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &e);
		addLast(&S1, e);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &e);
		addLast(&S2, e);
	}

	if (subSet(&S1, &S2, &failResult)) printf("0\n");
	else printf("%d\n", failResult);

	return 0;
}