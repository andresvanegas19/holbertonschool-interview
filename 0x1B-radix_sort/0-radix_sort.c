#include "sort.h"
/**
 * i_digit_current - iterate to the current digit and sorting the array
 * @array: pointer to the array
 * @size: length of the array
 * @p_temp_n: p_temp_n is the number of digits
 * @exponential: exponential
 *
 * Return: 0
 */
int i_digit_current(
	int *array, ssize_t size, int *p_temp_n, long exponential
)
{
	ssize_t i = -1;
	int aux[10] = {0};

	for (i = 0; i < size; i++)
	{
		aux[(array[i] / exponential) % 10]++, p_temp_n[i] = 0;
	}

	for (i = 1; i < 10; i++)
	{
		aux[i] += aux[i - 1];
	}

	/* comparison of unsigned expression >= 0 is always true*/
	for (i = size - 1; i >= 0; i--)
	{
		p_temp_n[--aux[(array[i] / exponential) % 10]] = array[i];
	}

	for (i = 0; i < size; i++)
	{
		array[i] = p_temp_n[i];
	}

	return (0);
}
/**
 * radix_sort - Write a function that sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: pointer to an array of integers,  will contain only numbers >= 0
 * @size: length of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	long exponential = 1;
	int *p_temp_n, n_max_num = -1;

	if (!array || size < 2)
	{
		return;
	}

	p_temp_n = malloc(sizeof(int *) * size);
	if (p_temp_n == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		if (array[i] > n_max_num)
		{
			n_max_num = array[i];
		}
		else
		{
			n_max_num = n_max_num;
		}
	}

	while (n_max_num / exponential > 0)
	{
		i_digit_current(array, size, p_temp_n, exponential);
		print_array(array, size);
		exponential *= 10;
	}

	free(p_temp_n);
}
