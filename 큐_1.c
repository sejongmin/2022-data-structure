#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct {
	int* queue;
	int front, rear;
	int q;
}QueueType;

void init(QueueType* Q) {
	scanf("%d", &Q->q);
	Q->queue = (int*)calloc(Q->q, sizeof(int));
	Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q) {
	return Q->rear == Q->front;
}

int isFull(QueueType* Q) {
	return (Q->rear + 1) % Q->q == Q->front;
}

void print(QueueType* Q) {
	for (int i = 0; i < Q->q; i++) {
		printf(" %d", Q->queue[i]);
	}
	printf("\n");
}

int enqueue(QueueType* Q, int e) {
	if (isFull(Q)) {
		printf("overflow");
		print(Q);
		return 0;
	}
	Q->rear = (Q->rear + 1) % Q->q;
	Q->queue[Q->rear] = e;

	return 1;
}

int dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("underflow");
		return 0;
	}
	Q->front = (Q->front + 1) % Q->q;
	Q->queue[Q->front] = 0;

	return 1;
}

int main() {
	QueueType Q;
	init(&Q);

	int N;
	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++) {
		char o;
		int e;
		scanf("%c", &o);

		if (o == 'I') {
			scanf("%d", &e);
			if (!enqueue(&Q, e))
				break;
		}
		else if (o == 'D') {
			if (!dequeue(&Q))
				break;
		}
		else if (o == 'P') {
			print(&Q);
		}
		getchar();
	}

	return 0;
}