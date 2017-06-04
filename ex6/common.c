#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define M 500

typedef struct book {
	int id;
	char title[N];
	char author[N];
	int isLend;
} Book;

/* データファイルからデータ読み込み */
void readData(FILE *fp, Book book[], int *n)
{

	int i;

	if ((fp = fopen("data.txt", "r")) == NULL) {
		printf("File can not open.\n");
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%d\n", n);

	for (i = 0; i < M && i < *n; i++) {
		fscanf(fp, "%d\n", &book[i].id);
		fgets(book[i].title, N, fp);
		book[i].title[strlen(book[i].title) - 1] = '\0';    // 闇の処理
		fgets(book[i].author, N, fp);
		book[i].author[strlen(book[i].author) - 1] = '\0';  // 闇の処理
		fscanf(fp, "%d\n", &book[i].isLend);
	}

	fclose(fp);

	return;
}

/* データファイルを配列bookの内容に書き込み */
void writeData(FILE *fp, Book book[], int *n)
{
	int i;

	if ((fp = fopen("data.txt", "w")) == NULL) {
		printf("File can not open.\n");
		exit(EXIT_FAILURE);
	}

	fprintf(fp, "%d\n", *n);
	
	for (i = 0; i < M && i < *n; i++) {
		fprintf(fp, "%d\n", book[i].id);
		fprintf(fp, "%s\n", book[i].title);
		fprintf(fp, "%s\n", book[i].author);
		fprintf(fp, "%d\n", book[i].isLend);
	}

	fclose(fp);

	return;
}

/* 在庫検索 */
void bookSearch(Book book[], int *n)
{
	int i = 0;
	char str[N], lend[N];

	//getchar();
	
	printf("\n検索したいタイトルを入力してください.\n"
		   "タイトル : ");
	while ((str[i] = getchar()) != '\n') i++;
	str[i] = '\0';
	//fgets(str, N, stdin);

	for (i = 0; i < M && i < *n; i++) {
		if (strcmp(str, book[i].title) == 0) {
			if (book[i].isLend == 0)
				strcpy(lend, "在庫あり");
			else
				strcpy(lend, "貸出中");
			printf("\nID : %d\n"
				   "タイトル : %s\n"
				   "著者 : %s\n"
				   "状態 : %s\n"
				   , book[i].id, book[i].title, book[i].author, lend);
			return;
		}
	}
	printf("\"%s\"に該当するタイトルは見つかりません.\n", str);
	
	return;
}
