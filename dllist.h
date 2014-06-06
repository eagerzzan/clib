/*******************************************************************************
 * dllist.h
 * This file is header about doubly linked list.
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _D_LLIST_H
#define _D_LLIST_H

#define ELEMENT_TYPE int

typedef struct _DLL_NODE DLL_NODE;

struct _DLL_NODE
{
	ELEMENT_TYPE data;
	DLL_NODE *p_prev;
	DLL_NODE *p_next;
};

typedef struct _DLL_LIST
{
	DLL_NODE *p_head;
	unsigned int cnt;
} DLL_LIST;

DLL_LIST* dll_create(void);
void dll_destroy(DLL_LIST **pp_list);

DLL_NODE* dll_make_node(ELEMENT_TYPE data);

void dll_insert(DLL_LIST *p_list, DLL_NODE *p_prev, DLL_NODE *p_new);
void dll_delete(DLL_LIST *p_list, DLL_NODE *p_del);

DLL_NODE* dll_search_forward(DLL_LIST *p_list, ELEMENT_TYPE condition);
DLL_NODE* dll_search_backward(DLL_LIST *p_list, ELEMENT_TYPE condition);

void dll_print_list(DLL_LIST *p_list);

#endif

/* end of file */


