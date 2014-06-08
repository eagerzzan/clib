/*******************************************************************************
 * dequeue.h
 * double ended queue
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _DE_QUEUE_H
#define _DE_QUEUE_H

#include <stdlib.h>
#include <string.h>

#include "queue.h"

QUEUE* deq_create(int init_size);
void deq_destroy(QUEUE **pp_q);
int deq_is_full(QUEUE *p_q);
int deq_is_empty(QUEUE *p_q);
int deq_push_back(QUEUE *p_q, ELEMENT_TYPE a);
int deq_push_front(QUEUE *p_q, ELEMENT_TYPE a);
int deq_peek_back(QUEUE *p_q, ELEMENT_TYPE *p_a);
int deq_peek_front(QUEUE *p_q, ELEMENT_TYPE *p_a);
int deq_pop_back(QUEUE *p_q, ELEMENT_TYPE *p_a);
int deq_pop_front(QUEUE *p_q, ELEMENT_TYPE *p_a);

#endif

/* end of file */
