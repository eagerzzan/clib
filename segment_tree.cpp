#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct SegmentTree
{
	vector<int> info;

	SegmentTree(const vector<int> a)
	{
		info.resize(2 * a.size() - 1);
		construct_segment_tree(0, 0, a.size() - 1, a);
	}

	int construct_segment_tree(int pos, int s, int e, vector<int> a)
	{
		if (s == e)
			return info[pos] = a[s];
		else
		{
			info[pos] = min(construct_segment_tree(2 * pos + 1, s, (s + e) / 2, a),
					construct_segment_tree(2 * pos + 2, (s + e) / 2 + 1, e, a));

			return info[pos];
		}
	}

	int range_minimum_query(int pos, int ss, int se, int qs, int qe)
	{
		if (ss > qe || se < qs)
			return INT_MAX;

		if (qs <= ss && qe >= se)
			return info[pos];
		else
		{
			return min(range_minimum_query(2 * pos + 1, ss, (ss + se) / 2, qs, qe),
					range_minimum_query(2 * pos + 2, (ss + se) / 2 + 1, se, qs, qe));
		}
	}

	void update_value(int i, int new_val, vector<int> &a)
	{
		int pos;

		if (i < 0 || i > a.size() - 1)
			return;

		a[i] = new_val;

		pos = i + a.size() - 1;
		info[pos] = a[i];

		while (pos > 0)
		{
			pos = (pos - 1) / 2;
			info[pos] = min(info[pos * 2 + 1], info[pos * 2 + 2]);
		}
	}
};

int main()
{
	int a[] = {10, 20, 15, 7, 3, 2, 8, 30};
	vector<int> arr(a, a + sizeof(a) / sizeof(int));
	SegmentTree st(arr);

	for (int i = 0; i < st.info.size(); i++)
		cout << st.info[i] << " ";
	cout << endl;

	cout << "RMQ : " << st.range_minimum_query(0, 0, arr.size() - 1, 0, 5) << endl;

	st.update_value(0, 1, arr);
	for (int i = 0; i < st.info.size(); i++)
		cout << st.info[i] << " ";
	cout << endl;

	cout << "RMQ : " << st.range_minimum_query(0, 0, arr.size() - 1, 0, 5) << endl;

	return 0;
}
