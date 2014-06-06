/*******************************************************************************
 * dllist.c
 * This file is source abuot doubly linked list.
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#include "dllist.h"
#include <stdio.h>
#include <stdlib.h>

DLL_LIST* dll_create(void)
{
	DLL_LIST *p_list;

	p_list = (DLL_LIST *) malloc(sizeof(DLL_LIST));
	if (p_list == NULL) return NULL;

	p_list->p_head = NULL;
	p_list->cnt = 0;

	return p_list;
}

void dll_destroy(DLL_LIST **pp_list)
{
	DLL_NODE *p_cur, *p_tmp;

	if (pp_list == NULL || *pp_list == NULL) return;

	if ((*pp_list)->p_head)
	{
		p_tmp = (*pp_list)->p_head->p_next;

		while (p_tmp != (*pp_list)->p_head)
		{
			p_cur = p_tmp;
			p_tmp = p_cur->p_next;

			free(p_cur);
		}

		free((*pp_list)->p_head);
		(*pp_list)->p_head = NULL;
	}

	free(*pp_list);
	*pp_list = NULL;
}

DLL_NODE* dll_make_node(ELEMENT_TYPE data)
{
	DLL_NODE *p_node;

	p_node = (DLL_NODE *) malloc(sizeof(DLL_NODE));
	if (p_node == NULL) return NULL;

	p_node->data = data;
	p_node->p_prev = p_node;
	p_node->p_next = p_node;

	return p_node;
}

void dll_insert(DLL_LIST *p_list, DLL_NODE *p_prev, DLL_NODE *p_new)
{
	if (p_list == NULL || p_prev == NULL || p_new == NULL) return;

	if (p_list->p_head == NULL)
	{
		p_new->p_next = p_new;
		p_new->p_prev = p_new;
		p_list->p_head = p_new;
	}
	else
	{
		p_prev->p_next->p_prev = p_new;
		p_new->p_next = p_prev->p_next;
		p_new->p_prev = p_prev;
		p_prev->p_next = p_new;
	}
}

void dll_delete(DLL_LIST *p_list, DLL_NODE *p_del)
{
	if (p_list == NULL || p_list->p_head == NULL | p_del == NULL) return;

	if (p_del == p_del->p_next)
		p_list->p_head = NULL;
	else
	{
		p_del->p_next->p_prev = p_del->p_prev;
		p_del->p_prev->p_next = p_del->p_next;

		if (p_del == p_list->p_head)
			p_list->p_head = p_del->p_next;
	}

	free(p_del);
}

DLL_NODE* dll_search_forward(DLL_LIST *p_list, ELEMENT_TYPE condition)
{
	DLL_NODE *p_tmp;

	if (p_list == NULL || p_list->p_head == NULL) return NULL;

	p_tmp = p_list->p_head;

	while (p_tmp)
	{
		if (condition == p_tmp->data)
			break;

		p_tmp = p_tmp->p_next;
	}

	return p_tmp;
}

DLL_NODE* dll_search_backward(DLL_LIST *p_list, ELEMENT_TYPE condition)
{
	DLL_NODE *p_tmp;

	if (p_list == NULL || p_list->p_head == NULL) return NULL;

	p_tmp = p_list->p_head;

	while (p_tmp)
	{
		if (condition == p_tmp->data)
			break;

		p_tmp = p_tmp->p_prev;
	}

	return p_tmp;
}

void dll_print_list(DLL_LIST *p_list)
{
	DLL_NODE *p_tmp;

	if (p_list == NULL || p_list->p_head == NULL) return;

	p_tmp = p_list->p_head;

	do
	{
		printf("List Search : %p, %d\n", p_tmp, p_tmp->data);

		p_tmp = p_tmp->p_next;
	}
	while (p_tmp != p_list->p_head);
}

/* end of file */

