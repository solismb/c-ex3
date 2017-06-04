#include <stdio.h>

int main()
{
	int i, j;

	for (i = 1; i <= 6; i++) {
		for (j = 1; j <= 6; j++) {
			if ((i + j) % 5 == 0) {    //2個のサイコロの全ての和を5の倍数かチェック
				printf("%dと%d ", i, j);
			}
		}
	}
	puts("");

	return 0;
}
