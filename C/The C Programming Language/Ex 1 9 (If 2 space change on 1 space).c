#include<stdio.h>

main() {
	int counter = 0;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			counter++;
	}
	printf("%d\n", counter);
	system("pause");
}