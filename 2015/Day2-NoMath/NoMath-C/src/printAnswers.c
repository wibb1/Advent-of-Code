#include <stdio.h>
#include <stdlib.h>
#include "noMath.h"

/*********************************************************
 * 
 * Function:  printAnswers
 * 
 * Purpose:   Prints the answers
 * 
 * Parameters:  area - the area of wrapping paper required
 *              ribbon - the length of ribon calculated
 * 
 * Returns:   Nothing (call by reference)
 * 
 * *******************************************************/

void printAnswers(int area, int ribbon){
	printf("The area of wrapping papper is %d\n", area);
	printf("The length of ribbon is %d\n", ribbon);
}