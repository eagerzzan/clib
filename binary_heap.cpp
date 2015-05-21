#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void max_heapify(vector<int> &h, int i)
{
	int largest = i;
	int left = (i << 1) + 1; // 2 * i + 1
	int right = (i + 1) << 1; // 2 * i + 2 = 2 * (i + 1)

	if (left < h.size() && h[left] > h[largest])
		largest = left;

	if (right < h.size() && h[right] > h[largest])
		largest = right;

	if (largest != i)
	{
		swap(h[largest], h[i]);
		max_heapify(h, largest);
	}
}

void insert_key(vector<int> &h, int k)
{
	int i;

	h.push_back(k);
	i = h.size() - 1;

	while (i != 0 && h[(i - 1) / 2] < h[i])
	{
		swap(h[i], h[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

int extract_max(vector<int> &h)
{
	int ret = INT_MIN;

	if (h.size() < 1)
		return ret;

	ret = h.front();

	h[0] = h.back();
	h.pop_back();

	max_heapify(h, 0);

	return ret;
}

void build_heap(vector<int> &h)
{
	int length = h.size() / 2;
	int i;

	for (i = length; i > -1; i--)
		max_heapify(h, i);
}

void print_heap(vector<int> h)
{
	cout << "-----------------------------" << endl;
	for (int i = 0; i < h.size(); i++)
		cout << h[i] << " ";
	cout << endl;
	cout << "-----------------------------" << endl;
}

int main()
{
	int a[] = {1, 3, 4, 8, 5, 9, 6, 7};

	vector<int> heap(a, a + sizeof(a) / sizeof(int));

	build_heap(heap);
	print_heap(heap);

	cout << "root : " << extract_max(heap) << endl;
	print_heap(heap);

	insert_key(heap, 15);
	print_heap(heap);

	int r;

	while ((r = extract_max(heap)) != INT_MIN)
	{
		cout << "root : " << r << endl;
		print_heap(heap);
	}

	return 0;
}

