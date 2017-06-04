#include "common.c"

int main()
{
	FILE *fp;
	Book book[M];
	int n = 0;

	printf("### Inventory Search System ###\n");
			
	for (;;) {
		printf("\n----------------------------------------------\n");
		readData(fp, book, &n);
		bookSearch(book, &n);
	}

	return 0;
}
