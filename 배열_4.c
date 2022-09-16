#include <stdio.h>
#pragma warning(disable:4996)


void screw(int arr[][100], int N, int M) {
	int start_col = 0, finish_col = M - 1;
	int start_row = 0, finish_row = N - 1;
	int num = 1, i, j;

	while (start_col <= finish_col && start_row <= finish_row) {
		for (j = start_col; j <= finish_col; j++)
			arr[start_row][j] = num++;
		start_row++;

		if (start_row <= finish_row) {
			for (i = start_row; i <= finish_row; i++)
				arr[i][finish_col] = num++;
			finish_col--;
			if (start_col <= finish_col) {
				for (j = finish_col; j >= start_col; j--)
					arr[finish_row][j] = num++;
				finish_row--;
				if (start_row <= finish_row) {
					for (i = finish_row; i >= start_row; i--)
						arr[i][start_col] = num++;
					start_col++;
				}
			}
		}
	}
}

int main() {
	int N, M, arr[100][100];

	scanf("%d %d", &N, &M);

	screw(arr, N, M);

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			printf(" %d", arr[x][y]);
		}
		printf("\n");
	}

	return 0;
}