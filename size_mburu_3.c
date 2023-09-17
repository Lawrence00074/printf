#include "main.h"
/**
 * get_size - Calculate the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_mb = *i + 1;
	int size = 0;

	if (format[curr_mb] == '1')
		size = S_LONG;
	else if (format[curr_mb] == 'h')
		size  = S_SHORT;

	if (size == 0)
		*i = curr_mb - 1;
	else
		*i = curr_mb;

	return (size);
}
