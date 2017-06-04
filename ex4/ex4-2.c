#include <stdio.h>
#include <string.h>
#include <ctype.h>

//enum Mode {reset, print, add, sub, twice, num} mode;
enum Mode {add, sub} mode;

int workCalc(char str[], int *ans, int *flag)
{
	int i;

	if (strcmp(str, "reset") == 0) {
		*ans = 0;
		return 0;
	}
	if (strcmp(str, "print") == 0) {
		printf("ans = %d\n", *ans);
		return 0;
	}
	if (strcmp(str, "+") == 0) {
		printf("~ 加算モード ~\n");
		mode = add;
		return 0;
	}
	if (strcmp(str, "-") == 0) {
		printf("~ 減算モード ~\n");
		mode = sub;
		return 0;
	}
	if (strcmp(str, "twice") == 0) {
		*ans *= 2;
		return 0;
	}
			
	if (str[0] == '-') {
		for (i = 1; i < strlen(str); i++)
			if (!isdigit(str[i]))
				*flag = 1;
	} else {
		for (i = 0; i < strlen(str); i++)
			if (!isdigit(str[i]))
				*flag = 1;
	}
				

	//temp = atoi(str);
	return atoi(str);
}

int main()
{
	mode = add;
	int ans = 0, temp = 0, flag = 0;
	char str[30];

	printf("### Easy Calculator Program ###\n");

	while (1) {
		scanf("%s", str);
		while (1) {
			temp = workCalc(str, &ans, &flag);
			if (flag == 1) {
				printf("syntax error\n");
				scanf("%s", str);
				flag = 0;
			}
			else
				break;
		}
		if (mode == add)
			ans += temp;
		if (mode == sub)
			ans -= temp;
		//temp = atoi(str);
		//workCalc(&ans, str);
		//ans = calculate(temp, ans);
	}

	return 0;
}
