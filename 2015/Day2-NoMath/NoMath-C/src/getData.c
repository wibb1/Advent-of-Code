#include <stdio.h>
#include "noMath.h"

int getData(){

	FILE *dataFile;
	char textStrings[MAXCHAR];
	char *filename = "/Users/willcampbell/workspace/Advent-of-code/2015/Day2-NoMath/NoMath-C/lib/input.txt";
	char *token;
	int intToken;
	int intTokens[MAXCHAR][3];
	int firstCount;
	int secondCount;
	const char *separator = "x";
	int swap;
	int swapCount;
	char *remainingString;

	dataFile = fopen(filename, "r");
	if (dataFile == NULL)
	{
		printf("Could not open file %s.\n", filename);
		return (1);
	}
	/* cycle through the file and collect the strings */
	firstCount = 0;
	while (fgets(textStrings, MAXCHAR, dataFile) != NULL)
	{
		token = strtok(textStrings, separator);
		secondCount = 0;
		while (token != NULL)
		{
			intToken = strtol(token, &remainingString, 10); /* converts the string to integer with base 10 */
			intTokens[firstCount][secondCount] = intToken; /* feeds the string into multidimentional array */
			token = strtok(NULL, separator); /* assigns NULL to token */
			secondCount++;
		}

		/* SORTARRAY GOES HERE */

		printf("\r");
		firstCount++;
	}
	fclose(dataFile);

}