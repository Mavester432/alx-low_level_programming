#include <stdlib.h>
#include <time.h>
#include <stdio>
/**
 * main - This program will assign a random number to the variable n
 *
 * Return 0
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there 	
	return (0);
}
