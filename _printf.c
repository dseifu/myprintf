#include "main.h"
#include <stdio.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_binary_num - print unsigned int as binary
 * @n: the number
 *
 * Return: the num of digits putchar'ed
*/

int print_binary_num(unsigned int n)
{
	int dp = 1, lc = 1;
	int prdico = 0;

	if (n == 0)
	{
		return (_putchar(48));
	}
	else
	{
		while (lc)
		{
			if ((n / dp) < 2)
				lc = 0;
			else
				dp = dp * 2;
		}
		while (dp > 0)
		{
			prdico += _putchar((n / dp) + '0');
			n = n % dp;
			dp = dp / 2;
		}
	}
	return (prdico);
}

/**
 * print_octal_num - print unsigned int as octal
 * @n: the number
 *
 * Return: the num of digits putchar'ed
 */

int print_octal_num(unsigned int n)
{
	int dp = 1, lc = 1;
	int prdico = 0;

	if (n == 0)
	{
		return (_putchar(48));
	}
	else
	{
		while (lc)
		{
			if ((n / dp) < 8)
				lc = 0;
			else
				dp = dp * 8;
		}
		while (dp > 0)
		{
			prdico += _putchar((n / dp) + '0');
			n = n % dp;
			dp = dp / 8;
		}
	}
	return (prdico);
}

/**
 * replace_h - replace digits upper than 10 by respective letters
 * @h: the digit
 * @is_upper: flag to use lower or upper case
 *
 * Return: the num of digits putchar'ed
*/

int replace_h(unsigned long int h, int is_upper)
{
	switch (h)
	{
	case 10:
		if (is_upper)
			return (_putchar('A'));
		else
			return (_putchar('a'));
	case 11:
		if (is_upper)
			return (_putchar('B'));
		else
			return (_putchar('b'));
	case 12:
		if (is_upper)
			return (_putchar('C'));
		else
			return (_putchar('c'));
	case 13:
		if (is_upper)
			return (_putchar('D'));
		else
			return (_putchar('d'));
	case 14:
		if (is_upper)
			return (_putchar('e'));
		else
			return (_putchar('e'));
	case 15:
		if (is_upper)
			return (_putchar('F'));
		else
			return (_putchar('f'));
	}
	return (0);
}

/**
 * print_hex_num - print unsigned int as hexadecimal
 * @n: the number
 * @is_upper: flag for format specifier used
 *
 * Return: the num of digits putchar'ed
*/

int print_hex_num(unsigned long int n, int is_upper)
{
	unsigned long int dp = 1, lc = 1;
	unsigned long int h;
	int prdico = 0;

	if (n == 0)
	{
		return (_putchar(48));
	}
	else
	{
		while (lc)
		{
			if ((n / dp) < 16)
				lc = 0;
			else
				dp = dp * 16;
		}
		while (dp > 0)
		{
			h = n / dp;
			if (h < 10)
				prdico += _putchar(h + '0');
			else
				prdico += replace_h(h, is_upper);
			n = n % dp;
			dp = dp / 16;
		}
	}
	return (prdico);
}

/**
 * print_unsigned_number - print number
 * @n: the number
 *
 * Return: the num of digits putchar'ed
 */

int print_unsigned_number(unsigned int n)
{
	int dp = 1, lc = 1;
	int prdico = 0;

	if (n == 0)
	{
		return (_putchar(48));
	}
	else
	{
		while (lc)
		{
			if ((n / dp) < 10)
				lc = 0;
			else
				dp = dp * 10;
		}
		while (dp > 0)
		{
			prdico += _putchar((n / dp) + '0');
			n = n % dp;
			dp = dp / 10;
		}
	}
	return (prdico);
}

/**
 * print_number - print number
 * @n: the number
 *
 * Return: the num of digits putchar'ed
 */

int print_number(int n)
{
	int dp = 1, lc = 1;
	int prdico = 0;

	if (n == 0)
	{
		return (_putchar(48));
	}
	else
	{
		if (n < 0)
			prdico += _putchar(45);
		while (lc)
		{
			if (n < 0)
				if ((n / dp) > -10)
					lc = 0;
				else
					dp = dp * 10;
			else
				if ((n / dp) < 10)
					lc = 0;
				else
					dp = dp * 10;
		}
		while (dp > 0)
		{
			if (n < 0)
			{
				prdico += _putchar((-(n / dp)) + '0');
				n = -(n % dp);
			}
			else
			{
				prdico += _putchar((n / dp) + '0');
				n = n % dp;
			}
			dp = dp / 10;
		}
	}
	return (prdico);
}

/**
 * switch_f_and_print - switch format chars one by one and print accordingly
 * @f: format char
 * @ap: va_list var
 *
 * Return: 1 if f is a valid case 0 if not
 */

int switch_f_and_print(char f, va_list ap)
{
	char *s;
	int i;
	int strl = 0;

	switch (f)
	{
	case 'b':
		return (print_binary_num(va_arg(ap, unsigned int)));
	case 'c':
		return (_putchar(va_arg(ap, int)));
	case 'o':
		return (print_octal_num(va_arg(ap, unsigned int)));
	case 'x':
		return (print_hex_num(va_arg(ap, unsigned long int), 0));
	case 'X':
		return (print_hex_num(va_arg(ap, unsigned long int), 1));
	case 'u':
		return (print_unsigned_number(va_arg(ap, unsigned int)));
	case 'i':
	case 'd':
		return (print_number(va_arg(ap, int)));
	case 'p':
		_putchar('0');
		_putchar('x');
		return (2 + print_hex_num(va_arg(ap, unsigned long int), 0));
	case 's':
		s = va_arg(ap, char *);
		if (s != NULL)
		{
			strl = strlen(s);
			for (i = 0; i < strl; i++)
				_putchar(s[i]);
		}
		return (strl);
	case '%':
		return (_putchar('%'));
	}
	return (0);
}

/**
 * _printf - my version of printf
 * @format: a format string
 *
 * Return: No of printed chars
*/

int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int l, i = 0;
	char f;
	char *error = "Error";
	int count = 0, prichco = 0;

	if (format != NULL)
	{
		l = strlen(format);
		va_start(ap, format);
		while (i < l && format[i] != '\0')
		{
			f = format[i];
			if (f == '%')
			{
				i++;
				if (i < l)
				{
					f = format[i];
					prichco = switch_f_and_print(f, ap);
					if (prichco)
						count += prichco;
					else
					{
						i--;
						f = format[i];
						count += _putchar(f);
					}
				}
				else
					for (i = 0; i < 5; i++)
						_putchar(error[i]);
			}
			else
				count += _putchar(f);
			i++;
		}
		va_end(ap);
	}
	return (count);
}
