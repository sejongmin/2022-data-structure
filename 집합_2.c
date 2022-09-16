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

void traverse(SetType* S) {
	SetNode* p = S->H;

	if (p == NULL)
		printf(" 0");
	else
		for (; p != NULL; p = p->next)
			printf(" %d", p->data);
	printf("\n");
}

void unionSet(SetType* S1, SetType* S2) {
	SetType S;
	init(&S);

	SetNode* p = S1->H;
	SetNode* q = S2->H;
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			addLast(&S, p->data);
			p = p->next;
		}
		else if (p->data > q->data) {
			addLast(&S, q->data);
			q = q->next;
		}
		else {
			addLast(&S, p->data);
			p = p->next;
			q = q->next;
		}
	}
	while (p != NULL) {
		addLast(&S, p->data);
		p = p->next;
	}
	while (q != NULL) {
		addLast(&S, q->data);
		q = q->next;
	}
	traverse(&S);
}

void interSet(SetType* S1, SetType* S2) {

	SetType S;
	init(&S);

	SetNode* p = S1->H;
	SetNode* q = S2->H;
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			p = p->next;
		}
		else if (p->data > q->data) {
			q = q->next;
		}
		else {
			addLast(&S, p->data);
			p = p->next;
			q = q->next;
		}
	}
	traverse(&S);
}

int main() {
	SetType S1, S2;
	init(&S1);
	init(&S2);

	int n, e;

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
	unionSet(&S1, &S2);
	interSet(&S1, &S2);

	return 0;
}