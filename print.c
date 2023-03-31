#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - a printf function
 * @format: string to be printed
 *
 * Return: number of chars printed.
 */

int _printf(const char *format, ...)
{
	int num_chars_printed = 0;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, sizeof(char));
				num_chars_printed++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				write(1, s, strlen(s));
				num_chars_printed += strlen(s);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				char buf[32];
				int i = 0;

				if (num < 0)
				{
					write(1, "-", 1);
					num_chars_printed++;
					num = -num;
				}
				if (num == 0)
				{
					write(1, "0", 1);
					num_chars_printed++;
				}
				while (num > 0)
				{
					buf[i++] = num % 10 + '0';
					num /= 10;
				}
				while (i > 0)
				{
					write(1, &buf[--i], 1);
					num_chars_printed++;
				}
			}
			else if (*format == '%')
			{
				char c = '%';

				write(1, &c, sizeof(char));
				num_chars_printed++;
			}
		}
		else
		{
			write(1, format, sizeof(char));
			num_chars_printed++;
		}
		format++;
	}
	va_end(args);
	return (num_chars_printed);
}
