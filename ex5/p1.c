#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double y;  // 時刻tにおける瞬時値
	double r;  // 乱数値
	int i;  // 時刻(単位=サンプル)

	srandom(time(NULL));  // 乱数の初期化

	// 時刻を0から2秒まで動かし、各時刻における瞬時値yを出力する
	for (i = 0; i < 44100 * 2; i++) {
		r = random();  // 0からRAND_MAXまでのいずれかの値がrに入る
		y = 1000.0 / RAND_MAX * (r - RAND_MAX / 2.0);
		printf("%d\n%d\n", (short)y, (short)y);
	}

	return 0;
}
