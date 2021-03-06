#include <stdio.h>
#include <math.h>
#define F 880  // sin波の周波数
#define LEN 2  // 再生時間
#define A 5000  // sin波の振幅
#define SAMPLE_RATE 44100  // wavファイルのサンプリング周波数

int main()
{
	double t;  // 時刻(単位 = 秒)
	double y;  // 時刻tにおける瞬時値

	// 時刻を0からLEN秒まで動かし、各時刻における瞬時値yを出力する
	for (t = 0; t <= LEN; t += 1.0 / SAMPLE_RATE) {
		y = A * sin(2.0 * M_PI * F * t);
		printf("%d\n%d\n", (short)y, (short)y);
	}

	return 0;
}
