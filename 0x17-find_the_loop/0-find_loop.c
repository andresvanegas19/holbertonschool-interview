#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: the adress of the node where the loop starts, or
 *  NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *confim = head;
    listint_t *p_next_head = head;

    if (!head)
        return (NULL);

    while (p_next_head && p_next_head->next)
    {
        confim = confim->next;
        p_next_head = p_next_head->next->next;
        if (confim == p_next_head)
        {
            confim = head;
            while (confim != p_next_head)
            {
                confim = confim->next;
                p_next_head = p_next_head->next;
            }
            return (p_next_head);
        }
    }
    return (NULL);
}