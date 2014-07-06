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

#define DISABLE_CIRCULAR_LIST

#define ELEMENT_TYPE int

typedef struct _SLL_NODE
{
	ELEMENT_TYPE data;
	struct _SLL_NODE *p_next;
} SLL_NODE;

typedef struct _SLL_LIST
{
	SLL_NODE *p_head;
	unsigned int cnt;
} SLL_LIST;

SLL_LIST* sll_create(void);
void sll_destroy(SLL_LIST **pp_list);

SLL_NODE* sll_make_node(ELEMENT_TYPE data);

void sll_insert(SLL_LIST *p_list, SLL_NODE *p_prev, SLL_NODE *p_new);
void sll_insert_back(SLL_LIST *p_list, SLL_NODE *p_new);
void sll_delete(SLL_LIST *p_list, SLL_NODE *p_prev);

int sll_is_lastnode(SLL_NODE *p_node);

void sll_print_list(SLL_LIST *p_list);

#endif

/* end of file */

