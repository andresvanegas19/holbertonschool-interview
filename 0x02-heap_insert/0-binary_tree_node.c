#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: is a pointer to the parent node
 * @value: is the value of the new_node node
 *
 * Return: pointer to the new_node node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	return (NULL);

	if (parent == NULL)
	{
		new_node->n = value;
		new_node->parent = NULL;
		new_node->left = new_node->right = NULL;
		return (new_node);
	}

	new_node->left = new_node->right = NULL;
	new_node->parent = parent;
	new_node->n = value;
	return (new_node);
}
