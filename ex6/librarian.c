#include "common.c"

void login(char []);                               // パスワード認証
void bookLend(FILE *, Book [], int *);             // 貸出処理
void bookReturn(FILE *, Book [], int *);           // 返却処理
void bookRegistration(FILE *, Book [], int *);     // 追加登録
int menu();

int main()
{
	FILE *fp;
	Book book[M];
	char pass[] = "login";
	int m, n = 0;

	login(pass);
	readData(fp, book, &n);
	printf("\n### Welcome to Library System ###\n");
	
	do {
		m = menu();
		switch (m) {
		case 1:
			getchar();  // 改行読み飛ばし
			bookSearch(book, &n);
			break;
		case 2:
			bookLend(fp, book, &n);
			break;
		case 3:
			bookReturn(fp, book, &n);
			break;
		case 4:
			bookRegistration(fp, book, &n);
			break;
		case 5:
			// 終了
			break;
		default:
			printf("Error.\n");
			break;
		}
	} while (m >= 1 && m <= 4);	
			
	return 0;
}

void login(char pass[])
{
	char str[N];
	int miss = 0;

	printf("Login Menu\n");

	do {
		printf("password : ");
		scanf("%s", str);

		if (strcmp(pass, str) == 0) {
			break;
		} else {
			printf("パスワードが違います.\n");
			miss++;			
			if (miss == 3) {
				printf("エラーが起きました. プログラムを終了します.\n");
				exit(EXIT_FAILURE);
			}
		}
	} while (miss < 3);

	return;
}

int menu(void)
{
	int m;

	printf("\n----------------------------------------------\n");
	printf("数字を入力してメニューを選んでください.\n"
		   "1 : 在庫検索\n"
		   "2 : 本の貸し出し\n"
		   "3 : 本の返却\n"
		   "4 : 追加登録\n"
		   "5 : 終了\n"
		);

	do {
		printf("\nMenu number : ");
		scanf("%d", &m);
		if (m >= 1 && m <= 5)
			break;
		printf("メニューに対応した数字を入力してください.\n");
	} while (m < 1 || m > 5);

	printf("----------------------------------------------\n");
	
	return m;
}			

void bookLend(FILE *fp, Book book[], int *n)
{
	int id, i;

	readData(fp, book, n);

	printf("\n貸し出す本の管理番号を入力してください.\n"
		   "ID : ");
	scanf("%d", &id);

	for (i = 0; i < M && i < *n; i++) {
		if (id == book[i].id) {
			if (book[i].isLend == 1) {
				// 現在貸出中
				printf("タイトル : %s\nは現在貸出中です.\n", book[i].title);
				return;
			} else {
				// 在庫有り(0) -> 貸出中(1)に変更
				printf("タイトル : %s\nを貸出しました.\n", book[i].title);
				book[i].isLend = 1;
				writeData(fp, book, n);
				return;
			}
		}
	}
	printf("該当するデータは見つかりません.\n");
	
	return;
}

void bookReturn(FILE *fp, Book book[], int *n)
{
	int id, i;

	readData(fp, book, n);

	printf("\n返却する本の管理番号を入力してください.\n"
		   "ID : ");
	scanf("%d", &id);

	for (i = 0; i < M && i < *n; i++) {
		if (id == book[i].id) {
			if (book[i].isLend == 1) {
				// 貸出中(1) -> 在庫有り(0)に変更
				printf("タイトル : %s\nは返却されました.\n", book[i].title);
				book[i].isLend = 0;
				writeData(fp, book, n);
				return;
			} else {
				// 現在在庫有り
				printf("タイトル : %s\nは既に返却されています.\n", book[i].title);
				return;
			}
		}
	}
	printf("該当するデータは見つかりません.\n");

	return;
}

void bookRegistration(FILE *fp, Book book[], int *n)
{
	int i = 0;

	getchar();  // 改行読み飛ばし

	printf("\n追加したいデータのタイトルを入力してください :\n");
	while ((book[*n].title[i] = getchar()) != '\n') i++;
	book[*n].title[i] = '\0';

	i = 0;
		
	printf("著者名を入力してください :\n");
	while ((book[*n].author[i] = getchar()) != '\n') i++;
	book[*n].author[i] = '\0';

	book[*n].id = (*n) + 1;
	book[*n].isLend = 0;
	// 登録データ数の更新
	(*n)++;
	
	writeData(fp, book, n);
	printf("\nデータを追加しました.\n");
	printf("登録したデータの管理番号は\nID : %d\nとなります.\n", *n);

	return;
}
