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
	listint_t *ph /* pointer head */, *bh /* behing */, *nnode /* new node */;

	if (head == NULL)
		return (NULL);

	nnode = malloc(sizeof(listint_t));
	if (nnode == NULL)
		return (NULL);

	bh = *head;
	nnode->n = number;
	nnode->next = NULL;

	if (*head == NULL)
	{
		*head = nnode;
		return (nnode);
	}

	if (number <= bh->n)
	{
		nnode->next = *head;
		*head = nnode;
		return (nnode);
	}

	ph = bh->next;

	while (ph != NULL)
	{
		if (ph->n >= number)
		{
			nnode->next = ph;
			bh->next = nnode;
			break;
		}

		if (ph->n < number && ph->next == NULL)
		{
			ph->next = nnode;
			break;
		}

		bh = bh->next;
		ph = ph->next;
	}

	return (nnode);
}
