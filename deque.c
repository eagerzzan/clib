/*******************************************************************************
 * dequeue.c
 * double ended queue
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#include "deque.h"

QUEUE* deq_initialize(int init_size)
{
	QUEUE *p_q;

	p_q = q_initialize(init_size);

	return p_q;
}

void deq_deinitialize(QUEUE **pp_q)
{
	q_deinitialize(pp_q);
}

int deq_is_full(QUEUE *p_q)
{
	return q_is_full(p_q);
}

int deq_is_empty(QUEUE *p_q)
{
	return q_is_empty(p_q);
}

int deq_push_back(QUEUE *p_q, ELEMENT_TYPE a)
{
	return q_enqueue(p_q, a);
}

int deq_push_front(QUEUE *p_q, ELEMENT_TYPE a)
{
	if (p_q == NULL) return -1;

	if (deq_is_full(p_q)) return -1;
	else
	{
		if (p_q->front == 0) p_q->front = p_q->size - 1;
		else p_q->front--;

		p_q->p_data[p_q->front] = a;

		return 0;
	}
}

int deq_peek_back(QUEUE *p_q, ELEMENT_TYPE *p_a)
{
	if (p_q == NULL || p_a == NULL) return -1;

	if (deq_is_empty(p_q)) return -1;
	else
	{
		if (p_q->back == 0)
			*p_a = p_q->p_data[p_q->size - 1];
		else
			*p_a = p_q->p_data[p_q->back - 1];

		return 0;
	}
}

int deq_peek_front(QUEUE *p_q, ELEMENT_TYPE *p_a)
{
	return q_peek(p_q, p_a);
}

int deq_pop_back(QUEUE *p_q, ELEMENT_TYPE *p_a)
{
	if (p_q == NULL || p_a == NULL) return -1;

	if (deq_is_empty(p_q)) return -1;
	else
	{
		if (p_q->back == 0)
			p_q->back = p_q->size - 1;
		else
			p_q->back--;

		*p_a = p_q->p_data[p_q->back];
		p_q->p_data[p_q->back] = 0;

		return 0;
	}
}

int deq_pop_front(QUEUE *p_q, ELEMENT_TYPE *p_a)
{
	return q_dequeue(p_q, p_a);
}

/* end of file */

