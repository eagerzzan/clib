#include <iostream>
#include <sys/time.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#if 0
static void swap(int *p_a, int *p_b)
{
	int tmp = *p_a;
	*p_a = *p_b;
	*p_b = tmp;
}
#endif

void insertion_sort(int a[], int n)
{
	int i, j;
	int tmp;

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

void selection_sort(int a[], int n)
{
	int i, j;
	int smallest;

	int tmp;

	for (i = 0; i < n; i++)
	{
		smallest = i;

		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[smallest])
				smallest = j;
		}

		//tmp = a[i]; a[i] = a[smallest]; a[smallest] = tmp;
		swap(a[i], a[smallest]);
	}
}

static int partition(int a[], int low, int high)
{
	int pivot_item;
	int tmp;
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
	swap(a[low], a[j]);

	return j;
}

void quick_sort(int a[], int low, int high)
{
	int pivot;

	if (high > low)
	{
		int pivot = partition(a, low, high);

		quick_sort(a, low, pivot - 1);
		quick_sort(a, pivot + 1, high);
	}
}

void bubble_sort(int a[], int n)
{
	int i, j;
	int tmp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j + 1] < a[j])
				swap(a[j], a[j + 1]);
		}
	}
}

void counting_sort(int a[], int n, int maxk)
{
	int b[n];
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

int sequential_search(int a[], int n, int key)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (a[i] == key)
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
int fibonacci_search(int a[], int n, int key)
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

		if (a[i] > key)
		{
			f = f2; f2 = f1; f1 = f - f2;
			//printf("c>0 : f=%d\n", f);
		}
		else if (a[i] < key)
		{
			j++;
			f = f1--;
			//printf("c<0 : f=%d\n", f);
		}
		else
			return i;
	}

	return -1;
}

int binary_search(int a[], int n, int key)
{
	int first, mid, last;
	int c;

	first = 0;
	last = n - 1;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (a[mid] == key)
			return mid;
		else if (a[mid] > key)
			last = mid - 1;
		else
			first = mid + 1;
	}

	return -1;
}


int interpolation_search(int a[], int n, int key)
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (!(a[high] == a[low] || key < a[low] || a[high] < key))
	{
		mid = low + (key - a[low]) * ((high - low) / (a[high] - a[low]));

		if (a[mid] < key)
			low = mid + 1;
		else if (key < a[mid])
			high = mid - 1;
		else
			return mid;
	}

	if (key == a[low])
		return low;
	else
		return -1;
}

#if 0
int binary_tree_search(
		int a[],
		int n,
		int key
		)
{
	BT_ROOT *p_root;
	int i;

	p_root = bst_create();

	for (i = 0; i < n; i++)
		bst_insert(p_root, a[i]);

	printf("search : %p\n", bst_search(p_root->p_node, key));

	bst_destroy(&p_root);

	return 0;
}
#endif

void create_tests(int **ppa, int num, int mode, int digits)
{
	int i;
	int max = pow(10, digits);

	*ppa = (int *) malloc(sizeof(int) * num);

	switch (mode)
	{
		case 0 :
			for (i = 0; i < num; i++)
				(*ppa)[i] = rand() % max;
			break;

		case 1 :
			for (i = 0; i < num; i++)
				(*ppa)[i] = i % max;	
			break;

		case 2 :
			for (i = 0; i < num; i++)
				(*ppa)[i] = (num - i - 1) % max;
			break;

		default :
			break;
	}
}

const char* get_sort_name(int i)
{
	const char *sort_name[] = {
		"quick sort",
		"insertion sort",
		"selection sort",
		"exchange sort",
		"bubble sort",
		"heap sort",
		"shell sort",
		"merge sort",
		"radix sort",
		"counting sort",
		"bucket sort"
	};

	return sort_name[i];
}

void sort_test_all(int *pa, int num, int digits)
{
	struct timeval tv1, tv2;
	int *p_tmp;
	int i;

	p_tmp = (int *) malloc(sizeof(int) * num);

	for (i = 0; i < 11; i++)
	{
		memcpy(p_tmp, pa, sizeof(int) * num);

		gettimeofday(&tv1, NULL);

		switch (i)
		{
			case 0 : quick_sort(p_tmp, 0, num - 1); break;
			case 1 : insertion_sort(p_tmp, num); break;
			case 2 : selection_sort(p_tmp, num); break;
			//case 3 : exchangesort(p_tmp, num); break;
			case 4 : bubble_sort(p_tmp, num); break;
			//case 5 : heap_sort(p_tmp, num); break;
			//case 6 : shellsort(p_tmp, num); break;
			//case 7 : merge_sort(p_tmp, 0, num - 1); break;
			//case 8 : radix_sort(p_tmp, num, digits); break;
			case 9 : counting_sort(p_tmp, num, pow(10, digits)); break;
			//case 10 : bucket_sort(p_tmp, num, pow(10, digits)); break;
			default : break;
		}

		gettimeofday(&tv2, NULL);

		printf("sort[%d:%s] : %ld usec\n", i, get_sort_name(i),
				(tv2.tv_sec * 1000000 + tv2.tv_usec)
				- (tv1.tv_sec * 1000000 + tv1.tv_usec));
	}

	if (p_tmp) free(p_tmp);
}

