#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the list_t list to print
 *
 * Return: the number of nodes
 */

size_t print_list(const list_t *h)
{
unsigned long s = 0;

while (h != NULL)
{
if (h->str == NULL)
{

printf("[0] (nil)\n");
}
else
{
unsigned long len = 0;

while (h->str[len] != '\0')
{
len++;
}
printf("[%lu] %s, len = %lu\n", s, h->str, len);
}
s++;
h = h->next;
}

return (s);

}
