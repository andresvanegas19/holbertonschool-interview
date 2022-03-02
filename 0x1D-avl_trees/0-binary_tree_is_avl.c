#include "binary_trees.h"

/**
 * is_binary_search_tree - checks if tree is a binary search tree
 * @node: current node being checked
 * @min: integer indicating the left boundary of the current node's value
 * @max: integer indicating the right boundary of the current node's value
 * @height: height of the current binary tree level
 * (curr value needs to be <= max and >= min)
 * Return: 1 if tree is a valid BST otherwise 0
 */
int is_valid_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int n_height_l = 0, n_height_r = 0;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (is_valid_avl(tree->left, min, tree->n, &n_height_l) == 0 ||
		is_valid_avl(tree->right, tree->n, max, &n_height_r) == 0)
	return (0);

	*height = ((n_height_l > n_height_r) ? n_height_l : n_height_r) + 1;

	if (abs(n_height_l - n_height_r) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise If
 * tree is NULL, return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	return (is_valid_avl(tree, -1, INT_MAX, &height));
}
