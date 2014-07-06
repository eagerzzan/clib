/*******************************************************************************
 * bheap.h
 * header of binary heap 
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _BHEAP_H
#define _BHEAP_H

#ifndef ELEMENT_TYPE
#define ELEMENT_TYPE int
#endif

typedef struct _HEAP_NODE
{
	int key;
	ELEMENT_TYPE data;
} HEAP_NODE;

typedef struct _ARRAY_HEAP
{
	HEAP_NODE *p_elements;
	int heap_size;
	int last;
} ARRAY_HEAP;

ARRAY_HEAP* bheap_create(int init_size);
void bheap_destroy(ARRAY_HEAP **pp_h);

void bheap_push(ARRAY_HEAP *p_h, HEAP_NODE element);
void bheap_pop(ARRAY_HEAP *p_h, HEAP_NODE *p_element);

void bheap_make_heap(ARRAY_HEAP *p_h);

#endif

/* end of file */

