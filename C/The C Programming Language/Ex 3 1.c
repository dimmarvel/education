#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binsearch(int element, int arr[], int size)
{
	int mid;
	int lower = 0;
	int high = size - 1;

	while (lower <= high)
	{
		mid = (high + lower) / 2;
		if (element < arr[mid])
		{
			high = mid - 1;
		}
		else if (element > arr[mid])
		{
			lower = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && x != v[mid]) {
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if (x == v[mid])
		return mid;
	else
		return -1;
}

main()
{
	int mas[10];
	int i;
	clock_t clock1;
	clock_t clock2;

	for (i = 0; i < 10; i++)		
		mas[i] = i;

	clock1 = clock();
	binsearch(1, mas, 10);
	clock2 = clock();
	printf("binsearch() time = %lu\n", (unsigned long int)(clock2 - clock1));

	clock1 = clock();
	binsearch2(1, mas, 10);
	clock2 = clock();
	printf("binsearch2() time = %lu\n", (unsigned long int)(clock2 - clock1));
	system("pause");
}