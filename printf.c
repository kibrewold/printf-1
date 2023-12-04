#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str_arg;
	char char_arg;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			switch (*(format + 1))
			{
			case 'c':
				char_arg = (char)va_arg(args, int);
				count += write(1, &char_arg, 1);
				break;
			case 's':
				str_arg = va_arg(args, char *);
				while (*str_arg)
				{
					count += write(1, str_arg, 1);
					str_arg++;
				}
				break;
			case '%':
				count += write(1, "%", 1);
				break;
			default:
				count += write(1, "%", 1);
				count += write(1, &*(format + 1), 1);
				break;
			}
			format++;
		}
		else
		{
			count += write(1, format, 1);
		}

		format++;
	}

	va_end(args);

	return count;
}

int main(void)
{
	_printf("Hello, %c!\n", 'W');
	_printf("This is a %s example.\n", "printf");
	_printf("A percentage sign: %%\n");

	return 0;
}
