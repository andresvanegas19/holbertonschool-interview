
#include "holberton.h"

/**
 * is_integer - Check if the string is an integer
 *
 * @n: Sring to check if is an integer
 * Return: 1 if it is correct otherwise return 0
 */
int is_integer(char *n)
{
    int i = 0;

    while (*(n + i) != '\0')
    {
        /* validation of not a integer*/
        if (*(n + i) < '0' || *(n + i) > '9')
        {
            return (0);
        }

        i++;
    }

    return (1);
}

/**
 * len_string - calculate the len of a string
 *
 * @s: Pointer that contains the string
 *
 * Return: the len of the string
 */
int len_string(const char *s)
{
    int len = 0;

    while (*s != '\0')
    {
        len++;
        s++;
    }
    return (len);
}

/**
 * main - program that multiplies two positive numbers
 * @argc: Number of the total of the arguments
 * @argv: Arguments of the multiply
 *
 * Return: return 0, otherwise, prints Error and returns 98
 */
int main(int argc, char *argv[])
{
    int p, res, total_len, len_number_one, len_number_two, i, j = 0;
    int *total;

    /* Check if the number of arguments is correct */
    if (argc < 3 || argc > 3 || !(is_integer(argv[2])) || !(is_integer(argv[1])))
    {
        puts("Error");
        exit(98);
    }

    /* Validate the 0 multiplication */
    if (argv[1][0] == '0' || argv[2][0] == '0')
    {
        printf("0\n");
        return (0);
    }

    /* Validate the len of the numbers */
    len_number_one = len_string(argv[1]);
    len_number_two = len_string(argv[2]);
    total_len = len_number_one + len_number_two;

    total = calloc(total_len, sizeof(int *));
    if (total == NULL)
    {
        puts("Error");
        exit(98);
    }

    for (i = (len_number_two - 1); i > -1; i--)
    {
        res = 0;
        for (j = (len_number_one - 1); j > -1; j--)
        {
            p = (argv[2][i] - '0') * (argv[1][j] - '0');
            res = (p / 10);
            total[(i + j) + 1] += (p % 10);
            if (total[(i + j) + 1] > 9)
            {
                total[i + j] += total[(i + j) + 1] / 10;
                total[(i + j) + 1] = total[(i + j) + 1] % 10;
            }
            total[(i + j)] += res;
        }
    }

    if (total[0] == 0)
    {
        i = 1;
    }
    else
    {
        i = 0;
    }

    /* Print the result */
    for (; i < total_len; i++)
        printf("%d", total[i]);
    printf("\n");

    free(total);
    return (0);
}
