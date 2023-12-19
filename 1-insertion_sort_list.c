#include "sort.h"
/**
 *insertion_sort_list - sorting algorithm
 *@list: double pointer
 *Return: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux_1_c = NULL;
	listint_t *aux_2_t = NULL;
	listint_t *aux_3_h = NULL;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	aux_1_c = (*list)->next;
	while (aux_1_c)
	{
		aux_2_t = aux_1_c->prev;
		aux_3_h = aux_1_c->next;
		while (aux_2_t && aux_1_c->n < aux_2_t->n)
		{
			aux_3_h = aux_1_c->next;
			if (aux_2_t->prev != NULL)
				aux_2_t->prev->next = aux_1_c;
			aux_1_c->prev = aux_2_t->prev;
			aux_2_t->prev = aux_1_c;
			aux_1_c->next = aux_2_t;
			aux_2_t->next = aux_3_h;
			if (aux_3_h)
				aux_3_h->prev = aux_2_t;
			if (!aux_1_c->prev)
				(*list) = aux_1_c;
			print_list(*list);
			aux_2_t = aux_1_c->prev;
		}
		aux_1_c = aux_3_h;
	}
}
