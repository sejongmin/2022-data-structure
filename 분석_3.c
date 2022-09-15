#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int* prefixAverages1(int X[], int n) {
	int* A;
	A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += X[j];
		}
		if (((sum * 10) / (i + 1)) % 10 >= 5)
			A[i] = sum / (i + 1) + 1;
		else
			A[i] = sum / (i + 1);
	}
	return A;
}

int* prefixAverages2(int X[], int n) {
	int sum = X[0];

	int* A;
	A = (int*)malloc(sizeof(int) * n);
	A[0] = X[0];

	for (int i = 1; i < n; i++) {
		sum += X[i];

		if (((sum * 10) / (i + 1)) % 10 >= 5)
			A[i] = sum / (i + 1) + 1;
		else
			A[i] = sum / (i + 1);
	}
	return A;
}

int main() {
	int N;
	int* A1;
	int* A2;
	int* A;

	scanf("%d", &N);

	A = (int*)malloc(sizeof(int) * N);
	A1 = (int*)malloc(sizeof(int) * N);
	A2 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	A1 = prefixAverages1(A, N);
	A2 = prefixAverages2(A, N);


	for (int i = 0; i < N; i++)
		printf("%d ", A1[i]);
	printf("\n");

	for (int i = 0; i < N; i++)
		printf("%d ", A2[i]);

	free(A);
	free(A1);
	free(A2);

	return 0;
}