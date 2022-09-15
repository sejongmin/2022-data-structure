#include <stdio.h>
#pragma warning(disable : 4996)

int rMax(int arr[], int idx) {
	if (idx == 0)
		return arr[0];

	int a = rMax(arr, idx - 1);

	if (a > arr[idx])
		return a;
	else
		return arr[idx];
}

int main() {
	int N, arr[20];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	printf("%d", rMax(arr, N - 1));

	return 0;
}