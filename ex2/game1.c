#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int setPlayerHand()
{
	int phand;

	printf("\n#####プレイヤーの入力#####\n");
	printf("グー: 1, チョキ: 2, パー: 3\n");
	
	do {
		printf("プレイヤー: ");
		scanf("%d", &phand);
		if (phand >= 1 && phand <= 3)
			break;
		printf("\n1, 2, 3 のいずれかを入力してください。\n");
	} while (phand < 1 || phand > 3);

	return phand;
}

int setComputerHand()
{
	int chand;
	
	srand((unsigned)time(NULL));
	chand = rand() % 3 + 1;

	if (chand == 1)
		printf("\nあいて : グー\n");
	if (chand == 2)
		printf("\nあいて : チョキ\n");
	if (chand == 3)
		printf("\nあいて : パー\n");

	return chand;
}

// 勝ち : com == (player % 3) + 1
int judge(int player, int computer)
{
	int result;
	
	if (computer == (player % 3) + 1)  // 勝ち
		result = 1;
	else if (computer == player)  // あいこ
		result = 3;
	else  // 負け
		result = 2;
	
	return result;	
}

int match()
{
	int phand, chand, result;

	do {
		phand = setPlayerHand();
		chand = setComputerHand();
		result = judge(phand, chand);

		if (result == 1 || result == 2)
			break;
		printf("\nあいこです。もう一回入力\n");
	} while (result == 3);  // あいこならループ

	return result;
}

// 勝ち負け表示、プレイヤーの返事
int resultReply(int result)
{
	int ans;

	if (result == 1)
		printf("\nあなたの勝ち！\n");
	else
		printf("\nあなたの負け...\n");
	
	printf("\n1 : もう一度する\n");
	printf("2 : メニューに戻る\n");

	do {
		scanf("%d", &ans);
		if (ans == 1 || ans == 2)
			break;
		printf("\n1, 2 のいずれかを入力してください。\n");
	} while (ans < 1 || ans > 2);

	return ans;
}

int menu()
{
	int m;
	
	printf("\n##### じゃんけんゲーム #####\n\n");
	printf("数字を入力してメニューを選んでください。\n");
	printf("1 : じゃんけんをする\n");
	printf("2 : 成績を見る\n");
	printf("3 : ゲームを終わる\n");
	printf("\nメニューの数字を入力してください: ");

	do {
		scanf("%d", &m);
		if (m >= 1 && m <= 3)
			break;
		printf("\n1, 2, 3 のいずれかを入力してください。\n");
	} while (m < 1 || m > 3);

	return m;
}

int printScore(int win, int lose)
{
	int a;

	printf("\n#####今までの成績#####\n");
	if (win == 0 && lose == 0)
		printf("まだプレイしてません。\n");
	else
		printf("勝ち: %d 回, 負け: %d 回\n", win, lose);

	printf("\nどうしますか?\n");
	printf("1 : メニューに戻る\n");
	printf("2 : ゲーム終了\n");
	
	do {
		scanf("%d", &a);
		if (a == 1 || a == 2)
			break;
		printf("\n1 か 2を入力してください\n");
	} while (a > 1 || a < 2);

	return a;
}

int main()
{
	int m, win = 0, lose = 0, result, ans;

	do {
		m = menu();
		if (m == 1) {
			do {
				result = match();
				if (result == 1)
					win++;
				else
					lose++;
				ans = resultReply(result);  // もう一度orメニュー
			} while (ans == 1);  // もう一度なら繰り返し
		}
		if (m == 2) {
			ans = printScore(win, lose);  // メニューor終了
			if (ans == 2)  // 終了ならbreakする
				break;
		}
		if (m == 3)
			break;
	} while (m == 1 || m == 2);

	return 0;
}
