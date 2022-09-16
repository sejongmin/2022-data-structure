#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void zigzag(int arr[][100], int N) {
	int num = 1;

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = num++;
			}
		}
		else {
			for (int j = N - 1; j >= 0; j--) {
				arr[i][j] = num++;
			}
		}
	}
}

int main() {
	int N, num = 1, arr[100][100];
	scanf("%d", &N);

	zigzag(arr, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}