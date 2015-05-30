/*******************************************************************************
 * sort.c
 * source of sort 
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"
#include "bheap.h"
#include "sllist.h"

static void swap(int *p_a, int *p_b)
{
	int tmp = *p_a;
	*p_a = *p_b;
	*p_b = tmp;
}

static int partition(ELEMENT_TYPE a[], int low, int high)
{
	ELEMENT_TYPE pivot_item;
	ELEMENT_TYPE tmp;
	int i, j;

	//if (a == NULL || pivot == NULL) return;

	pivot_item = a[low];
	j = low;

	for (i = low + 1; i <= high; i++)
	{
		if (a[i] < pivot_item)
		{
			j++;
			tmp = a[i]; a[i] = a[j]; a[j] = tmp;
		}
	}

	// tmp = a[low]; a[low] = a[*pivot]; a[*pivot] = tmp;
	swap(&a[low], &a[j]);

	return j;
}

void quicksort(ELEMENT_TYPE a[], int low, int high)
{
	int pivot;

	if (high > low)
	{
		int pivot = partition(a, low, high);

		quicksort(a, low, pivot - 1);
		quicksort(a, pivot + 1, high);
	}
}

void selectionsort(ELEMENT_TYPE a[], int n)
{
	int i, j;
	int smallest;

	ELEMENT_TYPE tmp;

	for (i = 0; i < n; i++)
	{
		smallest = i;

		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[smallest])
				smallest = j;
		}

		tmp = a[i]; a[i] = a[smallest]; a[smallest] = tmp;
	}
}

void exchangesort(ELEMENT_TYPE a[], int n)
{
	ELEMENT_TYPE tmp;
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				tmp = a[i]; a[i] = a[j]; a[j] = tmp;
			}
		}
	}
}

void bubblesort(ELEMENT_TYPE a[], int n)
{
	int i, j;
	ELEMENT_TYPE tmp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j + 1] < a[j])
			{
				tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp;
			}
		}
	}
}

void heap_sort(ELEMENT_TYPE a[], int n)
{
	ARRAY_HEAP *p_h = NULL;
	HEAP_NODE tmp;
	int i;

	p_h = bheap_create(n);

	for (i = 0; i < n; i++)
	{
		tmp.key = a[i];
		tmp.data = a[i];
		p_h->p_elements[i + 1] = tmp;
		p_h->last++;
		//bheap_push(p_h, tmp);
	}

	bheap_make_heap(p_h);

	for (i = n - 1; i >= 0; i--)
	{
		bheap_pop(p_h, &tmp);
		a[i] = tmp.key;
	}

	bheap_destroy(&p_h);
}

void insertionsort(ELEMENT_TYPE a[], int n)
{
	int i, j;
	ELEMENT_TYPE tmp;

	for (i = 1; i < n; i++)
	{
		tmp = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > tmp)
		{
			a[j + 1] = a[j];
			j--;
		}

		a[j + 1] = tmp;
	}
}

void shellsort(ELEMENT_TYPE a[], int n)
{
	/* Marcin Ciura's gap sequence */
	int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};

	int i, j, k;
	int inc;
	ELEMENT_TYPE tmp;

	for (i = 0; i < sizeof(gaps) / sizeof(gaps[0]); i++)
	{
		for (j = gaps[i]; j < n; j++)
		{
			tmp = a[j];

			for (k = j; k >= gaps[i] && a[k - gaps[i]] > tmp; k -= gaps[i])
				a[k] = a[k - gaps[i]];

			a[k] = tmp;
		}
	}
}

