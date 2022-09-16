#include <stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct ListNode {
	int coef, exp;
	struct ListNode* next;
}ListNode;

typedef struct {
	ListNode* H, * T;
}ListType;

void init(ListType* L) {
	L->H = L->T = NULL;
}

void appendTerm(ListType* L, int c, int e) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* p = L;

	node->coef = c;
	node->exp = e;
	node->next = NULL;

	if (L->H == NULL)
		L->H = L->T = node;
	else {
		L->T->next = node;
		L->T = node;
	}
}

void addPoly(ListType* L1, ListType* L2, ListType* L3) {
	ListNode* p = L1->H;
	ListNode* q = L2->H;
	int sum;

	while (p && q) {
		if (p->exp == q->exp) {
			sum = p->coef + q->coef;
			if (sum)
				appendTerm(L3, sum, p->exp);
			p = p->next;
			q = q->next;
		}
		else if (p->exp > q->exp) {
			appendTerm(L3, p->coef, p->exp);
			p = p->next;
		}
		else {
			appendTerm(L3, q->coef, q->exp);
			q = q->next;
		}
	}
	for (; p != NULL; p = p->next)
		appendTerm(L3, p->coef, p->exp);
	for (; q != NULL; q = q->next)
		appendTerm(L3, q->coef, q->exp);
}

void print(ListType* L) {
	for (ListNode* p = L->H; p != NULL; p = p->next)
		printf(" %d %d", p->coef, p->exp);
	printf("\n");
}

int main() {
	ListNode Poly1, Poly2, result;
	init(&Poly1);
	init(&Poly2);
	init(&result);

	int N, c, e;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &c, &e);
		appendTerm(&Poly1, c, e);
	}

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &c, &e);
		appendTerm(&Poly2, c, e);
	}

	addPoly(&Poly1, &Poly2, &result);
	print(&result);

	return 0;
}