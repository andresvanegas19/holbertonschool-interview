#include "search.h"

/**
* linear_skip - is the function to skip the first n elements of an array
*
* @list: p to the head of the skip list to search in
* @value: value to finds
*
* Return: a pointer on the first pnode where value is located, otherwise NULL
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *pnode;

	if (!list)
		return (NULL);

	pnode = list->express;

	printf("Value checked at index [%lu] = [%d]\n", pnode->index, pnode->n);

	while (pnode && pnode->n < value)
	{
		list = pnode;
		pnode = pnode->express;
		if (!pnode)
		{
			pnode = list;

			while (pnode->next)
				pnode = pnode->next;
			break;
		}

		printf("Value checked at index [%lu] = [%d]\n", pnode->index, pnode->n);
	}

	printf(
	    "Value found between indexes [%lu] and [%lu]\n",
	    list->index,
	    pnode->index);

	for (; list && pnode->n >= list->n; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);

		if (list->n == value)
			return (list);
	}

	return (NULL);
}
