#include <stdio.h>

int main()
{
    int days, n, i;
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	printf("日数の入力: ");
	do {
		scanf("%d", &days);
		if (days < 0 || days > 365) {
			printf("無効です。再度入力してください。\n");
			printf("日数の入力: ");
		}
	} while (days < 0 || days > 365);

	n = days;
	
	if (days == 365) {
		printf("365日後は 1月1日\n");
	} else {
		for (i = 0; days >= month[i]; i++) {
			days -= month[i];
		}
		
		printf("%d日後は %d月%d日\n", n, i+1, days+1);
	}

	return 0;
}
