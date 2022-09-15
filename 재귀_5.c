#include <stdio.h>
#pragma warning(disable : 4996)

void hanoi(int N, char A, char B, char C) {
	if (N == 1)
		printf("%c %c\n", A, C);
	else {
		hanoi(N - 1, A, C, B);
		printf("%c %c\n", A, C);
		hanoi(N - 1, B, A, C);
	}
}


int main() {
	int N;
	scanf("%d", &N);
	hanoi(N, 'A', 'B', 'C');

	return 0;
}