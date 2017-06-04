#include <stdio.h>

int main()
{
	int i, n, y = 0, tmp = 0;

	printf("整数nの入力: ");
	do {
		scanf("%d", &n);
		if (n <= 0) {    //入力した値が0または負数の時、再度入力させる
			printf("無効です。再度入力してください。\n");
			printf("整数nの入力: ");
		}
	} while (n <= 0);

	for (i = 1; i <= n; i++) {
		tmp += i;
		y += tmp;
	}

	printf("y = %d\n", y);

	return 0;
}
