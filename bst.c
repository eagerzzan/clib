/*******************************************************************************
 * bst.c
 * binary search tree 
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

BT_ROOT* bst_create(void)
{
	BT_ROOT *p_root = NULL;

	p_root = (BT_ROOT *) malloc(sizeof(BT_ROOT));
	if (p_root)
	{
		p_root->p_node = NULL;
		p_root->count = 0;
	}

	return p_root;
}

void _bst_destroy_recursively(BT_NODE *p_node)
{
	if (p_node == NULL) return;

	_bst_destroy_recursively(p_node->p_left);
	_bst_destroy_recursively(p_node->p_right);

	printf("release : %p\n", p_node);
	free(p_node);
}

void bst_destroy(BT_ROOT **pp_root)
{
	if (pp_root == NULL || *pp_root == NULL) return;

	if ((*pp_root)->p_node)
		_bst_destroy_recursively((*pp_root)->p_node);

	free(*pp_root);
	*pp_root = NULL;
}

BT_NODE* bst_make_node(int key)
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

BT_NODE* _bst_insert_recursively(BT_NODE *p_node, int key)
{
	if (p_node == NULL)
	{
		p_node = bst_make_node(key);
		printf("p_tmp : %p, %d\n", p_node, key);
	}
	else if (key < p_node->key)
		p_node->p_left = _bst_insert_recursively(p_node->p_left, key);
	else if (key > p_node->key)
		p_node->p_right = _bst_insert_recursively(p_node->p_right, key);

	return p_node;
}

void bst_insert(BT_ROOT *p_root, int key)
{
	if (p_root == NULL) return;

	p_root->p_node = _bst_insert_recursively(p_root->p_node, key);
}

BT_NODE* _bst_delete_recursively(BT_NODE *p_node, int key)
{
	BT_NODE *p_tmp;

	if (p_node == NULL) return NULL;
	else if (key < p_node->key)
		p_node->p_left = _bst_delete_recursively(p_node->p_left, key);
	else if (key > p_node->key)
		p_node->p_right = _bst_delete_recursively(p_node->p_right, key);
	else if (p_node->p_left && p_node->p_right)
	{
		p_tmp = p_node->p_right;

		while (p_tmp->p_left)
			p_tmp = p_tmp->p_left;
		
		p_node->key = p_tmp->key;
		p_node->p_right = _bst_delete_recursively(p_node->p_right, p_tmp->key);
	}
	else
	{
		p_tmp = p_node;

		if (p_node->p_right)
			p_node = p_node->p_right;
		else if (p_node->p_left)
			p_node = p_node->p_left;
		else
			p_node = NULL;

		printf("release : %p\n", p_tmp);
		free(p_tmp);
	}

	return p_node;
}

BT_NODE* bst_delete(BT_ROOT *p_root, int key)
{
	if (p_root == NULL || p_root->p_node == NULL) return NULL;

	return _bst_delete_recursively(p_root->p_node, key);
}

void bst_preorder(BT_NODE *p_node)
{
	if (p_node == NULL) return;

	printf("%d ", p_node->key);

	if (p_node->p_left) bst_preorder(p_node->p_left);
	if (p_node->p_right) bst_preorder(p_node->p_right);
}

BT_NODE* bst_search(BT_NODE *p_node, int key)
{
	if (p_node == NULL)
		return NULL;
	else if (p_node->key > key)
		return bst_search(p_node->p_left, key);
	else if (p_node->key < key)
		return bst_search(p_node->p_right, key);
	else
		return p_node;
}

/* end of file */

