#include "main.h"
/**
 * _strlen_recursion - print length of string
 * @s: string to print
 *
 * Return: length of string
 */
int _strlen_recursion(char *s)
{
	if (s[0] != '\0')
		return (1 + _strlen_recursion(s + 1));
	return (0);
}

/**
 * pal_checker - checks is *s is a palindrome
 * @s: base address of string
 * @l: index (left)
 * @r: index (right)
 *
 * Return: 1 if s is palindrome, otherwise 0
 */
int pal_checker(char *s, int l, int r)
{
	if (s[l] == s[r])
	{
		if (l > r / 2)
			return (1);
		else
			return (pal_checker(s, l + 1, r - 1));
		else
			return (0);
	}
}

/**
 * is_palindrome - checks for palindrome
 * @s: string address
 *
 * Return: if n = prime (1), n != prime (0)
 */
int is_palindrome(char *s)
{
	return (pal_checker(s, 0, _strlen_recursion(s) - 1));
}
