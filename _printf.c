#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - printf fnction
 * @format: format.
 * Return: printed chars.
 */
int _printf(const char *format, ...)
{
	int mb, print = 0, print_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (mb = 0; format && format[mb] != '\0'; mb++)
	{
		if (format[mb] != '%')
		{
			buffer[buff_ind++] = format[mb];
	
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			print_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &mb);
			width = get_width(format, &mb, list);
			precision = get_precision(format, &mb, list);
			size = get_size(format, &mb);
			++mb;
			print = handle_print(format, &mb, list, buffer, flags, width, precision, size);
			if (print == -1)
				return (-1);
			print_char += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (print_char);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to adda next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
