#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>

#include "sort.h"
#include "sllist.h"
#include "search.h"
#include "bst.h"
#include "avl.h"

void create_tests(ELEMENT_TYPE **ppa, int num, int mode)
{
	int i;

	*ppa = (ELEMENT_TYPE *) malloc(sizeof(ELEMENT_TYPE) * num);

	switch (mode)
	{
		case 0 :
			for (i = 0; i < num; i++)
				(*ppa)[i] = rand() % num;
			break;

		case 1 :
			for (i = 0; i < num; i++)
				(*ppa)[i] = i;	
			break;

		case 2 :
			for (i = 0; i < num; i++)
				(*ppa)[i] = num - i - 1;
			break;

		default :
			break;
	}
}

void sort_test_all(ELEMENT_TYPE *pa, int num, int digits)
{
	struct timeval tv1, tv2;
	ELEMENT_TYPE *p_tmp;
	int i;

	p_tmp = (ELEMENT_TYPE *) malloc(sizeof(ELEMENT_TYPE) * num);

	for (i = 0; i < 11; i++)
	{
		memcpy(p_tmp, pa, sizeof(ELEMENT_TYPE) * num);

		gettimeofday(&tv1, NULL);

		switch (i)
		{
			case 0 : quicksort(p_tmp, 0, num - 1); break;
			case 1 : insertionsort(p_tmp, num); break;
			case 2 : selectionsort(p_tmp, num); break;
			case 3 : exchangesort(p_tmp, num); break;
			case 4 : bubblesort(p_tmp, num); break;
			case 5 : heap_sort(p_tmp, num); break;
			case 6 : shellsort(p_tmp, num); break;
			case 7 : merge_sort(p_tmp, 0, num - 1); break;
			case 8 : radix_sort(p_tmp, num, digits); break;
			case 9 : counting_sort(p_tmp, num, pow(10, digits)); break;
			case 10 : bucket_sort(p_tmp, num, pow(10, digits)); break;
			default : break;
		}

		gettimeofday(&tv2, NULL);

		printf("sort[%d] : %ld usec\n", i,
				(tv2.tv_sec * 1000000 + tv2.tv_usec)
				- (tv1.tv_sec * 1000000 + tv1.tv_usec));
	}

	if (p_tmp) free(p_tmp);
}

void test_bst(void)
{
	BT_ROOT *p_root;

	p_root = bst_create();

	bst_insert(p_root, 10);

	bst_insert(p_root, 12);

	bst_insert(p_root, 5);

	bst_insert(p_root, 4);

	bst_insert(p_root, 9);

	bst_insert(p_root, 6);

	bst_insert(p_root, 7);

	bst_preorder(p_root->p_node);

	printf("before delete\n");
	bst_delete(p_root, 4);

	printf("after delete\n");
	bst_preorder(p_root->p_node);

	bst_insert(p_root, 4);
	bst_insert(p_root, 3);
	printf("search : %p\n", bst_search(p_root->p_node, 9));
	bst_preorder(p_root->p_node);

	bst_destroy(&p_root);
}

void test_avl(void)
{
	AVL_ROOT *p_root;
	int i;

	p_root = avl_create();

#if 1
#if 1
	i = 30;
	avl_insert(p_root, i);
	printf("insert %d\n", i);
	avl_preorder(p_root->p_node);

	i = 40;
	avl_insert(p_root, i);
	printf("insert %d\n", i);
	avl_preorder(p_root->p_node);

	i = 34;
	avl_insert(p_root, i);
	printf("insert %d\n", i);
	avl_preorder(p_root->p_node);

	i = 36;
	avl_insert(p_root, i);
	printf("insert %d\n", i);
	avl_preorder(p_root->p_node);

	i = 30;
	avl_delete(p_root, i);
	printf("delete %d\n", i);
	avl_preorder(p_root->p_node);
#else
	for (i = 20; i > 0; i--)
	{
		avl_insert(p_root, i);
		printf("insert %d\n", i);
		avl_preorder(p_root->p_node);
	}
#endif
#else
	avl_insert(p_root, 10);
	printf("insert 10\n");
	avl_preorder(p_root->p_node);

	avl_insert(p_root, 4);
	printf("insert 4\n");
	avl_preorder(p_root->p_node);

	avl_insert(p_root, 12);
	printf("insert 12\n");
	avl_preorder(p_root->p_node);

	avl_insert(p_root, 3);
	printf("insert 3\n");
	avl_preorder(p_root->p_node);

	avl_insert(p_root, 6);
	printf("insert 6\n");
	avl_preorder(p_root->p_node);

	avl_insert(p_root, 13);
	printf("insert 13\n");
	avl_preorder(p_root->p_node);

	avl_insert(p_root, 11);
	printf("insert 11\n");
	avl_preorder(p_root->p_node);

	avl_insert(p_root, 5);
	printf("insert 5\n");
	avl_preorder(p_root->p_node);

	avl_insert(p_root, 7);
	printf("insert 7\n");
	avl_preorder(p_root->p_node);

	avl_insert(p_root, 9);
	printf("insert 9\n");
	avl_preorder(p_root->p_node);

	avl_delete(p_root, 4);
	printf("after delete  4\n");
	avl_preorder(p_root->p_node);

	avl_delete(p_root, 6);
	printf("after delete 6\n");
	avl_preorder(p_root->p_node);

	avl_delete(p_root, 3);
	printf("delete 3\n");
	avl_preorder(p_root->p_node);

	avl_delete(p_root, 5);
	printf("delete 5\n");
	avl_preorder(p_root->p_node);

	avl_delete(p_root, 9);
	printf("delete 9\n");
	avl_preorder(p_root->p_node);

	avl_delete(p_root, 7);
	printf("delete 7\n");
	avl_preorder(p_root->p_node);

	printf("search : %p\n", avl_search(p_root->p_node, 9));
	avl_preorder(p_root->p_node);
#endif

	avl_destroy(&p_root);
}

