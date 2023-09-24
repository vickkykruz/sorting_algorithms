#include "sort.h"
/**
 * sh_sort - This is a function that return the sorted array of integers
 * @arr: This is an argument that represent the given array
 * @size: This is an argument that reprsent the given size
 * @num: This is an argument that reprsent the given number
 *
 * Return: This is a function return nothing (void)
 */
void sh_sort(int *arr, int size, int num)
{
	int tmp, i, j;

	for (i = 0; (i + num) < size; i++)
	{
		for (j = i + num; (j - num) >= 0; j = j - num)
		{
			if (arr[j] < arr[j - num])
			{
				/** Swap the value **/
				tmp = arr[j];
				arr[j] = arr[j - num];
				arr[j - num] = tmp;
			}
		}
	}
	print_array(arr, size);
}
/**
 * shell_sort - This is a function that sorts an array of integers in
 * ascending order using Shell sort
 * @array: This is an argument thst reprsent the given array
 * @size: This is an argument that represent the given size
 *
 * Return: This function return an array of integers in ascending order
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;

	while ((n = (n - 1) / 3) > 0)
		sh_sort(array, size, n);
}
