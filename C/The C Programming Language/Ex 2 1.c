#include<limits.h>
#include<float.h>
#include<stdio.h>
main()
{

	printf("char -\t\t\t %d to %d \n", CHAR_MAX, CHAR_MIN);
	printf("unsigned char -\t\t %d\n", UCHAR_MAX);
	printf("int -\t\t\t %d to %d \n", INT_MAX, INT_MIN);
	printf("unsigned int -\t\t %u\n", UINT_MAX);
	printf("short -\t\t\t %d to %d \n", SHRT_MAX, SHRT_MIN);
	printf("unsigned short -\t %u\n", USHRT_MAX);
	printf("long -\t\t\t %d to %d \n", LONG_MAX, LONG_MIN);
	printf("unsigned long -\t\t %lu\n", ULONG_MAX);
	printf("--------------------------------\n");
	printf("float -\t\t %.1f to %f\n", FLT_MAX, FLT_MIN);
	printf("unsigned float -\t\t %.1f to %.*f\n", FLT_MAX, FLT_MIN);
	system("pause");
}
