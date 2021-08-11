#include "binary_trees.h"

/**
 * node_tree - checks if a node is a the last
 * @node: pointer to the node to check
 * Return: 1 if node is it, otherwise returns 0
*/
int node_tree(heap_t *node)
{
	int leafs;

	if (node == NULL)
		return (0);

	leafs = 1;

	leafs = leafs + node_tree(node->left);
	leafs = leafs + node_tree(node->right);

	return (leafs);
}

/**
 * checking - checks if a tree is perfect
 * @node: pointer to the node to check
 * Return: 1 if tree is perfect, otherwise 0
*/
int checking(heap_t *node)
{
	int left;
	int right;

	if (node == NULL)
		return (0);

	right = node_tree(node->right);
	left = node_tree(node->left);

	if (left == right)
		return (1);
	else
		return (0);
}

/**
 * find_parent - finds the parent of the tree node
 * @node: pointer to the node to check
 * Return: pointer to the parent
*/
heap_t *find_parent(heap_t *node)
{
	int right_node;
	int complete;
	int left_node;
	int right_tree;

	if (node == NULL)
		return (NULL);

	left_node = node_tree(node->left);
	right_node = node_tree(node->right);

	if (left_node < 1 || right_node < 1)
		return (node);

	complete = checking(node->left);
	right_tree = checking(node->right);

	if (complete < 1 || (complete && right_tree && left_node == right_node))
	{
		return (find_parent(node->left));
	}
	else if (right_tree < 1 || (complete && right_tree && left_node > right_node))
	{
		return (find_parent(node->right));
	}
	else
	{
		return (node);
	}
}

/**
 * swap_node - change the position og the node
 * @node: pointer to the node
*/
void swap_node(heap_t **node)
{
	heap_t *current;
	int aux;

	current = *node;

	while (current->parent != NULL)
	{
		if (current->parent->n < current->n)
		{
			aux = current->parent->n;
			current->parent->n = current->n;
			current->n = aux;
			*node = current->parent;
		}
		else
			current = current->parent;
	}
}

/**
* heap_insert - inserts a value into a Max Binary Heap
* @root: double pointer to the root node of the Heap
* @value: value store in the node to be inserted
* Return: pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	parent = find_parent(*root);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent == NULL)
	{
		*root = new_node;
	}
	else if (parent->left == NULL)
	{
		parent->left = new_node;
	}
	else
	{
		parent->right = new_node;
	}

	swap_node(&new_node);

	return (new_node);
}
