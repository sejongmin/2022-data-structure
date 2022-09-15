#include <stdio.h>
#pragma warning(disable : 4996)

void print(int N) {
	if (N >= 10) print(N / 10);
	printf("%d\n", N % 10);
}

int main() {
	int N;
	scanf("%d", &N);
	print(N);

	return 0;
}