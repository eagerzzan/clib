#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class DArray
{
private :
	const int inc;
	T *array;
	int size;
	int used;

public :
	DArray() : inc(10)
	{
		size = inc;
		used = 0;

		array = new int[size];

		for (int i = 0; i < size; i++)
			array[i] = 0;
	}

	DArray(int init_size) : inc(10)
	{
		size = init_size;
		used = 0;

		array = new int[size];

		for (int i = 0; i < size; i++)
			array[i] = 0;
	}

	~DArray()
	{
		delete[] array;
	}

	void resize(int increment)
	{
		int *new_array;
		int old_size = size;

		size += increment;

		if (used > size)
			used = size;

		new_array = new int[size];

		for (int i = 0; i < size; i++)
		{
			if (i < old_size)
				new_array[i] = array[i];
		}

		delete[] array;

		array = new_array;
	}

	void insert_element(T value)
	{
		if (used == size)
			resize(inc);

		array[used] = value;
		used++;
	}

	void delete_element(int idx)
	{
		if (idx + 1 < used)
		{
			memmove(array + idx, array + idx + 1, (size - idx - 1) * sizeof(T));
			used--;
		}
		else if (idx + 1 == used)
		{
			array[idx] = 0;
			used--;
		}
	}

	T& operator[](int idx)
	{
		return array[idx];
	}

	int get_used_size(void)
	{
		return used;
	}
};

int main()
{
	DArray<int> darray(10);

	for (int i = 0; i < 10; i++)
		darray.insert_element(i);

	darray.insert_element(29);
	darray.insert_element(11);
	darray[0] = 30;
	darray.delete_element(9);
	darray.delete_element(3);
	darray[1] = 40;
	darray.resize(-5);

	for (int i = 0; i < darray.get_used_size(); i++)
		cout << "array[" << i << "] : " << darray[i] << endl;

	return 0;
}

