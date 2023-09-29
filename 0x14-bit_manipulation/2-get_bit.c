#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to search
 * @index: index of the bit
 *
 * Return: final value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	/*initialize the values*/
	int bit;

	if (index > 63)
		return (-1);

	bit = (n >> index) & 1;

	return (bit);
}


