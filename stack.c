/*******************************************************************************
 * stack.c
 * source of stack
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#include "stack.h"
#include <stdlib.h>

STACK* s_create(int init_size)
{
	STACK *p_s;

	p_s = (STACK *) malloc(sizeof(STACK));
	if (p_s == NULL) return NULL;

	p_s->p_data = (ELEMENT_TYPE *) malloc(init_size * sizeof(ELEMENT_TYPE));
	p_s->top = -1;
	p_s->size = init_size;

	return p_s;
}

void s_destroy(STACK **pp_s)
{
	if (pp_s == NULL || *pp_s == NULL) return;

	if ((*pp_s)->p_data)
		free((*pp_s)->p_data);

	free(*pp_s);
	*pp_s = NULL;
}

int s_is_full(STACK *p_s)
{
	if (p_s == NULL) return 0;

	if (p_s->top == p_s->size - 1) return 1;
	else return 0;
}

int s_is_empty(STACK *p_s)
{
	if (p_s == NULL) return 0;

	if (p_s->top < 0) return 1;
	else return 0;
}

int s_push(STACK *p_s, ELEMENT_TYPE a)
{
	if (p_s == NULL) return 0;

	if (s_is_full(p_s)) return -1;
	else
	{
		p_s->p_data[++p_s->top] = a;
		return 0;
	}
}

int s_pop(STACK *p_s, ELEMENT_TYPE *p_a)
{
	if (p_s == NULL || p_a == NULL) return 0;

	if (s_is_empty(p_s)) return -1;
	else
	{
		*p_a = p_s->p_data[p_s->top--];
		return 0;
	}
}

int s_peek(STACK *p_s, ELEMENT_TYPE *p_a)
{
	if (p_s == NULL) return -1;

	if (s_is_empty(p_s)) return -1;
	else
	{
		*p_a = p_s->p_data[p_s->top];
		return 0;
	}
}

/* end of file */

