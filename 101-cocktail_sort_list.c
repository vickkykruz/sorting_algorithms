#include "sort.h"
/**
 * swap_list - This is a function does the swap operation and return the list
 * @ptr1: This is an argument that reprsent the first pointer
 * @ptr2: This is an argument that reprsent the second pointer
 * @n: This is an argument that reprsent the 0 for increase otherwise 1 for
 * decrease
 *
 * Return: This function returns a void (nothing)
 */
void swap_list(listint_t **ptr1, listint_t **ptr2, int n)
{
	listint_t *tmp1, *tmp2;

	tmp1 = *ptr1;
	tmp2 = *ptr2;

	tmp1->next = tmp2->next;
	tmp2->prev = tmp1->prev;

	if (tmp2->next)
		tmp2->next->prev = tmp1;
	if (tmp1->prev)
		tmp1->prev->next = tmp2;

	tmp1->prev = tmp2;
	tmp2->next = tmp1;

	if (n == 0)
		*ptr1 = tmp2;
	else
		*ptr2 = tmp1;
}
/**
 * increase_sort_list - This is a function that return largest number to the
 * end of the list
 * @ptr: This is an argument thay reprsent the given pointer that points to
 * the largest number
 * @tmp: This is an argument that reprsent the given limit of the list
 * @list: This is an argument that reprsent the listint_t struct
 *
 * Return: This function returns a void (nothing)
 */
void increase_sort_list(listint_t **ptr, listint_t **tmp, listint_t **list)
{
	listint_t *lt_sort = *ptr;

	while (lt_sort != *tmp && lt_sort->next != *tmp)
	{
		if (lt_sort->n > lt_sort->next->n)
		{
			swap_list(&lt_sort, &(lt_sort->next), 0);
			if (lt_sort->prev == NULL)
				*list = lt_sort;
			print_list(*list);
		}
		lt_sort = lt_sort->next;
	}
	*tmp = lt_sort;
	*ptr = lt_sort;
}
/**
 * decrease_sort_list - This is a function that return smallest number to the
 * to the start
 * @ptr: This is an argument that reprsent the given pointer that points to
 * the smallest number
 * @tmp: This is an argument that reprsent the given limit of the list
 * @list: This is an argument that reprsent the listint_t struct
 *
 * Return: This function return a void (nothing)
 */
void decrease_sort_list(listint_t **ptr, listint_t **tmp, listint_t **list)
{
	listint_t *lt_sort = *ptr;

	while (lt_sort != *tmp && lt_sort->prev != *tmp)
	{
		if (lt_sort->n < lt_sort->prev->n)
		{
			swap_list(&(lt_sort->prev), &lt_sort, 1);
			if (lt_sort->prev->prev == NULL)
				*list = lt_sort->prev;
			print_list(*list);
		}
		lt_sort = lt_sort->prev;
	}
	*tmp = lt_sort;
	*ptr = lt_sort;
}
/**
 * cocktail_sort_list - This is a function that sorts a doubly linked list of
 * integers in ascending order using the Cocktail shaker sort algorithm
 * @list: This is an argument that reprsent the given list
 *
 * Return: This function return the sorted doubled list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp1, *tmp2, *ptr;

	if (list == NULL || *list == NULL)
		return;

	tmp1 = tmp2 = NULL;
	ptr = *list;

	do {
		increase_sort_list(&ptr, &tmp1, list);
		decrease_sort_list(&ptr, &tmp2, list);
	} while (tmp1 != tmp2);
}
