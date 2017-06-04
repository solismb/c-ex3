#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int setP, setC;  // プレイヤーの初期値,コンピュータの初期値

// プレイヤーの初期値を決める関数
void setPlayerNum()
{
	printf("\n##### プレイヤーの入力 #####\n");
	printf("1 から 20 までの好きな数を入力してください\n");
	
	do {
		printf("プレイヤー: ");
		scanf("%d", &setP);
		if (setP >= 1 && setP <= 20)
			break;
		printf("1 から 20 までの数を入力してください\n");
	} while (setP < 1 || setP > 20);
}

// コンピュータの初期値を決める関数
void setComputerNum()
{	
	srandom(time(0));
	setC = random() % 20 + 1;
}

// プレイヤーがコンピュータの数を決める入力関数
int playerInput()
{
	int pInput;

	printf("\n##### コンピュータの数を当てよう ######\n1 から 20 までの数を入力してください\n");

	do {
		printf("コンピュータの数を当てよう: ");
		scanf("%d", &pInput);
		if (pInput >= 1 && pInput <= 20)
			break;
		printf("1 から 20 までの数を入力してください\n");
	} while (pInput < 1 || pInput > 20);

	return pInput;
}

// コンピュータがプレイヤーの数を決める関数
int computerInput(int level)
{
	int cInput;

	printf("\n##### コンピュータのターン #####\n");
	
	srand((unsigned)time(NULL));

	if (level == 1)
		cInput = rand() % 20 + 1;  // 初級:ランダム
	if (level == 2)
		cInput = setP + (rand() % 11 - 5);  // 中級:プレイヤー初期値-5 ~ +5 をランダム
	if (level == 3)
		cInput = setP + (rand() % 7 - 3);  // 上級:プレイヤー初期値 -3 ~ +3 をランダム

	if (cInput > 20)
		cInput = cInput - 20;
	if (cInput < 1)
		cInput = 20 + cInput;
	
	return cInput;
}

// プレイヤーの入力とコンピュータの初期値の判定
int judgePlayer(int player)
{
	int result = 2;

	if (player == setC) {
		printf("\nあなたの勝ちです!\n");
		result = 1;
	} else if (player > setC) {
		printf("\n||残念、もっと小さい数です||\n\n");
	} else {
		printf("\n||残念、もっと大きい数です||\n\n");
	}

	return result;
}

// コンピュータの入力とプレイヤーの初期値の判定
int judgeComputer(int computer)
{
	int result = 1;

	printf("あなたは %d です\n", setP);
	printf("コンピュータは %d を選びました\n", computer);
	if (computer == setP) {
		printf("\nコンピュータがあたなの数を当てました。残念...\n");
	} else {
		printf("\nコンピュータは外しました。\n");
		result = 2;  // コンピュータが外したとき
	}
	
	return result;
}

// ゲーム1回戦分
int match(int level)
{
	int pnum, cnum, pr, cr;

	do {
		pnum = playerInput();
		pr = judgePlayer(pnum);
		if (pr == 1)  // プレイヤーが勝ちならbreak
			break;
		cnum = computerInput(level);
		cr = judgeComputer(cnum);
		if (cr == 1)  // コンピュータが勝ちならbreak
			break;
	} while (pr == 2 && cr == 2);

	return pr;  // 勝敗数カウントのためプレイヤーリザルトを返す
}

int startMenu()
{
	int m;
	
	printf("\n##### 数当てゲーム #####\n\n");
	printf("数字を入力してメニューを選んでください。\n");
	printf("1 : 数当てゲームをする\n");
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

// レベル選択画面メニュー
int levelMenu()
{
	int level;

	printf("\n##### コンピュータのレベルを選択しよう #####\n");
	printf("数字を入力してレベルを選択してください。\n");
	printf("1 : 初級\n");
	printf("2 : 中級\n");
	printf("3 : 上級\n");

	do {
		scanf("%d", &level);
		if (level >= 1 && level <= 3)
			break;
		printf("\n1, 2, 3 のいずれかを入力してください。\n");
	} while (level < 1 || level > 3);

	return level;
}

// 今までの戦績
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
	int m, win = 0, lose = 0, level, result, ans;

	do {
		m = startMenu();
		if (m == 1) {
			level = levelMenu();
			setPlayerNum();
			setComputerNum();
			result = match(level);  // 対戦後プレイヤーリザルト(1:勝ち, 2:負け)が返ってくる
			if (result == 1)  // プレイヤーが勝ちなら
				win++;
			else
				lose++;
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
