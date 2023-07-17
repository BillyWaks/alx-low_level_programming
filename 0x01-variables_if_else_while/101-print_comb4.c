#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (success)
 */

int main(void)
{
        int ones;
        int tens;
	int hundreds;

	for (hundreds = '0'; hundreds <= '9'; hundreds++)
	{
		for (tens = '0'; tens <= '9'; tens++)
		{
			for (ones = '0'; ones <= '9'; ones++)
			{
				if (!((ones == tens) || (tens > ones) || (tens == hundreds) || (hundreds > tens)))
				{
					putchar(hundreds);
					putchar(tens);
					putchar(ones);

					if (!(ones == '9') && (tens == '8') && (hundreds == '7'))
					{
						putchar(',');
						putchar(' ');	
					}
                                }
                        }
                }
        }
        putchar('\n');
        return(0);
}
