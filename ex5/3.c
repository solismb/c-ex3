#include <stdio.h>
#include <math.h>
//#define F 440
#define LEN 4  // 再生時間
#define A 20000
#define SAMPLE_RATE 44100  // wavファイルのサンプリング周波数

int main()
{
	double s;
	double y;
	double F = 440.0;
	double theta;

	// 時刻を0からLEN秒まで動かし、各時刻における瞬時値yを出力する
	theta = 0.0;
	for (s = 0; s <= LEN; s += 1.0 / SAMPLE_RATE) {
		F = (110.0 * s) + 440.0;
		y = A * sin(theta);
		printf("%d\n%d\n", (short)y, (short)y);
		theta += 2.0 * M_PI * F / SAMPLE_RATE;
	}

	return 0;
}
