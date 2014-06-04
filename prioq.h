/*******************************************************************************
 * prioq.h
 * priority queue 
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _PRIO_QUEUE_H
#define _PRIO_QUEUE_H

#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ELEMENT_TYPE int

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

ARRAY_HEAP* prioq_initialize(int qsize);
void prioq_deinitialize(ARRAY_HEAP **pp_prioq);

void prioq_push(ARRAY_HEAP *p_prioq, HEAP_NODE element);
void prioq_pop(ARRAY_HEAP *p_prioq, HEAP_NODE *p_element);
void prioq_peek(ARRAY_HEAP *p_prioq, HEAP_NODE *p_element);

#endif

/* end of file */

