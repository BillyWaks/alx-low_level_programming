#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: string contains the binary number
 *
 * Return: the value of unsigned int
 */

unsigned int binary_to_uint(const char *b)
{
	/*initialization*/
	int n;
	unsigned int d_val = 0;

	if (!b)
		return (0);

	for (n = 0; b[n]; n++)
	{
		if (b[n] < '0' || b[n] > '1')
			return (0);
		d_val = 2 * d_val + (b[n] - '0');
	}

	return (d_val);
}

