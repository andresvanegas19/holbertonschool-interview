#include "search_algos.h"
#define NOT_FOUND (-1)

/**
 * basic_binary_search - implements a basic binary search
 * @array: array to search
 * @first: first position
 * @last: last position
 * @value: the valueue of the returned index
 * Return: index of number, NOT_FOUND if not found
 */
int basic_binary_search(int *array, int first, int last, int value)
{
	int pivot, i = 0;

	printf("Searching in array: ");
	for (i = first; i < last; i++)
		printf("%i, ", array[i]);
	printf("%i\n", array[i]);

	pivot = ((last - first) / 2) + first;

	if (array[pivot] == value && array[pivot - 1] != value)
		return (pivot);

	if (first == last)
		return (NOT_FOUND);

	if (array[pivot] >= value)
		return (basic_binary_search(array, first, pivot, value));

	if (array[pivot] < value)
		return (basic_binary_search(array, pivot + 1, last, value));

	return (NOT_FOUND);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers.
 * @array: the array
 * @size: the size of array
 * @value: the value to search for
 * Return: index of number or NOT_FOUND if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (NOT_FOUND);

	return (basic_binary_search(array, 0, (int)size - 1, value));
}
