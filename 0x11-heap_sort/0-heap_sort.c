#include "sort.h"

/**
 * swap - change the values of two variables into the array
 *
 * @p_array: pointer to the array
 * @size: is the size of the array
 * @a_idx: the index of the first variable into the array
 * @b_idx: the index of the second variable into the array
 *
 */
void swap(int *p_array, size_t size, int a_idx, int b_idx)
{
	int tmp = p_array[a_idx];

	p_array[a_idx] = p_array[b_idx];
	p_array[b_idx] = tmp;
	print_array(p_array, size);
}

/**
 * p_index - return the parent of a index in array
 *
 * @index: is the index
 *
 * Return: the parent of the index
 */
size_t p_index(int index)
{
	return (2 * index + 1);
}

/**
 * f_shif_root - fix the root of the heap to the correct position
 *
 * @array: pointer to the array
 * @size: is the size of the array
 * @start: is the index of the root
 * @end_indx: is the index of the last element of the array
 *
 */
void f_shif_root(int *array, size_t size, size_t start, size_t end_indx)
{
	size_t root = start;
	size_t child;
	size_t s_index;

	for (; p_index(root) <= end_indx;)
	{
		child = p_index(root);
		s_index = root;

		if (array[s_index] < array[child])
			s_index = child;

		if (child + 1 <= end_indx && array[s_index] < array[child + 1])
			s_index = child + 1;

		if (s_index == root)
			return;

		swap(array, size, root, s_index);

		root = s_index;
	}
}

/**
 * h_fy - order elements into array in ascending order
 *
 * @p_array: pointer to the array
 * @size: is the size of the array
 *
 */
void h_fy(int *p_array, int size)
{
	int start = ((size - 2) / 2);

	for (; start >= 0; start--)
	{
		f_shif_root(p_array, size, start, size - 1);
	}
}

/**
 * heap_sort - sorts an array of integers
 *
 * @array: pointer to the array
 * @size: is the size of the array
 *
 */
void heap_sort(int *array, size_t size)
{
	int end = 0;

	h_fy(array, size);
	for (end = size - 1; end > 0;)
	{
		swap(array, size, end, 0);
		end--;
		f_shif_root(array, size, 0, end);
	}
}
