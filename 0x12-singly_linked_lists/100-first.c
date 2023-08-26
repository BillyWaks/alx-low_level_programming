#include <stdio.h>
#include "lists.h"

/**
 * pre_message - prints a message before executing the main function
 */

void ComeFirstbyCTC(void)__attribute__ ((constructor));
/**
 * COmeFirst - function that runs before the main
 */

void ComeFirstbyCTC(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
