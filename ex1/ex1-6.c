#include <stdio.h>
#include <math.h>

int main()
{
	double x = 0.0, y;
	int i;

	printf("    x     y  |\n");
	do {
		y = sin(x);
		printf(" %5.2f %5.2f |", x, y);
		for (i = 0; i < (y + 1) * 15; i++)
			printf(" ");
		printf("*\n");
		x += 2.0 * M_PI / 21.0;
	} while (x <= 2 * M_PI);
	
	return 0;
}
