#include "main.h"
/**
 * get_flags - Calculates the active flags
 * @format: Formatted string in which to print the arguments
 * @i: taje a parameter
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int mb, curr_i;
	int flags = 0;

	const char FLAGS_CH[] = { '-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (mb = 0; FLAGS_CH[mb] != '\0'; mb++)
			if (format[curr_i] == FLAGS_CH[mb])
			{
				flags |= FLAGS_ARR[mb];
				break;
			}

		if (FLAGS_CH[mb] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
