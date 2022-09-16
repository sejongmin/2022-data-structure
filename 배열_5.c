#include <stdio.h>
#pragma warning(disable:4996)

void rain(int arr[][100], int N, int M) {

	int num = 1;
	for (int x = 0; x < M; x++) {
		int i = 0;
		int j = x;
		while (1) {
			if (i >= N || j < 0) break;
			arr[i++][j--] = num++;
		}
	}

	for (int y = 1; y < N; y++) {
		int i = y;
		int j = M - 1;
		while (1) {
			if (i >= N || j < 0) break;
			arr[i++][j--] = num++;
		}
	}
}

int main() {
	int N, M, arr[100][100];

	scanf("%d %d", &N, &M);

	rain(arr, N, M);

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			printf(" %d", arr[x][y]);
		}
		printf("\n");
	}
	return 0;
}