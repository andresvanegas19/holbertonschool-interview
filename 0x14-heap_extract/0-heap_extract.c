#include "binary_trees.h"
#include <stdlib.h>

/**
 * root_heap - hight measure of the tree
 * @p_tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t root_heap(const heap_t *p_tree)
{
    size_t hi_root = 0;
    size_t ri_hi = 0;

    if (!p_tree)
        return (0);

    if (p_tree->left)
        hi_root = 1 + root_heap(p_tree->left);

    if (p_tree->right)
        ri_hi = 1 + root_heap(p_tree->right);

    if (hi_root > ri_hi)
        return (hi_root);
    return (ri_hi);
}
/**
 * tree_size_h - measures the sum of heights of a binary tree
 * @p_tree:th root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *p_tree)
{
    size_t hi_root = 0;
    size_t ri_hi = 0;

    if (!p_tree)
        return (0);

    if (p_tree->left)
        hi_root = 1 + tree_size_h(p_tree->left);

    if (p_tree->right)
        ri_hi = 1 + tree_size_h(p_tree->right);

    return (hi_root + ri_hi);
}

/**
 * preorder_traversal - iterate over binary
 *
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 */
void preorder_traversal(heap_t *tree, heap_t **node, size_t height)
{
    if (!tree)
        return;

    if (!height)
        *node = tree;
    height--;

    preorder_traversal(tree->left, node, height);
    preorder_traversal(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
    int value;
    heap_t *tmp1, *tmp2;

    if (!root)
        return;

    tmp1 = root;

    while (1)
    {
        if (!tmp1->left)
            break;
        if (!tmp1->right)
            tmp2 = tmp1->left;
        else
        {
            if (tmp1->left->n > tmp1->right->n)
            {
                tmp2 = tmp1->left;
            }
            else
            {
                tmp2 = tmp1->right;
            }
        }
        if (tmp1->n > tmp2->n)
            break;

        value = tmp1->n;
        tmp1->n = tmp2->n;
        tmp2->n = value;
        tmp1 = tmp2;
    }
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
    int value;
    heap_t *heap_r, *node;

    if (!root || !*root)
        return (0);

    heap_r = *root;
    value = heap_r->n;

    if (!heap_r->left && !heap_r->right)
    {
        *root = NULL;
        free(heap_r);
        return (value);
    }

    preorder_traversal(heap_r, &node, root_heap(heap_r));

    heap_r->n = node->n;

    if (node->parent->right)
    {

        node->parent->right = NULL;
    }
    else
    {

        node->parent->left = NULL;
    }

    free(node);

    heapify(heap_r);

    *root = heap_r;

    return (value);
}