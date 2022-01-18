#include "sort.h"

/**
 * print_merge - printing the merge and merge the array
 * @array: pointer to array
 * @size: size of the array
 * @p_left: pointer to left array
 * @p_right: pointer to right array
 **/
void print_merge(int *array, size_t size, int *p_left, int *p_right)
{
	int i = 0, j = 0, k = 0;
	/* s means the size of the array */
	int s_left = size / 2;
	int s_right = size - s_left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(p_left, s_left);
	printf("[right]: ");
	print_array(p_right, s_right);

	while (i < s_left && j < s_right)
	{
		if (p_left[i] < p_right[j])
		{
			array[k++] = p_left[i++];
		}
		else
		{
			array[k++] = p_right[j++];
		}
	}

	while (i < s_left)
	{
		array[k++] = p_left[i++];
	}

	while (j < s_right)
	{
		array[k++] = p_right[j++];
	}

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge Sort algorithm
 * the Merge sort algorithm
 *
 * @array: pointer to the array
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i = 0;
	/* the 1000 not pass of the size of numbers*/
	int left[1000];
	int right[1000];

	if (!array)
	{
		return;
	}

	if (size < 2)
	{
		return;
	}

	mid = size / 2;
	for (; i < mid; i++)
	{
		left[i] = array[i];
	}

	for (i = mid; i < size; i++)
	{
		right[i - mid] = array[i];
	}

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	print_merge(array, size, left, right);
}
