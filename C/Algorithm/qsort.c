#include <stdio.h>
void swap(int arr[], int i, int j)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void qsort1(int arr[], int left, int right)
{
    int i;
    int last;

    if (left >= right)
    {
        return;
    }

    swap(arr, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (arr[i] < arr[left])
        {
            swap(arr, ++last, i);
        }
    }

    swap(arr, left, last);
    qsort1(arr, left, last - 1);
    qsort1(arr, last + 1, left);
}
void qsort2(int arr[], int left, int right)
{
    int i;
    int last;

    if (left >= right)
    {
        return;
    }

    swap(arr, left, (left + right) / 2);

    last = left;
    for (i = last + 1; i <= right; i++)
    {
        if (arr[i] < arr[left])
        {
            swap(arr, ++last, i);
        }
    }

    swap(arr, left, last);
    qsort2(arr, left, last - 1);
    qsort2(arr, last + 1, left);
}
void qsort3(int arr[], int left, int right)
{
    int i;
    int last;

    if (left >= right)
    {
        return;
    }
    swap(arr, left, (left + right) / 2);
    last = left;
    for (int i = last + 1; i <= right; i++)
    {
        if (arr[i] < arr[left])
        {
            swap(arr, ++last, i);
        }
    }
    swap(arr, left, last);
    qsort3(arr, left, last - 1);
    qsort3(arr, last + 1, left);
}

void qsort4(int arr[], int left, int right)
{
    int i;
    int last;
    if (left >= right)
    {
        return;
    }
    swap(arr, left, (left + right) / 2);
    last = left;
    for (int i = last + 1; i <= right; i++)
    {
        if (arr[i] < arr[left])
        {
            swap(arr, ++last, i);
        }
    }
    swap(arr, left, last);
    qsort4(arr, left, last - 1);
    qsort4(arr, last + 1, left);
}

void qsort4(int arr[], int left, int right)
{
    int i;
    int last;
    if (left >= right)
    {
        return;
    }
    swap(arr, left, (left + right) / 2);
    last = left;
    for (int i = last + 1; i <= right; i++)
    {
        if (arr[i] < arr[left])
        {
            swap(arr, ++last, i);
        }
    }
    swap(arr, left, last);
    qsort4(arr, left, last - 1);
    qsort4(arr, last + 1, left);
}

void qsort5(int arr[], int left, int right)
{
    int i;
    int last;

    if (left >= right)
    {
        return;
    }

    swap(arr, left, (left + right) / 2);
    last = left;

    for (int i = last + 1; i <= right; i++)
    {
        if (arr[i] < arr[left])
        {
            swap(arr, ++last, i);
        }
    }

    swap(arr, left, last);
    qsort5(arr, left, last - 1);
    qsort5(arr, last + 1, left);
}

void qsort6(int arr[], int left, int right)
{
    int i;
    int last;
    if (left >= right)
    {
        return;
    }

    swap(arr, left, (left + right) / 2);
    last = left;
    for (int i = last + 1; i <= right; i++)
    {
        if (arr[i] < arr[left])
        {
            swap(arr, ++last, i);
        }
    }

    swap(arr, left, last);
    qsort6(arr, left, last - 1);
    qsort6(arr, last + 1, left);
}

void qsort7(int arr[], int left, int right)
{
    int i;
    int last;
    if (left >= right)
    {
        return;
    }

    swap(arr, left, (left + right) / 2);
    last = left;
    for (int i = last + 1; i <= right; i++)
    {
        if (arr[i] < arr[left])
        {
            swap(arr, ++last, i);
        }
    }

    swap(arr, left, last);
    qsort7(arr, left, last - 1);
    qsort7(arr, last + 1, left);
}
// void qsort(double arr[], int left, int right)
//{
//	int i, last;
//
//	if (left >= right)
//		return;
//
//	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^\n");
//	for (int j = 0; j < 10; j++)
//	{
//		printf("(%d)%d ", j, arr[j]);
//	}
//
//	swap(arr, left, (left + right) / 2);
//
//	printf("\nswap(arr[left(%d)] = %d, arr[i(%d)] = %d)\n", left, arr[left], (left+right)/2, arr[(left + right) / 2]);
//	for (int j = 0; j < 10; j++)
//	{
//		printf("(%d)%d ", j, arr[j]);
//	}
//	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^\n");
//
//	last = left;
//
//	for (i = left + 1; i <= right; i++)
//	{
//		if (arr[i] < arr[left])
//		{
//			printf("\n----------------------------------\n");
//			printf("last = %d\n", last);
//			printf("i = %d\n", i);
//			printf("left = %d\n", left);
//			printf("right = %d\n", right);
//
//			for (int j = 0; j < 10; j++)
//			{
//				printf("(%d)%d ", j, arr[j]);
//			}
//
//			printf("\nif(arr[i(%d) = %d] < arr[left(%d) = %d])", i, arr[i], left, arr[left]);
//			swap(arr, last++, i);
//			printf("\nswap(arr[++last(%d)] = %d, arr[i(%d)] = %d)\n", last, arr[last], i, arr[i]);
//
//			for (int j = 0; j < 10; j++)
//			{
//				printf("(%d)%d ", j, arr[j]);
//			}
//			printf("\n----------------------------------");
//		}
//	}
//
//	swap(arr, left, last);
//	qsort(arr, left, last - 1);
//	qsort(arr, last + 1, right);
//}

main()
{

    int arr[10] = {4, 6, 7, 12, 53, 12, 5, 6, 78, 9};

    qsort7(arr, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    system("pause");
}