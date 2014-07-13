/*******************************************************************************
 * bst.h
 * binary search tree 
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _BST_H
#define _BST_H

#define ELEMENT_TYPE int

#ifndef BT_MAX_HEIGHT
#define BT_MAX_HEIGHT 32
#endif

typedef struct _BT_NODE
{
	int key;
	struct _BT_NODE *p_left;
	struct _BT_NODE *p_right;
} BT_NODE;

typedef struct _BT_ROOT
{
	struct _BT_NODE *p_node;
	int count;
} BT_ROOT;

BT_ROOT* bst_create(void);

void bst_destroy(BT_ROOT **pp_root);

BT_NODE* bst_make_node(int key);

void bst_insert(BT_ROOT *p_root, int key);

BT_NODE* bst_delete(BT_ROOT *p_root, int key);

void bst_preorder(BT_NODE *p_node);

BT_NODE* bst_search(BT_NODE *p_node, int key);

#endif

/* end of file */

