#include "main.h"

/**
 * print_pointer - Print a pointer address in hexadecimal format
 * @arg: The argument to print (a void pointer)
 *
 * Return: The number of characters printed
 */
int print_pointer(va_list arg)
{
	void *ptr = va_arg(arg, void *);
	char hex_chars[] = "0123456789abcdef";
	unsigned long int num = (unsigned long int)ptr;
	unsigned long int temp;
	int count = 0;
	unsigned int num_digits = 0;
	unsigned int i;

	count += _putchar('0');
	count += _putchar('x');

	if (num == 0)
	{
		count += _putchar('0');
		count += _putchar('0');
		return (count);
	}

	temp = num;
	while (temp != 0)
	{
		num_digits++;
		temp /= 16;
	}

	for (i = 0; i < (sizeof(void *) * 2U - num_digits); i++)
		count += _putchar('0');

	while (num != 0)
	{
		int digit = num % 16;

		count += _putchar(hex_chars[digit]);

		num /= 16;
	}

	return (count);
}

/**
 * reverse_string - reverses a string
 * @str: the string to reverse
 * Return: a pointer to the reversed string
 */
char *reverse_string(char *str)
{
	int i, j;
	char temp;

	if (str == NULL)
		return (NULL);

	i = 0;
	j = _strlen(str) - 1;

	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}

	return (str);
}

/**
 * _strlen - returns the length of a string
 * @s: the string to measure
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}
