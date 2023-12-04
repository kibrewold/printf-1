#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...)
{
    int chara_print = 0;
    va_list list_of_args;

    if (format == NULL)
    {
        return (-1);
    }

    va_start(list_of_args, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            chara_print++;
        }
        else
        {
            format++;

            if (*format == '\0')
            {
                break;
            }

            if (*format == '%')
            {
                // Handle %%
                write(1, format, 1);
                chara_print++;
            }
            else if (*format == 'c')
            {
                // Handle %c
                char value = va_arg(list_of_args, int);
                putchar(value);
                chara_print++;
            }
            else if (*format == 's')
            {
                // Handle %s
                char *value = va_arg(list_of_args, char *);
                while (*value != '\0')
                {
                    putchar(*value);
                    value++;
                    chara_print++;
                }
            }
        }

        format++;
    }

    va_end(list_of_args);

    return chara_print;
}

