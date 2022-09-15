#include <stdio.h>
#pragma warning(disable : 4996)

void gcd(int A, int B) {
	if (B == 0)
		printf("%d", A);
	else
		gcd(B, A % B);
}


int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	gcd(A, B);

	return 0;
}