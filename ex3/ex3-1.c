#include <stdio.h>
#include <string.h>
#define N 20

/* メニュー画面 */
int menu()
{
	int m;

	printf("##### ソートと探索 #####\n");
	printf("\n数字を入力してメニューを選んでください\n");
	printf("1 : データ入力\n");
	printf("2 : 選択ソート\n");
	printf("3 : バブルソート\n");
	printf("4 : 探索\n");
	printf("5 : 結果表示\n");
	printf("6 : プログラム終了\n");

	printf("\nMenu number : ");
	do {
		if (scanf("%d", &m) != 1) {
			printf("メニューに対応した数字を入力してください\n");
			scanf("%*s");
			continue;
		}

		if (m >= 1 && m <= 6)
			break;
		printf("メニューに対応した数字を入力してください\n");
	} while (m < 1 || m > 6);

	return m;
}

/* データ個数、データ 入力 */
int getData(int in[N], int *n)
{
	int i = 0;

	// データ個数入力
	printf("データ個数を入力してください\n");
	do {
		if (scanf("%d", &*n) != 1) {
			printf("数字を入力してください\n");
			scanf("%*s");
			continue;
		}

		if (*n >= 1 && *n <= N)
			break;
		printf("無効な数値です。再度入力してください\n");
	} while (*n < 1 || *n > N);

	// データ入力
	printf("\nデータの入力:\n");
	for (i = 0; i < *n; i++) {
		if (scanf("%d", &in[i]) != 1) {
			printf("入力が無効です。再度入力してください\n");
			scanf("%*s");
			continue;
		}
	}

	return 1;		//  データ入力確認フラグ : 1
}

/* スワップ */
void swap(int *a, int *b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

/* 選択ソート */
int selectionSort(int in[N], int out[N], int n)
{
	int i, j;

	memcpy(out, in, sizeof(int) * N);  // outにinをコピー
	
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (out[i] > out[j])
				swap(&out[i], &out[j]);

	printf("\n\x1b[36m~~ ソート完了 ~~\n\n\x1b[39m");

	return 2;		// 選択ソートのフラグ : 2
}

/* バブルソート */
int bubbleSort(int in[N], int out[N], int n)
{
	int i, k;

	memcpy(out, in, sizeof(int) * N);  // outにinをコピー

	for (k = n - 1; k > 0; k--)
		for (i = 0; i < k; i++)
			if (out[i] > out[i+1])
				swap(&out[i], &out[i+1]);

	printf("\n\x1b[36m~~ ソート完了 ~~\n\n\x1b[39m");

	return 3;		// バブルソートのフラグ : 3
}

/* 探索 */
int search(int in[N], int n)
{
	int x, i, count = 0;

	printf("\n探索したい値を入力してください\n");

	// 探索したい数の入力
	do {
		if (scanf("%d", &x) != 1) {
			printf("数字を入力してください\n");
			scanf("%*s");
			continue;
		}
		break;
	} while (1);
	
	// マッチしたデータをカウント
	for (i = 0; i < n; i++)
		if (x == in[i])
			count++;

	return count;
}

/* 探索結果の表示 */
void printSearch(int c)
{
	printf("\n探索の結果\n %d 個ヒットしました\n", c);

	printf("\nEnterを押してください。メニューに戻ります。\n");
	getchar();		// 入力バッファの改行読み飛ばし
	getchar();
	
	return;
}

/* ソート結果の表示 */
void printData(int in[N], int out[N], int n, int flag)
{
	int i;

	if (flag == 2)
		printf("\n## 選択ソートの結果 ##\n");
	else
		printf("\n## バブルソートの結果 ##\n");
	
	printf("ソート前データ\n");
	for (i = 0; i < n; i++)
		printf("%d ", in[i]);
	puts("");

	printf("ソート後データ\n");
	for (i = 0; i < n; i++)
		printf("%d ", out[i]);
	puts("");

	printf("\nEnterを押してください。メニューに戻ります。\n");
	getchar();		//　入力バッファの改行読み飛ばし
	getchar();

	return;
}

int main()
{
	int in[N] = {0}, out[N] = {0};
	int i, n, m, flag = 0;

	do {
		m = menu();
		switch (m) {
		case 1:
			flag = getData(in, &n);
			break;
		case 2:
			if (flag == 1 || flag == 3)
				flag = selectionSort(in, out, n);
			else
				printf("\n\x1b[31m## まだデータが入力されていません ##\n\n\x1b[0m");
			break;
		case 3:
			if (flag == 1 || flag == 2)
				flag = bubbleSort(in, out, n);
			else
				printf("\n\x1b[31m## まだデータが入力されていません ##\n\n\x1b[0m");
			break;
		case 4:
			if (flag == 1 || flag == 2 || flag == 3)
				printSearch(search(in, n));
			else
				printf("\n\x1b[31m## まだデータが入力されていません ##\n\n\x1b[0m");
			break;
		case 5:
			if (flag == 2 || flag == 3)
				printData(in, out, n, flag);
			else if (flag == 1)
				printf("\n\x1b[31m## まだソートされていません ##\n\n\x1b[0m");
			else
				printf("\n\x1b[31m## まだデータが入力されていません ##\n\n\x1b[0m");
			break;
		}
	} while (m >= 1 && m <= 5);

	return 0;
}
