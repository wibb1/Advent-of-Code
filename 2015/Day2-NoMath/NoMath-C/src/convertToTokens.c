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