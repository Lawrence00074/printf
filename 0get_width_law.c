#include "main.h"
/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
int curr_it;
int width = 0;
for (curr_it = *i + 1; format[curr_it] != '\0'; curr_it++)
{
if (is_digit(format[curr_it]))
{
width *= 10;
width += format[curr_it] - '0';
}
else if (format[curr_it] == '*')
{
curr_it++;
width = va_arg(list, int);
break;
}
else
break;
}
*i = curr_it - 1;
return (width);
}
