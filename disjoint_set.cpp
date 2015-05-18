#include <iostream>
#include <vector>

using namespace std;

typedef struct node
{
	int parent;
	int depth;
} NODE;

class DisjointSet
{
public :
	const int max;
	vector<NODE> u;

	DisjointSet(int max_n);
	int find_parent(int i);
	void merge(int i, int j);
	bool is_equal(int i, int j);
};

DisjointSet::DisjointSet(int max_n) : max(max_n)
{
	u.resize(max_n);

	for (int i = 0; i < max_n; i++)
	{
		u[i].parent = i;
		u[i].depth = 0;
	}
}

int DisjointSet::find_parent(int i)
{
	int j;

	j = i;
	while (u[j].parent != j)
		j = u[j].parent;

	return j;
}

void DisjointSet::merge(int i, int j)
{
	i = find_parent(i);
	j = find_parent(j);

	if (i == j) return;

	if (u[i].depth == u[j].depth)
	{
		u[i].depth++;
		u[j].parent = i;
	}
	else if (u[i].depth < u[j].depth)
		u[i].parent = j;
	else
		u[j].parent = i;
}

bool DisjointSet::is_equal(int i, int j)
{
	if (find_parent(i) == find_parent(j)) return true;
	else return false;
}

int main()
{
	DisjointSet s(10);

	s.merge(3, 5);
	s.merge(1, 7);

	cout << "7 belongs to " << s.find_parent(7) << endl;
	cout << "5 belongs to " << s.find_parent(5) << endl;

	cout << "5 and 7 is" << (s.is_equal(5, 7) ? " not" : "") << " disjoint set" << endl;
	cout << "1 and 7 is" << (s.is_equal(1, 7) ? " not" : "") << " disjoint set" << endl;

	s.merge(3, 1);

	cout << "5 and 7 is" << (s.is_equal(5, 7) ? " not" : "") << " disjoint set" << endl;

	return 0;
}
