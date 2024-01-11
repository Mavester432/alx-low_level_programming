#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list.
 * @head: Pointer to the head of the list.
 *
 * Return: Void.
 **/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	if (head == NULL)
	return;

	while (head)
	{
	current = head;
	head = head->next;
	free(current);
	}
}
