#include "lists.h"

/**
 * insert_node -  function in C that inserts a number into a sorted
 * singly linked list.
 * @head: pointer to head of list
 * @number: is the number of where the new node will be
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL, *cp_head = *head;

	new_node = malloc(sizeof(*head));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number; new_node->next = NULL;

	if (number < 0)
		return (NULL);

	if (head == NULL || number == 0)
	{
		*head = new_node; return (new_node);
	}


	while (*head != NULL)
	{
		if ((*head)->next == NULL)
		{
			(*head)->next = new_node;
			*head = cp_head;
			return (new_node);
		}

		if (number <= (*head)->next->n)
		{
			new_node->next = (*head)->next;
			(*head)->next = new_node;
			*head = cp_head;
			return (new_node);
		}
		*head = (*head)->next;
	}
	return (NULL);
}
