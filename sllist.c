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

SLL_LIST* sll_create(void)
{
	SLL_LIST *p_list;

	p_list = (SLL_LIST *) malloc(sizeof(SLL_LIST));
	if (p_list == NULL) return NULL;

	p_list->p_head = NULL;
	p_list->cnt = 0;

	return p_list;
}

void sll_destroy(SLL_LIST **pp_list)
{
	SLL_NODE *p_cur, *p_tmp;

	if (pp_list == NULL || *pp_list == NULL) return;

	if ((*pp_list)->p_head)
	{
		p_tmp = (*pp_list)->p_head->p_next;

#ifdef DISABLE_CIRCULAR_LIST
		while (p_tmp)
#else
		while (p_tmp != (*pp_list)->p_head)
#endif
		{
			p_cur = p_tmp;
			p_tmp = p_cur->p_next;

			printf("Release : %p\n", p_cur);
			free(p_cur);
		}

		printf("Release : %p\n", (*pp_list)->p_head);
		free((*pp_list)->p_head);
		(*pp_list)->p_head = NULL;
	}

	free(*pp_list);
	*pp_list = NULL;
}

SLL_NODE* sll_make_node(ELEMENT_TYPE data)
{
	SLL_NODE *p_node;

	p_node = (SLL_NODE *) malloc(sizeof(SLL_NODE));

	p_node->data = data;

#ifdef DISABLE_CIRCULAR_LIST
	p_node->p_next = NULL;
#else
	p_node->p_next = p_node;
#endif

	return p_node;
}

void sll_insert(SLL_LIST *p_list, SLL_NODE *p_prev, SLL_NODE *p_new)
{
	SLL_NODE *p_tmp = NULL;

	if (p_list == NULL || p_prev == NULL || p_new == NULL) return;

	printf("Insert: %p, %d\n", p_new, p_new->data);

	if (p_list->p_head == NULL)
		p_list->p_head = p_new;
	else
	{
		p_new->p_next = p_prev->p_next;
		p_prev->p_next = p_new;
	}
}

void sll_delete(SLL_LIST *p_list, SLL_NODE *p_prev)
{
	SLL_NODE *p_del;

	if (p_list == NULL || p_list->p_head == NULL)
		return;

#ifdef DISABLE_CIRCULAR_LIST
	if (p_prev == NULL)
	{
		p_del = p_list->p_head;
		p_list->p_head = p_head->p_next;
	}
	else
	{
		p_del = p_prev->p_next;
		p_prev->p_next = p_prev->p_next->p_next;
	}
#else
	if (p_prev == NULL) return;

	p_del = p_prev->p_next;

	if (p_del == p_del->p_next)
		p_list->p_head = NULL;
	else
	{
		p_prev->p_next = p_del->p_next;

		if (p_del == p_list->p_head)
			p_list->p_head = p_del->p_next;
	}
#endif

	printf("Delete : %p\n", p_del);
	free(p_del);
}

void sll_print_list(SLL_LIST *p_list)
{
	SLL_NODE *p_tmp;

	if (p_list == NULL || p_list->p_head == NULL) return;

	p_tmp = p_list->p_head;

	do
	{
		printf("List Search : %d\n", p_tmp->data);
		p_tmp = p_tmp->p_next;
	}
#ifdef DISABLE_CIRCULAR_LIST
	while (p_tmp);
#else
	while (p_tmp != p_list->p_head);
#endif
}

/* end of file */

