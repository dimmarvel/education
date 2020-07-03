#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define HEX 16.

int z_htoi(const char* str)
{
	int res = 0;
	int c = 0;
	int len = strlen(str);
	int i = len - 1;
	int indx = 0;
	
	while(i != -1){
		switch (toupper(str[i]))
		{
		case 'A': c = 10; break;
		case 'B': c = 11; break;
		case 'C': c = 12; break;
		case 'D': c = 13; break;
		case 'E': c = 14; break;
		case 'F': c = 15; break;
		default:
			if (str[i] >= '0' && str[i] <= '9') 
			{
				c = str[i] - '0';
				break;
			}
			break;
		}
		double temp = pow(HEX, indx++);
		res += c * ((temp == 0.) ? 0 : temp);
		i--;
	}

	return res;
}

main() {
	char str[1000];
	gets(str);
	int res = z_htoi(str);
	printf("%d\n", res);
	system("pause");
}