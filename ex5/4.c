#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define F 440
#define LEN 5  // 再生時間
#define A 20000
#define SAMPLE_RATE 44100  // wavファイルのサンプリング周波数

int main()
{
	double t;  // 時刻(単位 = 秒)
	double y, l, r;

	// 時刻を0からLEN秒まで動かし、各時刻における瞬時値yを出力する
	for (t = 0; t <= LEN; t += 1.0 / SAMPLE_RATE) {
		y = A * sin(2.0 * M_PI * F * t);
		l = ((LEN - t) / LEN) * y;
		r = (t / LEN) * y;
		printf("%d\n%d\n", (short)l, (short)r);
	}

	return 0;
}
