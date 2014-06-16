/*******************************************************************************
 * bst.c
 * binary search tree 
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#include "bst.h"

BST_ROOT* bst_create(void)
{
	BST_ROOT *p_root = NULL;

	p_root = (BST_ROOT *) malloc(sizeof(BST_ROOT));
	if (p_root)
	{
		p_root->p_node = NULL;
		p_root->count = 0;
	}

	return p_root;
}

void _bst_destroy_recursively(BST_NODE *p_node)
{
	if (p_node == NULL) return;

	_bst_destroy_recursively(p_node->p_left);
	_bst_destroy_recursively(p_node->p_right);

	free(p_node);
}

void bst_destroy(BST_ROOT **pp_root)
{
	if (pp_root == NULL || *pp_root == NULL) return;

	if ((*pp_root)->p_node)
		_bst_destroy_recursively((*pp_root)->p_node);

	free(*pp_root);
	*pp_root = NULL;
}


/* end of file */

