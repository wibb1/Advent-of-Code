#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noMath.h"



int main()
{
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
	int area = 0;
	int side1;
	int side2;
	int side3;
	int ribbon = 0;

	

	// "../lib/input.txt";
	// "/./../lib/input.txt"
	// "/./../src/main.c"
	// open the file and check for error

	dataFile = fopen(filename, "r");
	if (dataFile == NULL)
	{
		printf("Could not open file %s.\n", filename);
		return (1);
	}
	// cycle through the file and collect the strings 
	firstCount = 0;
	while (fgets(textStrings, MAXCHAR, dataFile) != NULL)
	{
		token = strtok(textStrings, separator);
		secondCount = 0;
		while (token != NULL)
		{
			intToken = strtol(token, &remainingString, 10); 
			// converts the string to integer with base 10 
			intTokens[firstCount][secondCount] = intToken; 
			// feeds the string into multidimentional array 
			token = strtok(NULL, separator); // assigns NULL to token 
			secondCount++;
		}

		do
		{
			swapCount = 0;
			for (int i = 0; i < 2; i++)
			{
				if (intTokens[firstCount][i] > intTokens[firstCount][i + 1])
				{
					swap = intTokens[firstCount][i];
					intTokens[firstCount][i] = intTokens[firstCount][i + 1];
					intTokens[firstCount][i + 1] = swap;
					swapCount++;
				}
			}
		} while (swapCount > 0);

		printf("\r");
		firstCount++;
	}
	fclose(dataFile); 

	

	for (int i = 0; i < MAXCHAR; i++)
	{
		/*
		Part1
		*/

		side1 = intTokens[i][0] * intTokens[i][1];
		side2 = intTokens[i][0] * intTokens[i][2];
		side3 = intTokens[i][1] * intTokens[i][2];
		area += 2 * (side1 + side2 + side3) + side1;

		/*
		Part 2
		*/

		ribbon += (intTokens[i][0] + intTokens[i][1]) * 2;
		ribbon += intTokens[i][0] * intTokens[i][1] * intTokens[i][2];
	}

	printAnswers(area, ribbon);

	return (0);
}