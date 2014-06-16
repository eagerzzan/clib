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

#ifndef BST_MAX_HEIGHT
#define BST_MAX_HEIGHT 32
#endif

typedef struct _BST_NODE
{
	struct _BST_NODE *p_left;
	struct _BST_NODE *p_right;
	ELEMENT_TYPE data;
} BST_NODE;

typedef struct _BST_ROOT
{
	struct _BST_NODE *p_node;
	int count;
} BST_ROOT;

#endif

/* end of file */

