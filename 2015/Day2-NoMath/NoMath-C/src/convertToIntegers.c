#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noMath.h"

int convertToIntegers(String token)
{
char *remainingString;

    return strtol(token, &remainingString, 10);
    // converts the string to integer with base 10

}