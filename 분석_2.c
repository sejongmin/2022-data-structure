#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int mostOnes(int A[][100], int n) {
	int ans = 0, row = 0, col = 0;

	while (row != n && col != n) {
		if (A[row][col] == 0) {
			row += 1;
			continue;
		}
		ans = row;
		col += 1;
	}
	return ans;
}

int main() {
	int A[100][100];
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	printf("%d", mostOnes(A, N));

	return 0;
}