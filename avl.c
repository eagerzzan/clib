/*******************************************************************************
 * avl.c
 * source of avl tree
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

AVL_ROOT* avl_create(void)
{
	AVL_ROOT *p_root = NULL;

	p_root = (AVL_ROOT *) malloc(sizeof(AVL_ROOT));
	if (p_root)
	{
		p_root->p_node = NULL;
		p_root->count = 0;
	}

	return p_root;
}

void _avl_destroy_recursively(AVL_NODE *p_node)
{
	if (p_node == NULL) return;

	_avl_destroy_recursively(p_node->p_left);
	_avl_destroy_recursively(p_node->p_right);

	printf("release : %p\n", p_node);
	free(p_node);
}

void avl_destroy(AVL_ROOT **pp_root)
{
	if (pp_root == NULL || *pp_root == NULL) return;

	if ((*pp_root)->p_node)
		_avl_destroy_recursively((*pp_root)->p_node);

	free(*pp_root);
	*pp_root = NULL;
}

AVL_NODE* avl_find_min(AVL_NODE *p_node)
{
	if (p_node == NULL)
		return NULL;
	else if (p_node->p_left == NULL)
		return p_node;
	else
		return avl_find_min(p_node->p_left);
}

AVL_NODE* avl_find_max(AVL_NODE *p_node)
{
	if (p_node == NULL)
		return NULL;
	else if (p_node->p_right == NULL)
		return p_node;
	else
		return avl_find_max(p_node->p_right);
}

int avl_get_height(AVL_NODE *p_node)
{
	if (p_node == NULL)
		return -1;
	else
		return p_node->height;
}

int avl_compare_height(AVL_NODE *pa, AVL_NODE *pb)
{
	if (pa && pb)
		return pa->height - pb->height;
	else if (pa)
		return pa->height;
	else if (pb)
		return -pb->height;
	else
		return 0;
}

int avl_get_max_height(AVL_NODE *pa, AVL_NODE *pb)
{
	if (pa && pb)
		return (pa->height > pb->height) ? pa->height : pb->height;
	else if (pa)
		return pa->height;
	else if (pb)
		return pb->height;
	else
		return 0;
}

AVL_NODE* avl_rotate_with_left(AVL_NODE *p_node)
{
	AVL_NODE *p_tmp = NULL;

	if (p_node == NULL) return NULL;

	p_tmp = p_node->p_left;
	if (p_tmp)
	{
		p_node->p_left = p_tmp->p_right;
		p_tmp->p_right = p_node;
	}
	else
		p_node->p_left = NULL;

	p_node->height = avl_get_max_height(p_node->p_left, p_node->p_right) + 1;

	if (p_tmp)
		p_tmp->height = avl_get_max_height(p_tmp->p_left, p_node) + 1;

	return p_tmp;
}

AVL_NODE* avl_rotate_with_right(AVL_NODE *p_node)
{
	AVL_NODE *p_tmp = NULL;

	if (p_node == NULL) return NULL;

	p_tmp = p_node->p_right;
	if (p_tmp)
	{
		p_node->p_right = p_tmp->p_left;
		p_tmp->p_left = p_node;
	}
	else
		p_node->p_right = NULL;

	p_node->height = avl_get_max_height(p_node->p_left, p_node->p_right) + 1;

	if (p_tmp)
		p_tmp->height = avl_get_max_height(p_tmp->p_right, p_node) + 1;

	return p_tmp;
}

AVL_NODE* avl_rotate_with_right_left(AVL_NODE *p_node)
{
	if (p_node)
		p_node->p_left = avl_rotate_with_right(p_node->p_left);

	return avl_rotate_with_left(p_node);
}

AVL_NODE* avl_rotate_with_left_right(AVL_NODE *p_node)
{
	if (p_node)
		p_node->p_right = avl_rotate_with_left(p_node->p_right);

	return avl_rotate_with_right(p_node);
}

AVL_NODE* avl_make_node(int key)
{
	AVL_NODE *p_node;

	p_node = (AVL_NODE *) malloc(sizeof(AVL_NODE));
	if (p_node)
	{
		p_node->key = key;
		p_node->p_left = NULL;
		p_node->p_right = NULL;
		p_node->height = 0;
	}

	return p_node;
}

AVL_NODE* _avl_insert(AVL_NODE *p_node, int key)
{
	if (p_node == NULL)
		p_node = avl_make_node(key);
	else if (key < p_node->key)
	{
		p_node->p_left = _avl_insert(p_node->p_left, key);

		if (avl_compare_height(p_node->p_left, p_node->p_right) > 1)
		{
			if (p_node->p_left && p_node->p_left->key > key)
			{
				printf("####### 1. Insert %d\n", key);
				p_node = avl_rotate_with_left(p_node);
			}
			else
			{
				printf("####### 2. Insert %d\n", key);
				p_node = avl_rotate_with_right_left(p_node);	
			}
		}
	}
	else if (key > p_node->key)
	{
		p_node->p_right = _avl_insert(p_node->p_right, key);

		if (avl_compare_height(p_node->p_right, p_node->p_left) > 1)
		{
			if (p_node->p_right && p_node->p_right->key < key)
			{
				printf("####### 3. Insert %d\n", key);
				p_node = avl_rotate_with_right(p_node);
			}
			else
			{
				printf("####### 4. Insert %d\n", key);
				p_node = avl_rotate_with_left_right(p_node);
			}
		}
	}

	p_node->height = avl_get_max_height(p_node->p_left, p_node->p_right) + 1;

	return p_node;
}

AVL_NODE* avl_insert(AVL_ROOT *p_root, int key)
{
	if (p_root == NULL) return NULL;

	p_root->p_node = _avl_insert(p_root->p_node, key);

	return p_root->p_node;
}

AVL_NODE* _avl_delete(AVL_NODE *p_node, int key)
{
	AVL_NODE *p_tmp;

	if (p_node == NULL) return NULL;
	else if (key < p_node->key)
		p_node->p_left = _avl_delete(p_node->p_left, key);
	else if (key > p_node->key)
		p_node->p_right = _avl_delete(p_node->p_right, key);
	else if (p_node->p_left && p_node->p_right)
	{
		p_tmp = p_node->p_right;

		while (p_tmp->p_left)
			p_tmp = p_tmp->p_left;

		p_node->key = p_tmp->key;
		p_node->p_right = _avl_delete(p_node->p_right, p_tmp->key);
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

	if (p_node)
	{
		if (avl_compare_height(p_node->p_left, p_node->p_right) > 1)
			p_node = avl_rotate_with_left(p_node);
		else if (avl_compare_height(p_node->p_right, p_node->p_left) > 1)
			p_node = avl_rotate_with_left_right(p_node);

		if (p_node)
			p_node->height = avl_get_max_height(p_node->p_left, p_node->p_right) + 1;
	}

	return p_node;
}

AVL_NODE* avl_delete(AVL_ROOT *p_root, int key)
{
	if (p_root == NULL || p_root->p_node == NULL) return NULL;

	p_root->p_node = _avl_delete(p_root->p_node, key);

	return p_root->p_node;
}

void avl_preorder(AVL_NODE *p_node)
{
	if (p_node == NULL) return;

	printf("[%p] - Key[%d], Height[%d], Left[%p], Right[%p]\n",
		   	p_node, p_node->key, p_node->height, p_node->p_left, p_node->p_right);

	if (p_node->p_left) avl_preorder(p_node->p_left);
	if (p_node->p_right) avl_preorder(p_node->p_right);
}

AVL_NODE* avl_search(AVL_NODE *p_node, int key)
{
	if (p_node == NULL)
		return NULL;
	else if (p_node->key > key)
		return avl_search(p_node->p_left, key);
	else if (p_node->key < key)
		return avl_search(p_node->p_right, key);
	else
		return p_node;
}

/* end of file */

