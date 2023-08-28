#include "lists.h"

/**
 * print_listint - Prints all elements of a linked list
 * @h: Pointer to the head of the linked list.
 *
 * Return: Number of nodes in the linked list.
 */
size_t print_listint(const listint_t *h)
{
const listint_t *current = h;
size_t count = 0;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
count++;
}

return (count);
}
