#include <stdio.h>

int main()
{
	int x, n;

	printf("10進数の正の整数の入力: ");
	do {
		scanf("%d", &n);
		if (n < 0) {   //負数の時、再度入力
			printf("無効です。再度入力してください。\n");
			printf("10進数の正の整数の入力: ");
		}
	} while (n < 0);

	if (n == 0)
		printf("0");
	
	while (n > 0) {
		x = n % 2;
		n /= 2;

		printf("%d", x);
	}
	puts("");

	return 0;
}		
