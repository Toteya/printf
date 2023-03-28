#include "main.h"

/**
 * _printf - Prints formatted text to stdout
 * @format: The format of the text to be printed
 *
 * Return: Number of characters that is printed
 * Description:
 */
int _printf(const char * const format, ...)
{
	va_list args;
	int i = 0, x = 0, chars = 0;

	va_start(args, format);
	while (format && format[i] != '\0')
	{
		x = 0;
		if (format[i] != '%')
		{
			pchar(format[i]);
			x++;
		}
		else
		{
			if (format[i + 1] == 'c')
			{
				pchar(va_arg(args, int));
				x++;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				if (printstring(va_arg(args, char *)) == -1)
					printstring("Error - no string\n");
				i++;
			}
			else if(format[i + 1] != '%')
			{
				pchar(format[i]);
				x++;
			}
		}
		chars += x;
		i++;
	}
	return (chars);
}
