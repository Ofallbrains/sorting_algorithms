#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending
 * @array: pointer
 * @size: array
 * Return:
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL)
if (size < 2)
return;
lomuto_alg(array, 0, size - 1, size);
}
/**
 * lomuto_alg - recursive
 * @point_array: pointer
 * @launch: starting
 * @close: ending
 * @size: array
 *
 * Return:
 */
void lomuto_alg(int *point_array, int launch, int close, size_t size)
{
	int piv_;

	if (launch < close)
	{
		piv_ = partition(point_array, launch, close, size);
		lomuto_alg(point_array, launch, piv_ - 1, size);
		lomuto_alg(point_array, piv_ + 1, close, size);
	}
}
/**
 * partition - partitions array
 *
 * @point_array: pointer
 * @launch: starting
 * @close: ending
 * @size: array
 * Return: aux
 */
int partition(int *point_array, size_t launch, size_t close, size_t size)
{
	size_t i = launch - 1;
	size_t k;
	int tmp_1 = 0;
	int aux_1 = 0;
	size_t aux_2 = 0;

	for (k = launch; k < close; k++)
	{
		if (point_array[k] < point_array[close])
		{
			i++;
			tmp_1 = point_array[i];
			point_array[i] = point_array[k];
			point_array[k] = tmp_1;
			if (point_array[k] != point_array[i])
				print_array(point_array, size);
		}
	}
	i++;
	aux_2 = i;
	aux_1 = point_array[i];
	point_array[i] = point_array[close];
	point_array[close] = aux_1;
	if (point_array[k] != point_array[i])
		print_array(point_array, size);
	return (aux_2);
}
