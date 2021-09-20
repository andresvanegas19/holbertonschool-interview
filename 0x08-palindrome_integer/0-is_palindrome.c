#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given
 * unsigned integer is a palindrome.
 *
 * @n: is the number to be checked
 *
 * Return: Your function must return
 * 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long revert = 0, validate_number = n;

    while (n != 0)
    {
        revert = revert * 10 + (n % 10);
        n = n / 10;
    }

    if (validate_number == revert)
        return (1);

    return (0);
}
