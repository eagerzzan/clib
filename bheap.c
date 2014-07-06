/*******************************************************************************
 * bheap.c
 * source of binary heap 
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "bheap.h"

ARRAY_HEAP* bheap_create(int init_size)
{
	ARRAY_HEAP *p_h = NULL;

	p_h = (ARRAY_HEAP *) malloc(sizeof(ARRAY_HEAP));

	p_h->p_elements = (HEAP_NODE *) malloc(sizeof(HEAP_NODE) * (init_size + 1));

	memset((void *) p_h->p_elements, 0, sizeof(HEAP_NODE) * (init_size + 1));
	p_h->p_elements[0].key = -INT_MAX;

	p_h->heap_size = init_size;
	p_h->last = 0;

	return p_h;
}

void bheap_destroy(ARRAY_HEAP **pp_h)
{
	if (pp_h && *pp_h)
	{
		if ((*pp_h)->p_elements)
			free((*pp_h)->p_elements);

		free(*pp_h);
		*pp_h = NULL;
	}
}

void siftdown(ARRAY_HEAP *p_h, int i)
{
	int parent, larger_child;
	HEAP_NODE siftkey;
	int spot_found;

	siftkey = p_h->p_elements[i];
	parent = i;
	spot_found = 0;

	while (2 * parent <= p_h->last && !spot_found)
	{
		if (2 * parent < p_h->last
				&& p_h->p_elements[2 * parent].key
				< p_h->p_elements[2 * parent + 1].key)
			larger_child = 2 * parent + 1;
		else
			larger_child = 2 * parent;

		if (siftkey.key < p_h->p_elements[larger_child].key)
		{
			p_h->p_elements[parent] = p_h->p_elements[larger_child];
			parent = larger_child;
		}
		else
			spot_found = 1;
	}

	p_h->p_elements[parent] = siftkey;
}
void bheap_push(ARRAY_HEAP *p_h, HEAP_NODE element)
{
	int i;

	if (p_h == NULL) return;

	if (p_h->last == p_h->heap_size) return;

	i = ++p_h->last;

	while ((i != 1) && (element.key > p_h->p_elements[i / 2].key))
	{
		p_h->p_elements[i] = p_h->p_elements[i / 2];
		i /= 2;
	}

	p_h->p_elements[i] = element;
}

void bheap_pop(ARRAY_HEAP *p_h, HEAP_NODE *p_element)
{
	*p_element = p_h->p_elements[1];
	p_h->p_elements[1] = p_h->p_elements[p_h->last];
	p_h->last--;
	siftdown(p_h, 1);
}

void bheap_make_heap(ARRAY_HEAP *p_h)
{
	int i;

	for (i = p_h->last / 2; i > 0; i--)
		siftdown(p_h, i);
}

/* end of file */

