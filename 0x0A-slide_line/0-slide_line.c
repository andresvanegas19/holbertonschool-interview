#include "slide_line.h"

/**
 * sl_left - slides and merges an array of integers
 * @line:  points to an array of integers containing
 * size elements, that must be slided & merged
 * to the direction represented by direction
 * @size: size of the array.
 */
void sl_left(int *line, size_t size)
{
    int count, i, j = 0;

    for (; i < (int)size; i++)
    {
        if (i == (int)size - 1)
        {
            line[count] = line[i];
            count++;
        }

        if (line[i] == 0)
            continue;

        for (j = i + 1; j < (int)size; j++)
        {
            if (line[j] == 0 && j == (int)size - 1)
            {
                line[count] = line[i];
                count++;
            }

            if (line[j] == 0)
                continue;

            if (line[i] == line[j])
            {
                line[count] = line[i] * 2;
                count++;
                i = j;
                break;
            }

            if (line[i] != line[j])
            {
                line[count] = line[i];
                count++;
                break;
            }
        }
    }

    for (i = count; i < (int)size; i++)
        line[i] = 0;
}

/**
 * sl_right - slides and merges an array of integers
 * @line:  points to an array of integers containing
 * size elements, that must be slided & merged
 * to the direction represented by direction
 * @size: size of the array.
 */
void sl_right(int *line, size_t size)
{
    int count, i, j = 0;
    count = size - 1;

    for (i = count; i >= 0; i--)
    {
        if (i == 0)
        {
            line[count] = line[i];
            count--;
        }

        if (line[i] == 0)
            continue;

        for (j = i - 1; j >= 0; j--)
        {
            if (line[j] == 0 && j == 0)
            {
                line[count] = line[i];
                count--;
            }

            if (line[j] == 0)
                continue;

            if (line[i] == line[j])
            {
                line[count] = line[i] * 2;
                count--;
                i = j;
                break;
            }

            if (line[i] != line[j])
            {
                line[count] = line[i];
                count--;
                break;
            }
        }
    }

    for (i = count; i >= 0; i--)
        line[i] = 0;
}

/**
 * slide_line - slides and merges an array of integers
 * @line:  points to an array of integers containing
 * size elements, that must be slided & merged
 * to the direction represented by direction
 * @size: size of the array.
 * @direction: direction can be either: - SLIDE_LEFT - SLIDE_RIGHT
 * If it is something else, the function must fail
 *
 * Return: the result of the slide.
 */
int slide_line(int *line, size_t size, int direction)
{
    if (line == NULL || size == 0)
        return (0);

    if (direction == SLIDE_LEFT)
    {
        sl_left(line, size);
        return (1);
    }

    if (direction == SLIDE_RIGHT)
    {
        sl_right(line, size);
        return (1);
    }

    return (0);
}