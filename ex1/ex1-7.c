#include <stdio.h>
#include <math.h>

int main()
{
	float x1, y1, x2, y2, x3, y3;
	float ab, bc, ca;
	
	printf("input x1 y1 : ");
	scanf("%f %f", &x1, &y1);
	printf("input x2 y2 : ");
	scanf("%f %f", &x2, &y2);	
	printf("input x3 y3 : ");
	scanf("%f %f", &x3, &y3);		

	ab = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	bc = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	ca = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

	if (ab == bc && bc == ca && ca == ab)
		printf("正三角形です\n");
	else if (((ca*ca == ab*ab + bc*bc) || (bc*bc == ab*ab + ca*ca) || (ab*ab == bc*bc + ca*ca)) && (ab == bc || bc == ca || ca == ab))
		printf("直角二等辺三角形です\n");
	else if ((ca*ca == ab*ab + bc*bc) || (bc*bc == ab*ab + ca*ca) || (ab*ab == bc*bc + ca*ca))
		printf("直角三角形です\n");
	else if (ab == bc || bc == ca || ca == ab)
		printf("二等辺三角形です\n");
	else
		printf("三角形です\n");

	printf("%f %f %f\n", ab, bc, ca);

	return 0;
}
