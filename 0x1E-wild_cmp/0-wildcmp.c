#include "holberton.h"

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
    int i, j;

    i = 0;
    j = 0;
    while (s1[i] != '\0' && s2[j] != '\0')
    {
        if (s1[i] == '*')
        {
            while (s2[j] != '\0' && s2[j] != s1[i + 1])
                j++;
            if (s2[j] == '\0')
                return (0);
            j++;
            i++;
        }
        else if (s1[i] != s2[j])
            return (0);
        else
            i++;
        j++;
    }
    if (s1[i] == '\0' && s2[j] == '\0')
        return (1);
    if (s1[i] == '\0' && s2[j] != '\0')
    {
        while (s2[j] != '\0' && s2[j] == '*')
            j++;
        if (s2[j] == '\0')
            return (1);
        else
            return (0);
    }
    if (s1[i] != '\0' && s2[j] == '\0')
        return (0);

    return (0);
}
