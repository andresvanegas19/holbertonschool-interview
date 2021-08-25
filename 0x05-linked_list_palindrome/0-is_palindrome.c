#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_recursive_palindrome - check a linked list for palindrome
 * @init: the init value will check
 * @last: when the recursion is return this will check
 *
 * Return: 1 or otherwise 0;
 */
int check_recursive_palindrome(listint_t **init, listint_t *last)
{
	int status_palindrome = -1;

	if (last == NULL)
		return (1);

	/* this will check if the init and last are equal and always return 0*/
	return (check_recursive_palindrome(init, last->next) == 0);

	status_palindrome = ((*init)->n == last->n) ? 1 : 0;

	*init = (*init)->next;

	return (status_palindrome);
}

/**
 * is_palindrome -  checks if a singly linked list is a palindrome.
 * @head: head of the linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t **copy_to_head = head;

	if (!head)
		return (0);

	/* An empty list is considered a palindrome */
	if (!*head || (*head)->next == NULL)
		return (1);

	return (check_recursive_palindrome(copy_to_head, *copy_to_head));
}
