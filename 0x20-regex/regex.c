#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: is the string to scan, can be empty, and can contain any ASCII
 * character in the exception of . and *
 * @pattern: is the regular expression's pattern, can be empty, and
 * can contain any ASCII character, including . and *
 *
 * Note:
 * The regular expression matching must support the characters . and *
 * matches any single character matches zero or more of the preceding character
 *
 * Return: return 1 if true, 0 if not
 */
int regex_match(char const *str, char const *pattern)
{
	if (!str)
		return (0);

	/* str checking the nulling */
	if (!*str)
	{
		/* checking the pattern  */
		if (*(pattern + 1) == '*')
			/* validating recursion */
			return (regex_match(str, pattern + 2));

		return (!*pattern);
	}

	if (*(pattern + 1) == '*')
	{
		if (*pattern == '.' || *pattern == *str)
			return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));

		return (regex_match(str, pattern + 2));
	}

	if (*pattern == '.' || *pattern == *str)
	{
		return (regex_match(str + 1, pattern + 1));
	}

	return (0);
}
