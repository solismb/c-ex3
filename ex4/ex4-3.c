#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 128
#define M 15

void sortFormula(char input[], char symbol[], char variable[][M], char constant[][M], int *vl, int *cl, int *sl)
{
	int i = 0, now = 0;
	char temp[M], check[] = "=+-*/()";

	do {
		temp[i] = input[now];
		if (isspace(input[now]) != 0) {
			temp[i] = '\0';
			if (isspace(input[now]) != 0 && isspace(input[now + 1]) == 0) {
				switch (checkFormula(temp, check)) {
				case 1:
					symbol[*sl] = temp[i-1];
					(*sl)++;
					break;
				case 2:
					strcpy(constant[*cl], temp);
					(*cl)++;
					break;
				case 3:
					strcpy(variable[*vl], temp);
					(*vl)++;
					break;
				default:
					printf("error\n");
				}
			i = 0;
			}
			
		} else {
			i++;
		}
		now++;
	} while (input[now] != '\0');		
	
	return;
}

int checkFormula(char temp[], char check[])
{
	int i, flag = 2;

	// 記号かチェックする
	for (i = 0; i < sizeof(check); i++)
		if (temp[0] == check[i])
			return 1;

	// 定数かチェックする
	for (i = 0; temp[i] != '\0'; i++)
		if (isdigit(temp[i]) == 0)
			flag = 3;

	return flag;
}

void printList(char variable[][M], char constant[][M], char symbol[], int vl, int cl, int sl)
{
	int i;

	for (i = 0; i < vl; i++)
		printf("【変数: %s 】\n", variable[i]);
	printf("   ... ...\n");
	for (i = 0; i < cl; i++)
		printf("【定数: %s 】\n", constant[i]);
	printf("   ... ...\n");
	for (i = 0; i < sl; i++)
		printf("【記号: %c 】\n", symbol[i]);

	return;
}

int main()
{
	char input[N], symbol[N];
	char variable[N][M], constant[N][M];
	int i, vl = 0, cl = 0, sl = 0;

	printf("please input formula :\n");
	fgets(input, N, stdin);

	sortFormula(input, symbol, variable, constant, &vl, &cl, &sl);

	printf("\nsort list\n");
	printList(variable, constant, symbol, vl, cl, sl);
	
	return 0;
}
