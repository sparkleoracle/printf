#include "main.h"

/**
 * get_flags - the main function that Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int m, curr_j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_j = *i + 1; format[curr_j] != '\0'; curr_j++)
	{
		for (m = 0; FLAGS_CH[m] != '\0'; m++)
			if (format[curr_j] == FLAGS_CH[m])
			{
				flags |= FLAGS_ARR[m];
				break;
			}

		if (FLAGS_CH[m] == 0)
			break;
	}

	*i = curr_j - 1;

	return (flags);
}
