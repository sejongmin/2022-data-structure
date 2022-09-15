#include <stdio.h>
#pragma warning(disable : 4996)

void print(int N) {
	printf("%d\n", N % 10);
	if (N >= 10) print(N / 10);
}

int main() {
	int N;
	scanf("%d", &N);
	print(N);

	return 0;
}