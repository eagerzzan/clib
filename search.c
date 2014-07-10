/*******************************************************************************
 * search.c
 * source of search
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#include <stdio.h>
#include <limits.h>

#include "search.h"

int is_same(const ELEMENT_TYPE src, const ELEMENT_TYPE dst)
{
	int ret;

	ret = (int) (src - dst);

	return ret;
}

int sequential_search(
		ELEMENT_TYPE a[],
		int n,
		ELEMENT_TYPE key,
		int (*is_same)(const ELEMENT_TYPE, const ELEMENT_TYPE)
		)
{
	int i;

	if (a == NULL) return;

	for (i = 0; i < n; i++)
	{
		if ((*is_same)(a[i], key) == 0)
			return i;
	}

	return -1;
}

/**
 * F : Fibonacci numbers array
 * k : An element in F
 * n = F(m) : size of F
 * If F(m) is not a Fibonacci number,
 *		F(m) is the smallest number in F that is greater than n.
 * 
 * 1. Set k = m
 * 2. If k = 0, stop. There is no match; the item is not in the array.
 * 3. Compare the item against element in F(k-1).
 * 4. If the item matches, stop.
 * 5. If the item is less than entry F(k-1), discard the elements
 *		from positions F(k-1) + 1 to n.
 *	  Set k = k - 1 and return to step 2.
 * 6. If the item is greater than entry F(k-1), discard the elements
 * 		from positions 1 to F(k-1).
 * 	  Renumber the remaining elements from 1 to F(k-2).
 * 	  Set k = k - 2, and return to step 2.
 */
int fibonacci_search(
		ELEMENT_TYPE a[],
		int n,
		ELEMENT_TYPE key,
		int (*is_same)(const ELEMENT_TYPE, const ELEMENT_TYPE)
		)
{
	int f, f1, f2;

	int c;
	int i, j, k;

	f = 2, f1 = f2 = 1;
	while (f < n)
	{
		f1 = f2;
		f2 = f;
		f = f1 + f2;
	}

	j = 0;
	while (f > 1)
	{
		i = f2 + j - 1;

		c = is_same(a[i], key);
		if (c > 0)
		{
			f = f2; f2 = f1; f1 = f - f2;
			printf("c>0 : f=%d\n", f);
		}
		else if (c < 0)
		{
			j++;
			f = f1--;
			printf("c<0 : f=%d\n", f);
		}
		else
			return i;
	}

	return -1;
}

void binary_search()
{

}

void binary_tree_search()
{

}

void balanced_tree_search()
{

}

void bubble_search()
{

}

void radix_search()
{

}

/* end of file */