bool compare(int i, int j) { return (i < j); }

int main(int argc, char **argv)
{
	struct timeval tv1, tv2;

	//int a[] = {3, 0, 5, 2, 7, 6};
	int a[] = {27, 106, 35, 92, 6, 10};
	int *pa = NULL;
	int length = 1000000;
	int mode, sort, search, tmp, digits;
	int i, j;

//	test_bst();
//	printf("##############################\n");
	//test_avl();

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

#if 0
		digits = 0;
		tmp = length;
		while (tmp)
		{
			tmp /= 10;
			digits++;
		}
#else
		digits = 2;
#endif
		printf("Digits : %d\n", digits);

		insertion_sort(a, sizeof(a) / sizeof(int));
		for (i = 0; i < sizeof(a) / sizeof(int); ++i)
		{
			printf("%d ", a[i]);
			if (i && (i % 10 == 0))
				printf("\n");
		}
		printf("\n");

		vector<int> v(a, a + sizeof(a) / sizeof(int));

		std::sort(v.begin(), v.end());

		if (binary_search(v.begin(), v.end(), 6, compare))
			cout << "found\n";
		else
			cout << "not found\n";

		create_tests(&pa, length, mode, digits); /* 0 : rand, 1 : seq, 2 : reverse */

		gettimeofday(&tv1, NULL);

		switch (sort)
		{
			case 0 : quick_sort(pa, 0, length - 1); break;
			case 1 : insertion_sort(pa, length); break;
			case 2 : selection_sort(pa, length); break;
			//case 3 : exchangesort(pa, length); break;
			case 4 : bubble_sort(pa, length); break;
			//case 5 : heap_sort(pa, length); break;
			//case 6 : shellsort(pa, length); break;
			//case 7 : merge_sort(pa, 0, length - 1); break;
			//case 8 : radix_sort(pa, length, digits); break;
			case 9 : counting_sort(pa, length, pow(10, digits)); break;
			//case 10 : bucket_sort(pa, length, pow(10, digits)); break;
			case 11 : sort_test_all(pa, length, digits); break;
			default : break;
		}

		gettimeofday(&tv2, NULL);

		if (sort < 11)
		{
			#if 1 // print sorted list
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
				"5:radix search, 6:interpolation search) "
				": ");
		scanf("%d", &search);

#if 0
		gettimeofday(&tv1, NULL);

		j = -1;

		switch (search)
		{
			case 0 :
				j = sequential_search(pa, length, tmp);
				break;
			case 1 :
				j = fibonacci_search(pa, length, tmp);
				break;
			case 2 :
				j = binary_search(pa, length, tmp);
				break;
			case 3 :
				//j = binary_tree_search(pa, length, tmp);
				break;
			case 6 :
				j = interpolation_search(pa, length, tmp);
				break;
			default :
				break;
		}

		gettimeofday(&tv2, NULL);

		if (search < 7)
		{
			printf("Search result : %d\n", j);

			printf("Search Elapsed time : %ld\n",
					(tv2.tv_sec * 1000000 + tv2.tv_usec)
					- (tv1.tv_sec * 1000000 + tv1.tv_usec));
		}
#else
		j = -1;

		gettimeofday(&tv1, NULL);
		j = sequential_search(pa, length, tmp);
		gettimeofday(&tv2, NULL);

		printf("Sequential Search result : %d\n", j);
		printf("Sequential Search Elapsed time : %ld\n",
				(tv2.tv_sec * 1000000 + tv2.tv_usec)
				- (tv1.tv_sec * 1000000 + tv1.tv_usec));

		gettimeofday(&tv1, NULL);
		j = fibonacci_search(pa, length, tmp);
		gettimeofday(&tv2, NULL);
		printf("Fibonacci Search result : %d\n", j);
		printf("Fibonacci Search Elapsed time : %ld\n",
				(tv2.tv_sec * 1000000 + tv2.tv_usec)
				- (tv1.tv_sec * 1000000 + tv1.tv_usec));

		gettimeofday(&tv1, NULL);
		j = binary_search(pa, length, tmp);
		gettimeofday(&tv2, NULL);
		printf("Binary Search result : %d\n", j);
		printf("Binary Search Elapsed time : %ld\n",
				(tv2.tv_sec * 1000000 + tv2.tv_usec)
				- (tv1.tv_sec * 1000000 + tv1.tv_usec));

		gettimeofday(&tv1, NULL);
		j = interpolation_search(pa, length, tmp);
		gettimeofday(&tv2, NULL);
		printf("Interpolation Search result : %d\n", j);
		printf("Interpolation Search Elapsed time : %ld\n",
				(tv2.tv_sec * 1000000 + tv2.tv_usec)
				- (tv1.tv_sec * 1000000 + tv1.tv_usec));
#endif


		if(pa) free(pa);
	}

	return 0;
}

