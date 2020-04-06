#include <stdio.h>

#define IN  1    /* внутри слова */
#define OUT 0    /* снаружи слова */
#define isChHere 1
#define isntChHere 0
#define MAXWLEN  100 

main()
{
	int charInfo[MAXWLEN], countChar[MAXWLEN];
	int c, state, maxCh = 1, chCounter = 1;
	int chState = isntChHere;
	for (int i = 0; i < MAXWLEN; ++i)
		charInfo[i] = countChar[i] = 0;

	state = OUT;
	while ((c = getchar()) != EOF){

		int i = 0;

		while ((i <= chCounter) && (chState == isntChHere)) {
			if (charInfo[i] == c) {
				chState = isChHere;
				++(countChar[i]);
				if (maxCh < countChar[i]) 
					maxCh = countChar[i];
			};
			i++;
		}
		if (chState == isntChHere) {
			charInfo[chCounter++] = c;
		}else
			chState = isntChHere;
	}
	printf("%d %d\n", chCounter, maxCh);

	for (int i = maxCh; i >= 0; i--)
	{
		for (int j = 0; j < chCounter; j++)
		{
			if (countChar[j] > i)
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
	for (int i = 0; i < chCounter; i++)
	{
		printf("%c",charInfo[i]);
	}
	system("pause");
}