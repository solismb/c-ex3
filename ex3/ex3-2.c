#include <stdio.h>
#define N 10

/* 行列の要素値入力 */
void input_mat(int n, int X[][N])
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (scanf("%d", &X[i][j]) != 1) {
				printf("入力が無効です。再入力してください。\n");
				scanf("%*s");
				continue;
			}
		}
	}

	return;
}

/* 行列の和 */
void s_mat(int n, int A[][N], int B[][N], int C[][N])
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			C[i][j] = A[i][j] + B[i][j];

	return;
}

/* 行列の積 */
void m_mat(int n, int A[][N], int B[][N], int C[][N])
{
	int i, j, k;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				C[i][j] += A[i][k] * B[k][j];

	return;
}

/* 結果表示 */
void print_mat(int n, int X[][N])
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%4d", X[i][j]);
		}
		puts("");
	}
	
	return;
}

int main()
{
	int A[N][N] = {0}, B[N][N] = {0}, sum[N][N] = {0}, pro[N][N] = {0};
	int n;

	printf("行列の次数の入力(最大10) : ");
	do {
		if (scanf("%d", &n) != 1) {
			printf("数字を入力してください\n");
			scanf("%*s");
			continue;
			}
		if (n >= 1 && n <= N)
			break;
		printf("無効な数値です。再度入力してください\n");
	} while (n < 1 || n > N);

	printf("\n行列 A の入力\n");
	input_mat(n, A);
	printf("\n行列 B の入力\n");
	input_mat(n, B);

	s_mat(n, A, B, sum);
	m_mat(n, A, B, pro);
	
	printf("\n=== A + B ===\n");
	print_mat(n, sum);
	
	printf("\n=== A * B ===\n");
	print_mat(n, pro);

	return 0;
}
