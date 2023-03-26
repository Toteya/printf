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
	int i, x = 0, chars = 0;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
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
		}
		chars += x;
	}
	return (chars);
}
