#include <stdio.h>

/**
 * flip_bits - counts the number of bits to flip
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	/*initialization*/
	int i, s = 0;
	unsigned long int latest;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		latest = exclusive >> i;
		if (latest & 1)
			s++;
	}

	return (s);
}