void merge(ELEMENT_TYPE a[], int low, int mid, int high)
{
	int i, j, k;
	ELEMENT_TYPE *p_tmp = NULL;

	if (low > high) return;

	p_tmp = (ELEMENT_TYPE *) malloc(sizeof(ELEMENT_TYPE) * (high - low + 1));
	if (p_tmp == NULL) return;

	i = low; j = mid + 1; k = 0;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
			p_tmp[k++] = a[i++];
		else
			p_tmp[k++] = a[j++];
	}

	if (i > mid)
		memcpy(p_tmp + k, a + j, sizeof(ELEMENT_TYPE) * (high - j + 1));
	else
		memcpy(p_tmp + k, a + i, sizeof(ELEMENT_TYPE) * (mid - i + 1));

	memcpy(a + low, p_tmp, sizeof(ELEMENT_TYPE) * (high - low + 1));

	if (p_tmp) free(p_tmp);
}

void merge_sort(ELEMENT_TYPE a[], int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;

		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);

		merge(a, low, mid, high);
	}
}

void radix_sort(ELEMENT_TYPE a[], int n, int ndigits)
{
	SLL_LIST *piles[10];
	SLL_NODE *p_tmp;
	int i, j, k;
	ELEMENT_TYPE d;

	int r;

	r = 1;

	for (i = 1; i <= ndigits; i++)
	{
		for (j = 0; j < 10; j++)
			piles[j] = sll_create();	

		for (j = 0; j < n; j++)
		{
			d = (a[j] / r) % 10;
			p_tmp = sll_make_node(a[j]);
			sll_insert_back(piles[d], p_tmp);
		}

		for (j = 0, k = 0; k < n; j++)
		{
			p_tmp = piles[j]->p_head;

			while (p_tmp)
			{
				a[k++] = p_tmp->data;
				p_tmp = p_tmp->p_next;
			}
		}

		r *= 10;

		for (j = 0; j < 10; j++)
			sll_destroy(&piles[j]);
	}
}

#if 1
void counting_sort(ELEMENT_TYPE a[], int n, int maxk)
{
	ELEMENT_TYPE b[n];
	int counts[maxk + 1];

	int i;

	memset(counts, 0, sizeof(counts));

	for (i = 0; i < n; i++)
		counts[a[i]]++;

	for (i = 1; i <= maxk; i++)
		counts[i] += counts[i - 1];

	for (i = 0; i < n; i++)
	{
		b[counts[a[i]] - 1] = a[i];
		counts[a[i]]--;
	}

	memcpy(a, b, sizeof(b));
}
#else
void counting_sort(ELEMENT_TYPE a[], int n, int maxk)
{
	int *counts;
	ELEMENT_TYPE *b;
	int tmp, total;
	int output[n];

	int i;

	counts = (int *) malloc(sizeof(int) * maxk);
	if (counts == NULL) return;

	memset(counts, 0, sizeof(int) * maxk);

	for (i = 0; i < n; i++)
		counts[a[i]]++;

	total = 0;
	for (i = 0; i < maxk; i++)
	{
		if (counts[i])
		{
			tmp = counts[i];
			counts[i] = total;
			total += tmp;
		}
	}

	b = (ELEMENT_TYPE *) malloc(sizeof(ELEMENT_TYPE) * n);
	if (b == NULL) return;

	memset(b, 0, sizeof(ELEMENT_TYPE) * n);

	for (i = 0; i < n; i++) 
	{
		b[counts[a[i]]] = a[i];
		counts[a[i]]++;
	}

	memcpy(a, b, sizeof(ELEMENT_TYPE) * n);

	if (b) free(b);
	if (counts) free(counts);
}
#endif

void bucket_sort(ELEMENT_TYPE a[], int n, int maxk)
{
	SLL_LIST *buckets[maxk];
	SLL_NODE *p_node;
	int i, j;

	for (i = 0; i < maxk; i++)
		buckets[i] = sll_create();

	for (i = 0; i < n; i++)
	{
		p_node = sll_make_node(a[i]);
		sll_insert_back(buckets[a[i]], p_node);
	}

	for (i = 0, j = 0; j < n; i++)
	{
		p_node = buckets[i]->p_head;

		while (p_node)
		{
			a[j++] = p_node->data;
			p_node = p_node->p_next;
		}
	}

	for (i = 0; i < maxk; i++)
		sll_destroy(&buckets[i]);
}

/* end of file */

