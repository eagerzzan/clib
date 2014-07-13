/*******************************************************************************
 * avl.h
 * header of avl tree
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _AVL_H
#define _AVL_H

#define ELEMENT_TYPE int

#ifndef BT_MAX_HEIGHT
#define BT_MAX_HEIGHT 32
#endif

typedef struct _AVL_NODE
{
	int key;
	struct _AVL_NODE *p_left;
	struct _AVL_NODE *p_right;
	int height;
} AVL_NODE;

typedef struct _AVL_ROOT
{
	struct _AVL_NODE *p_node;
	int count;
} AVL_ROOT;

AVL_ROOT* avl_create(void);

void avl_destroy(AVL_ROOT **pp_root);

AVL_NODE* avl_make_node(int key);

AVL_NODE* avl_insert(AVL_ROOT *p_root, int key);

AVL_NODE* avl_delete(AVL_ROOT *p_root, int key);

void avl_preorder(AVL_NODE *p_node);

AVL_NODE* avl_search(AVL_NODE *p_node, int key);

#endif

/* end of file */

