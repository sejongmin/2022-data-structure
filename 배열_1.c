#include <stdio.h>
#pragma warning(disable:4996)

void changenum(int X[], int idx1, int idx2) {
	int cnt;
	if ((idx2 - idx1) % 2 == 1) {
		cnt = (idx2 - idx1 + 1) / 2;
	}
	else
		cnt = (idx2 - idx1) / 2;

	for (int i = 0; i < cnt; i++) {
		int tmp = X[idx1 + i];
		X[idx1 + i] = X[idx2 - i];
		X[idx2 - i] = tmp;
	}
}

int main() {
	int arr[100];
	int N, T;
	int idx1, idx2;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &idx1, &idx2);
		changenum(arr, idx1, idx2);
	}
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);

	return 0;
}