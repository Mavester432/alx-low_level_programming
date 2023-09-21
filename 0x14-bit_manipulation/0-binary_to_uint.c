#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: char string
 * Return: converted decimal number or 0 if there is an unconvertable char
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	unsigned int base = 1;
	int length = 0;

	if (b == NULL)
	return (0);

while (b[length])

{
if (b[length] != '0' && b[length] != '1')
return (0);
length++;
}

while (length > 0)

{
	length--;
	if (b[length] == '1')
	result += base;
base *= 2;
}

return (result);
}
