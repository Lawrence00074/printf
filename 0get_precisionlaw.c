#include "main.h"
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
int curr_it = *i + 1;
int precision = -1;
if (format[curr_it] != '.')
return (precision);
precision = 0;
for (curr_it += 1; format[curr_it] != '\0'; curr_it++)
{
if (is_digit(format[curr_it]))
{
precision *= 10;
precision += format[curr_it] - '0';
}
else if (format[curr_it] == '*')
{
curr_it++;
precision = va_arg(list, int);
break;
}
else
break;
}
*i = curr_it - 1;
return (precision);
}
