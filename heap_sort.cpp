#include <iostream>

using namespace std;

void shift_down(int *a, int i, int max)
{
	int b, c1, c2;

	while (i < max)
	{
		b = i;
		c1 = (2 * i) + 1;
		c2 = c1 + 1;

		if (c1 < max && a[c1] > a[b])
			b = c1;

		if (c2 < max && a[c2] > a[b])
			b = c2;

		if (b == i) return;

		swap(a[i], a[b]);

		i = b;
	}
}

void to_heap(int *a, int n)
{
	int i = n / 2 - 1;

	while (i >= 0)
	{
		shift_down(a, i, n);
		i--;
	}
}

void heap_sort(int *a, int n)
{
	to_heap(a, n);
	int end = n - 1;

	while (end > 0)
	{
		swap(a[0], a[end]);
		shift_down(a, 0, end);
		end--;
	}
}

int main()
{
	int a[] = {
		12, 11, 15, 4, 98, 13, 2, 1, 3, 13};
	int n = sizeof(a) / sizeof(int);

	heap_sort(a, n);

	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
}
