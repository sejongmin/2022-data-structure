#include <stdio.h>
#pragma warning(disable:4996)

int changenum(int X[], int idx, int num) {
	int rnum = X[idx];
	X[idx] = num;
	return rnum;
}

int main() {
	int arr[100];
	int N, T;
	int idx, num;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &T);
	scanf("%d", &idx);

	num = arr[idx];

	for (int i = 1; i < T; i++) {
		scanf("%d", &idx);
		num = changenum(arr, idx, num);
	}

	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);

	return 0;
}