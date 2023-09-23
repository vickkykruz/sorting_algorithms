#include "sort.h"
/**
 * quick_sort - This is a function that return the sort array of integers in
 * ascending order
 * @array: This is an argumemt that reprsent the given array
 * @size: This is an argument that reprsent the given size
 *
 * Return: This function return the sorted array integers
 */
void quick_sort(int *array, size_t size)
{
	lomuto_partition(array, 0, size - 1, size);
}
/**
 * lomuto_partition - This is a function that auaxilar the function for the
 * quick sort
 * @arr: This is an argument that reprsent the given array
 * @low: This is an argument that reprsent the first index of the array
 * @high: This is an argument that reprsent the last index of the array
 * @size: This is an argumemt thay reprsent the given size of the array
 *
 * Return: This function return nothing (void)
 */
void lomuto_partition(int *arr, int low, int high, int size)
{
	int tmp, i, h, l;

	if (low < high)
	{
		h = high;
		l = low;

		for (i = low; i < high; i++)
		{
			if (arr[i] < arr[h])
			{
				if (i != l)
				{
					tmp = arr[i];
					arr[i] = arr[l];
					arr[l] = tmp;
					print_array(arr, size);
				}
				l++;
			}
		}

		if (l != h && arr[l] != arr[h])
		{
			tmp = arr[l];
			arr[l] = arr[h];
			arr[h] = tmp;
			print_array(arr, size);
		}
		lomuto_partition(arr, low, l - 1, size);
		lomuto_partition(arr, l + 1, high, size);
	}
}
