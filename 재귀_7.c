#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int find(int N, char str[], char S, int cnt) {
	if (N == strlen(str))
		return cnt;
	if (str[N] == S)
		cnt++;
	find(N + 1, str, S, cnt);
}


int main() {
	char str[101];
	char S;
	int cnt = 0;

	scanf("%s", str);
	getchar();
	scanf("%c", &S);

	printf("%d", find(0, str, S, cnt));
}