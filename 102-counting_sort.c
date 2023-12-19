#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void counting_sort(int *array, size_t size)
{
	int m, k, *count_array, *aux;
	size_t j;

	if (!array || size < 2)
		return;
	m = array[0];
	for (j = 0; j < size; j++)
	{
		if (array[j] > n)
			m = array[j];
	}
	count_array = calloc((m + 1), sizeof(int));
	for (j = 0; j < size; j++)
	{
		count_array[array[j]]++;
	}
	for (k = 1; k < m; k++)
	{
		count_array[k + 1] += count_array[k];
	}
	print_array(count_array, m + 1);
	aux = malloc(sizeof(int) * size);
	for (j = 0; j < size; j++)
	{
		count_array[array[j]]--;
		aux[count_array[array[j]]] = array[j];
	}
	for (j = 0; j < size; j++)
	{
		array[j] = aux[j];
	}
	free(aux);
	free(count_array);
}
