#include "binary_trees.h"

/**
 *  sorted_array_to_avl - Entry point
 * @array: array
 * @size: lenght array
 * Return: avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (size == 0)
        return (NULL);

    /* m is the size of in the middle */
    size_t m;

    /* increment by the pointer */
    int *la = NULL;
    int *ra = NULL;

    avl_t *root;

    if (size % 2 == 1)
    {
        m = size / 2;
    }
    else
    {
        m = (size / 2) + 1;
    }

    *la = *array;
    *ra = *(array + m + 1);

    root = (avl_t *)malloc(sizeof(avl_t));
    if (root == NULL)
        return (NULL);

    root->n = *(array + m);
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;

    return (root);
}