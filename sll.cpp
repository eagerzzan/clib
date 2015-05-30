#include <iostream>

using namespace std;

template <typename T>
struct SNODE
{
	T data;
	SNODE *p_next;
};

template <typename T>
class SList
{
private :
	SNODE<T> *p_head;

public :
#if 0
	SList() : p_head(NULL) {}

	~SList()
	{
		SNODE<T> *p_tmp = p_head;
		SNODE<T> *p_cur;

		while (p_tmp)
		{	
			p_cur = p_tmp;
			p_tmp = p_cur->p_next;

			delete p_cur;
		}
	}
#else
	SList();
	~SList();
#endif

	SNODE<T>* sorted_insert_node(T k)
	{
		SNODE<T> *p_new = new SNODE<T>;
		SNODE<T> *p_cur;

		if (p_new == NULL)
			return NULL;

		p_new->data = k;

		if (p_head == NULL || p_head->data > p_new->data)
		{
			p_new->p_next = p_head;
			p_head = p_new;
		}
		else
		{
			p_cur = p_head;

			while (p_cur->p_next && p_cur->p_next->data < p_new->data)
				p_cur = p_cur->p_next;

			p_new->p_next = p_cur->p_next;
			p_cur->p_next = p_new;
		}

		return p_new;
	}
#if 1
	SNODE<T>* insert_node(T k);

	SNODE<T>* insert_after(SNODE<T>* p_prev, T k);
#else
	SNODE<T>* insert_node(T k)
	{
		SNODE<T> *p_new = new SNODE<T>;
		SNODE<T> *p_cur;

		if (p_new == NULL)
			return NULL;

		p_new->data = k;

		if (p_head == NULL)
		{
			p_new->p_next = NULL;

			p_head = p_new;
		}
		else
		{
			p_cur = p_head;

			while (p_cur->p_next)
				p_cur = p_cur->p_next;

			p_new->p_next = p_cur->p_next;
			p_cur->p_next = p_new;
		}

		return p_new;
	}
#endif

#if 0
	void delete_node(T k)
	{
		SNODE<T> *p_del, *p_prev;

		p_del = p_head;

		if (p_del && p_del->data == k)
		{
			p_head = p_del->p_next;

			delete p_del;

			return;
		}

		while (p_del && p_del->data != k)
		{
			p_prev = p_del;
			p_del = p_del->p_next;
		}

		if (p_del == NULL)
			return;

		p_prev->p_next = p_del->p_next;

		delete p_del;
	}
#else
	void delete_node(T k)
	{
		SNODE<T> *p_del, *p_prev;

		p_del = p_head;

		while (p_del && p_del->data != k)
		{
			p_prev = p_del;
			p_del = p_del->p_next;
		}

		if (p_del == NULL)
			return;

		if (p_del == p_head)
			p_head = p_del->p_next;
		else
			p_prev->p_next = p_del->p_next;

		delete p_del;
	}
#endif

	SNODE<T>* find_node(T k)
	{
		SNODE<T> *p_tmp;

		p_tmp = p_head;

		while (p_tmp)
		{
			if (k == p_tmp->data)
				break;
			else
				p_tmp = p_tmp->p_next;
		}

		return p_tmp;
	}

	void print_node(void)
	{
		SNODE<T> *p_tmp;

		p_tmp = p_head;

		while (p_tmp)
		{
			cout << p_tmp->data << " ";
			p_tmp = p_tmp->p_next;
		}
		cout << endl;
	}
};

template <typename T>
SList<T>::SList() : p_head(NULL) {}

template <typename T>
SList<T>::~SList()
{
	SNODE<T> *p_tmp = p_head;
	SNODE<T> *p_cur;

	while (p_tmp)
	{
		p_cur = p_tmp;
		p_tmp = p_cur->p_next;

		delete p_cur;
	}
}

template <typename T>
SNODE<T>* SList<T>::insert_node(T k)
{
	SNODE<T> *p_new = new SNODE<T>;
	SNODE<T> *p_cur;

	if (p_new == NULL)
		return NULL;

	p_new->data = k;

	if (p_head == NULL)
	{
		p_new->p_next = NULL;

		p_head = p_new;
	}
	else
	{
		p_cur = p_head;

		while (p_cur->p_next)
			p_cur = p_cur->p_next;

		p_new->p_next = p_cur->p_next;
		p_cur->p_next = p_new;
	}

	return p_new;
}

template <typename T>
SNODE<T>* SList<T>::insert_after(SNODE<T>* p_prev, T k)
{
	SNODE<T> *p_new;

	if (p_prev == NULL)
		return NULL;

	p_new = new SNODE<T>;
	if (p_new == NULL)
		return NULL;

	p_new->data = k;
	p_new->p_next = p_prev->p_next;
	p_prev->p_next = p_new;

	return p_new;
}

int main()
{
	SList<int> sl;
	SNODE<int> *p_node;

	sl.insert_node(5);
	sl.insert_node(14);

	p_node = sl.find_node(5);
	sl.insert_after(p_node, 20);
	sl.insert_after(p_node, 8);
	sl.insert_after(p_node, 7);

	sl.delete_node(8);
	sl.delete_node(5);

	sl.print_node();

	return 0;
}
