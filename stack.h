/*******************************************************************************
 * stack.h
 * header of stack
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _STACK_H
#define _STACK_H

#define ELEMENT_TYPE int

typedef struct _STACK
{
	ELEMENT_TYPE *p_data;
	int top;
	int size;
} STACK;

STACK* s_create(int init_size);
void s_destroy(STACK **pp_s);

int s_is_full(STACK *p_s);
int s_is_empty(STACK *p_s);

int s_push(STACK *p_s, ELEMENT_TYPE a);
int s_pop(STACK *p_s, ELEMENT_TYPE *p_a);

int s_peek(STACK *p_s, ELEMENT_TYPE *p_a);

#endif

/* end of file */

