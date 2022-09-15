#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int modulo(int a, int b) {
	if (a >= b)
		modulo(a - b, b);
	else
		return a;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));

	return 0;
}