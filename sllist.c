/*******************************************************************************
 * sllist.c
 * This file is source file about singly circular linked list.
 *
 * If disable circular list, define DISABLE_CIRCULAR_LIST.
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#include "stdio.h"
#include "stdlib.h"
#include "sllist.h"

void sll_make_node(SLL_NODE **pp_node, ELEMENT_TYPE data)
{
	if (pp_node == NULL) return;

	*pp_node = (SLL_NODE *) malloc(sizeof(SLL_NODE));

	(*pp_node)->data = data;
	(*pp_node)->p_next = *pp_node;
}

void sll_insert_node(SLL_NODE *p_prev, SLL_NODE *p_new)
{
	SLL_NODE *p_tmp = NULL;

	if (p_prev == NULL || p_new == NULL) return;

	printf("Insert: %p, %d\n", p_new, p_new->data);

	p_new->p_next = p_prev->p_next;
	p_prev->p_next = p_new;
}

void sll_delete_node(SLL_NODE **pp_head, SLL_NODE *p_prev)
{
	SLL_NODE *p_del;

	if (*pp_head == NULL || p_prev == NULL) return;

	p_del = p_prev->p_next;

	printf("[DEL] HEAD : %p, n : %p\n", *pp_head, (*pp_head)->p_next);

	if (p_del == NULL) return;

#ifdef DISABLE_CIRCULAR_LIST
	p_prev->p_next = p_del->p_next;
#else
	if (p_del == p_del->p_next)
		*pp_head = NULL;
	else
	{
		p_prev->p_next = p_del->p_next;

		if (p_del == *pp_head)
			*pp_head = p_prev;
	}
#endif

	printf("Delete : %p\n", p_del);
	free(p_del);
}

void sll_print_node(SLL_NODE *p_head)
{
	SLL_NODE *p_tmp;

	if (p_head == NULL) return;

	p_tmp = p_head;

	do
	{
		printf("List Search : %d\n", p_tmp->data);
		p_tmp = p_tmp->p_next;
	}
	#ifdef DISABLE_CIRCULAR_LIST
	while (p_tmp);
	#else
	while (p_tmp != p_head);
	#endif
}

void sll_destruct(SLL_NODE **pp_head)
{
	SLL_NODE *p_cur, *p_tmp;

	if (pp_head == NULL || *pp_head == NULL) return;

	p_tmp = (*pp_head)->p_next;

	#ifdef DISABLE_CIRCULAR_LIST
	while (p_tmp)
	#else
	while (p_tmp != *pp_head)
	#endif
	{
		p_cur = p_tmp;
		p_tmp = p_cur->p_next;

		printf("Release : %p\n", p_cur);
		free(p_cur);
	}

	printf("Release : %p\n", *pp_head);
	free(*pp_head);
	*pp_head = NULL;
}

/* end of file */