int main(int argc, char **argv)
{
	struct timeval tv1, tv2;

	//ELEMENT_TYPE a[] = {3, 0, 5, 2, 7, 6};
	//ELEMENT_TYPE a[] = {27, 106, 35, 92, 6, 10};
	ELEMENT_TYPE *pa = NULL;
	int length = 1000000;
	int mode, sort, search, tmp, digits;
	int i, j;

//	test_bst();
//	printf("##############################\n");
	test_avl();

	mode = 0;

	while (1)
	{
		printf("Enter length : ");
		scanf("%d", &length);

		if (length <= 0) continue;

		printf("Enter mode(0:rand, 1:seq, 2:reverse) : ");
		scanf("%d", &mode);

		if (mode < 0 || mode > 2) continue;

		printf("Enter a kind of sort(0:quick sort, 1:insertion sort, "
				"2:selection sort, 3:exchange sort, 4:bubble sort, 5:heap sort, 6:shell sort, "
				"7:merge sort, 8:radix sort, 9:counting sort, 10:bucket sort) "
				": ");
		scanf("%d", &sort);

		if (sort > 11) continue;

		digits = 0;
		tmp = length;
		while (tmp)
		{
			tmp /= 10;
			digits++;
		}	

		create_tests(&pa, length, mode); /* 0 : rand, 1 : seq, 2 : reverse */

		AVL_ROOT *p_root;

		p_root = avl_create();

		for (i = 0; i < length; i++)
			avl_insert(p_root, pa[i]);

		avl_preorder(p_root->p_node);
		printf("#########################\n");

		for (i = 0; i < length; i++)
			avl_delete(p_root, pa[i]);

		printf("#########################\n");
		avl_preorder(p_root->p_node);

		avl_destroy(&p_root);

		gettimeofday(&tv1, NULL);

		switch (sort)
		{
			case 0 : quicksort(pa, 0, length - 1); break;
			case 1 : insertionsort(pa, length); break;
			case 2 : selectionsort(pa, length); break;
			case 3 : exchangesort(pa, length); break;
			case 4 : bubblesort(pa, length); break;
			case 5 : heap_sort(pa, length); break;
			case 6 : shellsort(pa, length); break;
			case 7 : merge_sort(pa, 0, length - 1); break;
			case 8 : radix_sort(pa, length, digits); break;
			case 9 : counting_sort(pa, length, pow(10, digits)); break;
			case 10 : bucket_sort(pa, length, pow(10, digits)); break;
			case 11 : sort_test_all(pa, length, digits); break;
			default : break;
		}

		gettimeofday(&tv2, NULL);

		if (sort < 11)
		{
			#if 1
			for (i = 0; i < length; ++i)
			{
				printf("%d ", pa[i]);
				if (i && (i % 10 == 0))
					printf("\n");
			}
			printf("\n");
			#endif

			printf("Elapsed time : %ld\n",
					(tv2.tv_sec * 1000000 + tv2.tv_usec)
					- (tv1.tv_sec * 1000000 + tv1.tv_usec));
		}

		printf("Enter number to find: ");
		scanf("%d", &tmp);

		printf("Enter a kind of search(0:sequential search, 1:fibonacci search, "
				"2:binary search, 3:binary tree search, 4:balanced tree search, "
				"5:radix search) "
				": ");
		scanf("%d", &search);

		j = -1;
		switch (search)
		{
			case 0 :
				j = sequential_search(pa, length, tmp, is_same);
				break;
			case 1 :
				j = fibonacci_search(pa, length, tmp, is_same);
				break;
			case 2 :
				j = binary_search(pa, length, tmp, is_same);
				break;
			case 3 :
				j = binary_tree_search(pa, length, tmp);
			default :
				break;
		}

		printf("Search result : %d\n", j);

		if(pa) free(pa);
	}

	return 0;
}


