#include<stdio.h>
int fahr_to_cel(int fahr){
	int celsius = ((5.0 / 9.0)*(fahr - 32.0));
	return celsius; 
}
main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 50;

	fahr = lower;

	printf("\tFarengate to Celsius\n");
	while (fahr <= upper) {
		celsius = fahr_to_cel(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	system("pause");
}