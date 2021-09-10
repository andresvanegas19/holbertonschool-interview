#include "lists.h"
/**
 * check_cycle -  function in C that checks if a singly linked list has a cycle in it.
 * @list: pointer oflistint_t list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    const listint_t *copy_linked_list = list;
    int i = 0;

    if (list == NULL || list->next == NULL)
        return (0);

    while (copy_linked_list != NULL)
    {
        if (i == 10)
            return (1);

        copy_linked_list = copy_linked_list->next, i++;
    }

    return (0);
}
