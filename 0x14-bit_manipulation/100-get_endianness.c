#include "main.h"

/**
 * get_endianness - checks and determines if a machine is little or big
 * Return: 0 (big), 1 (little)
 */
int get_endianness(void)
{
	/*initialize values*/
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}


