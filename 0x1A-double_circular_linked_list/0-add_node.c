#include "list.h"

/**
 * update_links - Updates and creates a new pointers into the
 * linked
 * @list: linked list being inserted to
 * @new: pointer to newly created node
 */
void update_links(List **list, List *new_node)
{
    if (!*list)
    {
        *list = new_node, (*list)->next = (*list)->prev = new_node;
    }
    else
    {
        new_node->prev = (*list)->prev, new_node->next = *list;
        (*list)->prev = (*list)->prev->next = new_node;
    }
}

/**
 * create_node - create into the linked list
 * @str: the string to copy into the new node
 *
 * Return: the adress of the new created node
 */
List *create_node(char *str)
{
    List *new_node;

    new_node = malloc(sizeof(*new_node));
    if (!new_node)
    {
        return (NULL);
    }

    new_node->str = strdup(str);

    if (!new_node->str)
    {
        return (NULL);
    }

    return (new_node);
}

/**
 * add_node_begin - Add a new node to the end of a double circular linked list
 * @list: linked list being inserted to
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
    List *new_node;

    new_node = create_node(str);
    if (!new_node)
    {
        return (NULL);
    }

    update_links(list, new_node);
    *list = new_node;

    return (new_node);
}

/**
 * add_node_end - insert new node to end of double circular linked list
 * @list: linked list being inserted to
 * @str: the string to copy into the new node
 *
 * Return: pointer to new node, NULL on error (new_node)
 */
List *add_node_end(List **list, char *str)
{
    List *new_node;

    new_node = create_node(str);
    if (!new_node)
    {
        return (NULL);
    }

    update_links(list, new_node);

    return (new_node);
}