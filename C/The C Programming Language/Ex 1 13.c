#include <stdio.h>

#define IN  1    /* внутри слова */
#define OUT 0    /* снаружи слова */

#define MAXWLEN  100 

main()
{
	int wordInfo[MAXWLEN], wordStat[MAXWLEN];
	int c, state, wordLength, wCounter = 0, maxL = 0;

	for (int i = 0; i < MAXWLEN; ++i)
		wordInfo[i] = wordStat[i] = 0;

	state = OUT;
	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				if (maxL < wordLength) maxL = wordLength;
				wordInfo[wCounter++] = wordLength;
			}
		}
		else if (state == OUT) {
			state = IN;
			wordLength = 1;
		}
		else
			++wordLength;
	

	for (int i = 0; i < wCounter; i++)
	{
		for (int j = 0; j < maxL; j++)
		{
			if (wordInfo[i] > j)
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
	system("pause");
}