#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked list
 * @h: Pointer to the head of the head of the linked list
 *
 * Return: The number of elements in the linked list.
 */
size_t listint_len(const listint_t *h)
{
	const listint_t *current = h;
	size_t count = 0;

	while (current != NULL)
	{
	current = current->next;
	count++;
	}
	return (count);
}
