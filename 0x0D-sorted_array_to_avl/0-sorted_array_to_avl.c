#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: is a pointer to an array of integers
 * @size: is the size of the array
 * Return: a pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    int i;

    if (!array || size < 1)
    {
        return (NULL);
    }

    for (i = 0; i < (int)size; i++)
    {
        if (array[i] < array[i - 1])
            return (NULL);
    }

    return (solution(array, 0, size - 1, NULL));
}

/**
 * solution - Constructing the AVL Tree
 *
 * @array: is a pointer to an array of integers
 * @init: initing the index
 * @end: ending
 * @parent: The AVL Parent Implemented to track i
 *
 * Return: a pointer to the root node of the created AVL tree
 */
avl_t *solution(int *array, int init, int end, avl_t *parent)
{
    avl_t *pAvlT;
    int mid;

    if (init > end)
        return (NULL);

    mid = (init + end) / 2;

    pAvlT = malloc(sizeof(avl_t));
    if (!pAvlT)
    {
        return (NULL);
    }

    pAvlT->n = array[mid];
    pAvlT->parent = parent;

    /* iterate by the leafs*/
    pAvlT->left = solution(array, init, mid - 1, pAvlT);
    pAvlT->right = solution(array, mid + 1, end, pAvlT);

    return (pAvlT);
}