#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - compares two strings
 * @s1: first string for comparing
 * @s2: compared string, the string can contain the special character *\
 *
 * Return: returns 1 if the strings can be considered identical,
 * otherwise return 0.
 */
int wildcmp(char *s1, char *s2)
{
	int i = 1;
	int v_return = 0;

	if (!(*s1))
	{
		/* printf("num %d\n", *s1); */
		if (*s2 == '*')
		{
			return (wildcmp(s1, s2 + i));
		}
		else
		{
			return (*s2 == '\0');
		}
	}

	if (*s2 == '*')
	{
		/* comparing the right to left */
		return (wildcmp(s1 + i, s2) || wildcmp(s1, s2 + i));
	}

	if (*s1 == *s2)
	{
		s1 += i;
		s2 += i;
		return (wildcmp(s1, s2));
	}
	/* printf("num %d\n", *s1); */

	return (v_return);
}
