#include "main.h"
/**
 *_printf - recreating the printf function
 *@format: is a character string
 *Return: 0
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0;
	int count = 0;
	char *ptr;

	va_list(args);
	va_start(args, format);

	while (format != NULL && format[i])
	{
		if (format[i] == '%')
		{
			format++;

			switch (format[i])
			{
				case '%': /* case of a % */
					write(1, &format[i], 1);
					break;

				case 's': /* case of a string */
					ptr = va_arg(args, char *);
					if (ptr == NULL)
					{
						write(1, "(null)", 6);
					}
					while (ptr[j] != '\0')
					{
						write(1, &ptr[j], 1);
						j++;
						count++;
					}
					break;

				case 'c': /* case of single character */
					ptr = va_arg(args, char *);
					if (ptr == NULL)
					{
						write(1, "(null)", 6);
						return (6);
					}
					write(1, &ptr, 1);
					break;
				default:
					write(1, "%", 1);
					write(1, &format[i], 1);
			}
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
