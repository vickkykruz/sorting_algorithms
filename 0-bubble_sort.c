#include "sort.h"
/**
 * bubble_sort - This is a function that sorts an array of integer in
 * ascending order
 * @array: This is an argument that reprsent the array
 * @size: This is an argument that reprsent the size
 *
 * Return: This function return the sorted array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swp;

	if (!array || !array[1])
		return;

	for (i = 0; i < size; i++)
	{
		swp = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/** Swap the array index **/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swp = 1;
				print_array(array, size);
			}
		}
		if (swp == 0)
			break;
	}
}
