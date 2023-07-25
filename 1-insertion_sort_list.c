#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: the list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *tmp = NULL;

	if (list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	while (node)
	{
		while (node->next && (node->n > node->next->n))
		{
			tmp = node->next;
			node->next = tmp->next;
			tmp->prev = node->prev;
			if (node->prev != NULL)
				node->prev->next = tmp;
			if (tmp->next != NULL)
				tmp->next->prev = node;
			node->prev = tmp;
			tmp->next = node;
			if (tmp->prev)
				node = tmp->prev;
			else
				*list = tmp;
			print_list(*list);
		}

		node = node->next;
	}
}
