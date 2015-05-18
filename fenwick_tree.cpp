#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void update(vector<int> &bit, vector<int> a, int i, int delta)
{
	for (int j = i; j < bit.size(); j |= j + 1)
		bit[j] += delta;
}

void construct(vector<int> &bit, vector<int> a)
{
	bit.clear();
	bit.resize(a.size());

	for (int i = 0; i < bit.size(); i++)
#if 0
		for (int j = i; j < bit.size(); j |= j + 1)
			bit[j] += a[i];
#else
		update(bit, a, i, a[i]);
#endif
}

int sum(vector<int> bit, int i)
{
	int _sum = 0;

	if (bit.size() <= i)
		return 0;

	while (i >= 0)
	{
		_sum += bit[i];
		i &= i + 1;
		i--;
	}

	return _sum;
}

int range_sum(vector<int> bit, int as, int ae)
{
	return sum(bit, ae) - sum(bit, as - 1);
}

int main()
{
	int a[] = {2, 10, 4, 5, 20, 1, 3, 8};
	vector<int> bit;
	vector<int> arr(a, a + sizeof(a) / sizeof(int));

	construct(bit, arr);

	for (int i = 0; i < bit.size(); i++)
		cout << bit[i] << " ";
	cout << endl;

	cout << "Sum : " << range_sum(bit, 0, 3) << endl;

	update(bit, arr, 0, 10);
	for (int i = 0; i < bit.size(); i++)
		cout << bit[i] << " ";
	cout << endl;
	cout << "Sum : " << range_sum(bit, 1, 3) << endl;

	return 0;
}
