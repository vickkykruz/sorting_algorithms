#include "sort.h"
/**
 * counting_sort - This is a function that sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: This is an argumentss that reprsent the given array
 * @size: This is an argument that reprsent the given size
 *
 * Return: This function that return the sorted array
 */
void counting_sort(int *array, size_t size)
{
	int i, n, *buff, *arr;

	if (size < 2)
		return;

	for (i = n = 0; i < (int)size; i++)
		if (array[i] > n)
			n = array[i];
	buff = malloc(sizeof(int) * (n + 1));
	if (!buff)
		return;

	for (i = 0; i <= n; i++)
		buff[i] = 0;
	for (i = 0; i < (int)size; i++)
		buff[array[i]] += 1;
	for (i = 1; i <= n; i++)
		buff[i] += buff[i - 1];

	print_array(buff, (n + 1));
	arr = malloc(sizeof(int) * (size + 1));

	if (!arr)
	{
		free(buff);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		arr[buff[array[i]] -  1] = array[i];
		buff[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = arr[i];
	free(buff);
	free(arr);
}
