#include "sort.h"
/**
 * swp_nodes - This is a function that return the swap list value
 * @list: This is an argument that reprsent the listint_t struct
 * @n1: This is an argument that reprsent the first node
 * @n2: This is an argument that reprsent the second node
 *
 * Return: This function return nothing (void)
 */
void swp_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	listint_t *next, *prev;

	prev = n1->prev;
	if (prev)
		prev->next = n2;
	n2->prev = prev;
	n1->prev = n2;
	next = n2->next;
	if (next)
		next->prev = n1;
	n1->next = next;
	n2->next = n1;
	if (*list == n1)
		*list = n2;
}

/**
 * insertion_sort_list - This is a function that sorts a double linked list
 * of an integer in ascending order
 * @list: This is an argument that repesent the struct listint_t
 *
 * Return: This function return a double linked list in ascending order
 */
void insertion_sort_list(listint_t **list)
{
	int swp;
	listint_t *tmp = *list;
	listint_t *tmp2;

	if (!(*list))
		return;

	while (tmp->next)
	{
		swp = 0;
		if (tmp->n > tmp->next->n)
		{
			swp_nodes(list, tmp, tmp->next);
			swp = 1;
			print_list(*list);
		}

		if (swp == 1)
		{
			tmp2 = tmp->prev;
			while (tmp2->prev)
			{
				if (tmp2->n < tmp2->prev->n)
				{
					swp_nodes(list, tmp2->prev, tmp2);
					print_list(*list);
				}
				else
					break;
			}
		}
		else
			tmp = tmp->next;
	}
}
