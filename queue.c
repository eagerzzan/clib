/*******************************************************************************
 * queue.c
 * queuue implementation
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

QUEUE* q_initialize(int init_size)
{
	QUEUE *p_q;

	p_q = (QUEUE *) malloc(sizeof(QUEUE));
	if (p_q == NULL) return NULL;
	else p_q->p_data = NULL;

	p_q->p_data = (ELEMENT_TYPE *) malloc(init_size * sizeof(ELEMENT_TYPE));
	if (p_q->p_data == NULL) return NULL;
	else
	{
		memset(p_q->p_data, 0, init_size * sizeof(ELEMENT_TYPE));
		p_q->front = 0;
		p_q->back = 0;
		p_q->size = init_size;
	}

	return p_q;
}

void q_deinitialize(QUEUE **pp_q)
{
	if (pp_q && *pp_q)
	{
		if ((*pp_q)->p_data)
			free((*pp_q)->p_data);

		free(*pp_q);
		*pp_q = NULL;
	}
}

int q_is_full(QUEUE *p_q)
{
	if (p_q && (p_q->back + 1) % p_q->size == p_q->front) return 1;
	else return 0;
}

int q_is_empty(QUEUE *p_q)
{
	if (p_q && p_q->back == p_q->front) return 1;
	else return 0;
}

int q_enqueue(QUEUE *p_q, ELEMENT_TYPE a)
{
	if (p_q == NULL) return -1;

	if (q_is_full(p_q)) return -1;
	else
	{
		p_q->p_data[p_q->back] = a;
		p_q->back = ++p_q->back % p_q->size;

		return 0;
	}
}

int q_peek(QUEUE *p_q, ELEMENT_TYPE *p_a)
{
	if (p_q == NULL || p_a == NULL) return -1;

	if (q_is_empty(p_q)) return -1;
	else
	{
		*p_a = p_q->p_data[p_q->front];

		return 0;
	}
}

int q_dequeue(QUEUE *p_q, ELEMENT_TYPE *p_a)
{
	if (p_q == NULL || p_a == NULL) return -1;

	if (q_is_empty(p_q)) return -1;
	else
	{
		*p_a = p_q->p_data[p_q->front];
		p_q->p_data[p_q->front] = 0;
		p_q->front = ++p_q->front % p_q->size;

		return 0;
	}
}

/* end of file */
