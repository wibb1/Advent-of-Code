

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