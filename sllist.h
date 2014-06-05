/*******************************************************************************
 * sllist.h
 * This file is header about singly circular linked list.
 *
 * If disable circular list, define DISABLE_CIRCULAR_LIST .
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _SLLIST_H
#define _SLLIST_H

//#define DISABLE_CIRCULAR_LIST

#define ELEMENT_TYPE int

typedef struct _SLL_NODE
{
	ELEMENT_TYPE data;
	struct _SLL_NODE *p_next;
} SLL_NODE;

void sll_make_node(SLL_NODE **pp_node, ELEMENT_TYPE data);
void sll_insert_node(SLL_NODE *p_prev, SLL_NODE *p_new);
void sll_delete_node(SLL_NODE **p_head, SLL_NODE *p_prev);
void sll_print_node(SLL_NODE *p_head);
void sll_destruct(SLL_NODE **pp_head);

#endif

/* end of file */

