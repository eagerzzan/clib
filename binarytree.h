/*******************************************************************************
 * binarytree.h
 * This file is source about binary tree.
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#define ELEMENT_TYPE int

typedef struct _BT_NODE
{
	ELEMENT_TYPE key;
	struct _BT_NODE *p_left;
	struct _BT_NODE *p_right;
} BT_NODE;

typedef struct _BT_ROOT
{
	struct _BT_NODE *p_node;
} BT_ROOT;	

BT_ROOT* bint_create(void);
void bint_destroy(BT_ROOT **pp_root);

BT_NODE* bint_make_node(ELELEMENT_TYPE key);

void bint_insert(BT_ROOT *p_root, BT_NODE *p_node);
void bint_delete(BT_ROOT *p_root, BT_NODE *p_node);

#endif

/* end of file */
