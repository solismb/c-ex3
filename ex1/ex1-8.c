#include <stdio.h>
#include <stdlib.h>

void lengthSort(int*,  int);
void checkTriangle(int*, int);

int main()
{
	int n, i;
	int *si;
	
	printf("棒の数: ");
	do {
		scanf("%d", &n);
		if (n < 3) {    // nが3未満のとき再入力
			printf("棒の数が足りません。再度入力してください。\n");
			printf("棒の数: ");
		}
	} while (n < 3);

	si = (int *)malloc(sizeof(int) * n);  //棒n本分の配列の動的確保
	if (si == NULL)
		exit(EXIT_FAILURE);

	printf("%d 本分の棒の長さの入力: \n", n);
	for (i = 0; i < n; i++)
		scanf("%d", &si[i]);

	lengthSort(si, n);  //棒の長さを大きい順にソート
	checkTriangle(si, n);  //三角形が出来るか判定

	return 0;
}

void lengthSort(int *psi, int n)
{
	int i, j, tmp;

	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (psi[i] < psi[j]) {
				tmp = psi[i];
				psi[i] = psi[j];
				psi[j] = tmp;
			}
		}
	}

	return;
}

void checkTriangle(int *psi, int n)
{
	int i = 0, max = 0;

	while (i < n) {
		if (psi[i] < psi[i+1] + psi[i+2]) {  //三角形の条件
			max = psi[i] + psi[i+1] + psi[i+2];  //最大周長
			break;	
		} else {
			i++;  //三角形の条件を満たせていないとき、一個ずらす
		}
	}

	if (max == 0)
		printf("三角形を作れませんでした。\n");
	else
		printf("%d, %d, %d の組み合わせの三角形で、周長は %d です。\n", psi[i], psi[i+1], psi[i+2], max);

	return;
}
