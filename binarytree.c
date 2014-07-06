/*******************************************************************************
 * binarytree.c
 * This file is source about binary tree.
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "binarytree.h"

BT_ROOT* bint_create(void)
{
	BT_ROOT *p_root = NULL;

	p_root = (BT_ROOT *) malloc(sizeof(BT_ROOT));
	if (p_root)
		p_root->p_node = NULL;

	return p_root;
}

void _bint_destory_node(BT_NODE *p_node)
{
	if (p_node)
	{
		_bint_destroy_node(p_node->p_left);
		_bint_destroy_node(p_node->p_right);

		printf("Release : %p\n", p_node);
		free(p_node);
	}
}

void bint_destroy(BT_ROOT **pp_root)
{
	BT_NODE *p_node;

	if (pp_root == NULL || *pp_root == NULL) return;

	p_node = (*pp_root)->p_node;
	if (p_node)
		_bint_destroy_node(p_node);

	free(*pp_root);
	*pp_root = NULL;
}

BT_NODE* bint_make_node(ELELEMENT_TYPE key)
{
	BT_NODE *p_node;

	p_node = (BT_NODE *) malloc(sizeof(BT_NODE));
	if (p_node)
	{
		p_node->key = key;
		p_node->p_left = NULL;
		p_node->p_right = NULL;
	}

	return p_node;
}

void bint_insert(BT_ROOT *p_root, BT_NODE *p_node)
{
	BT_NODE *p_tmp = NULL, *p_parent;

	if (p_root == NULL || p_node == NULL) return;

	if (p_root->p_node == NULL)
		p_root->p_node = p_node;
	else
	{
		p_parent = p_root->p_node;

		while (p_parent)
		{
			if (p_node->key < p_parent->key)
			{
				p_tmp = p_parent->p_left;
				if (p_tmp == NULL)
					p_parent->p_left = p_node;
			}
			else
			{
				p_tmp = p_parent->p_right;
				if (p_tmp == NULL)
					p_parent->p_right = p_node;
			}

			p_parent = p_tmp;
		}
	}
}

void bint_delete(BT_ROOT *p_root, BT_NODE *p_node)
{

}

/* end of file */
