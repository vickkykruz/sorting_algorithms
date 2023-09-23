#include "sort.h"
/**
 * selection_sort - This is a function that return the sorts an array of
 * integers in ascending order using Selction algorthms
 * @array: This is an argument that reprsent the given array
 * @size: This is an argument that reprsent the given size
 *
 * Return: This function return the sort arrays in ascending order
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, idx;

	for (i = 0; i < size; i++)
	{
		tmp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (tmp > array[j])
			{
				tmp = array[j];
				idx = j;
			}
		}
		if (tmp != array[i])
		{
			array[idx] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
