#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct QueueNode {
	int data;
	struct QueueNode* next, * prev;
}QueueNode;

typedef struct {
	QueueNode* front, * rear;
}QueueType;

void init(QueueType* Q) {
	Q->front = Q->rear = NULL;
}

int isEmpty(QueueType* Q) {
	return Q->front == NULL;
}

void add_front(QueueType* Q, int e) {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->prev = NULL;
	node->next = Q->front;
	node->data = e;

	if (isEmpty(Q)) {
		Q->front = node;
		Q->rear = node;
	}
	else {
		QueueNode* p = Q->front;
		p->prev = node;
		Q->front = node;
	}
}

void add_rear(QueueType* Q, int e) {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->next = NULL;
	node->prev = Q->rear;
	node->data = e;

	if (isEmpty(Q)) {
		Q->front = node;
		Q->rear = node;
	}
	else {
		QueueNode* p = Q->rear;
		p->next = node;
		Q->rear = node;
	}
}

int delete_front(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("underflow\n");
		return 0;
	}
	QueueNode* p = Q->front;

	if (p != Q->rear) {
		Q->front = p->next;
		Q->front->prev = NULL;
	}
	else {
		Q->front = NULL;
		Q->rear = NULL;
	}

	free(p);

	return 1;
}

int delete_rear(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("underflow\n");
		return 0;
	}

	QueueNode* p = Q->rear;

	if (p != Q->front) {
		Q->rear = p->prev;
		Q->rear->next = NULL;
	}
	else {
		Q->front = NULL;
		Q->rear = NULL;
	}
	free(p);

	return 1;
}

void print(QueueType* Q) {
	QueueNode* p = Q->front;

	for (; p != NULL; p = p->next)
		printf(" %d", p->data);
	printf("\n");
}

int main() {
	QueueType Q;
	init(&Q);

	int N;
	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++) {
		char o[3];
		int e;
		fgets(o, 3, stdin);

		if (strcmp(o, "AF") == 0) {
			scanf("%d", &e);
			add_front(&Q, e);
			getchar();
		}
		else if (strcmp(o, "AR") == 0) {
			scanf("%d", &e);
			add_rear(&Q, e);
			getchar();
		}
		else if (strcmp(o, "DF") == 0) {
			if (!delete_front(&Q))
				break;
			getchar();
		}
		else if (strcmp(o, "DR") == 0) {
			if (!delete_rear(&Q))
				break;
			getchar();
		}
		else {
			print(&Q);
		}

	}

	return 0;
}