#include<stdio.h>

main() {
	//Ex 1 1
	printf("Hello, world.\n");
	printf("--------------------------\n");
	//Ex 1 2
	printf("\aHello\n");

	//Ex 1 3
	printf("--------------------------\n");
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 50;

	fahr = lower;

	printf("\tFarengate to Celsius\n");
	while (fahr <= upper) {
		celsius = (5.0 / 9.0)*(fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	//Ex 1 4
	printf("--------------------------\n");

	lower = 0;
	upper = 300;
	step = 50;

	celsius = lower;

	printf("\tCelsius to Farengate\n");
	while (celsius <= upper) {
		fahr = celsius*(5.0/9.0)+32;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	system("pause");
}