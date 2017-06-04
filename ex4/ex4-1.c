#include <stdio.h>
#include <ctype.h>
#define N 500

void wordCount()
{
	int cnum = 0, word = 0, line = 0, i = 0, flag = 0;
	char str[N] = {0};

	while ((str[i] = getchar()) != EOF) {
		cnum++;
		if (isspace(str[i]) != 0) {
			cnum--;
			if (flag != 1)
				word++;
			flag = 1;
		} else {
			flag = 0;
		}
		if (str[i] == '\n')
			line++;
		i++;
	}

	printf("\n文字数 = %d\n単語数 = %d\n行数  = %d\n", cnum, word, line);

	return;
}

int main()
{
	//int cnum = 0, word = 0, line = 0;

	printf("英単語の入力(Ctrl+dで入力終了):\n");

	wordCount();

	return 0;
}
