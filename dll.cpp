#include <iostream>

using namespace std;

template <typename T>
struct DNODE
{
	T data;
	DNODE *p_prev;
	DNODE *p_next;
};

template <typename T>
class DList
{
private :
	DNODE<T> *p_head;
	DNODE<T> *p_tail;

public :
	DList() : p_head(NULL), p_tail(NULL) {}

	~DList()
	{
		DNODE<T> *p_tmp = p_head;
		DNODE<T> *p_cur;

		while (p_tmp)
		{
			p_cur = p_tmp;
			p_tmp = p_cur->p_next;

			delete p_cur;
		}
	}

	DNODE<T>* sorted_insert_node(T k)
	{
		DNODE<T> *p_new = new DNODE<T>;
		DNODE<T> *p_cur;

		if (p_new == NULL)
			return NULL;

		p_new->data = k;
		p_new->p_prev = p_new->p_next = NULL;

		if (p_head == NULL || p_head->data > p_new->data)
		{
			p_new->p_next = p_head;

			if (p_head)
				p_head->p_prev = p_new;

			p_head = p_new;
		}
		else
		{
			p_cur = p_head;

			while (p_cur->p_next && p_cur->p_next->data < p_new->data)
				p_cur = p_cur->p_next;

			p_new->p_next = p_cur->p_next;
			p_new->p_prev = p_cur;

			if (p_cur->p_next)
				p_cur->p_next->p_prev = p_new;

			p_cur->p_next = p_new;
		}

		if (p_new->p_next == NULL)
			p_tail = p_new;

		return p_new;
	}

	DNODE<T>* insert_after(DNODE<T> *p_prev, T k);

	DNODE<T>* insert_node(T k)
	{
		DNODE<T> *p_new = new DNODE<T>;
		DNODE<T> *p_cur;

		if (p_new == NULL)
			return NULL;

		p_new->data = k;

		if (p_head == NULL)
		{
			p_new->p_next = NULL;
			p_new->p_prev = NULL;

			p_head = p_new;
		}
		else
		{
			p_cur = p_tail;

			p_cur->p_next = p_new;

			p_new->p_prev = p_cur;
			p_new->p_next = NULL;
		}

		p_tail = p_new;

		return p_new;
	}

#if 0
	void delete_node(T k)
	{
		DNODE<T> *p_del, *p_prev;

		p_del = p_head;

		if (p_del && p_del->data == k)
		{
			if (p_del->p_next)
				p_del->p_next->p_prev = NULL;

			if (p_del == p_tail)
				p_tail = p_del->p_next;

			p_head = p_del->p_next;

			delete p_del;

			return;
		}

		while (p_del && p_del->data != k)
			p_del = p_del->p_next;

		if (p_del == NULL)
			return;

		p_del->p_prev->p_next = p_del->p_next;

		if (p_del->p_next)
			p_del->p_next->p_prev = p_del->p_prev;

		if (p_del == p_tail)
			p_tail = p_del->p_prev;

		delete p_del;
	}
#else
	void delete_node(T k)
	{
		DNODE<T> *p_del;

		p_del = find_node(k);
		if (p_del == NULL)
			return;

		if (p_del->p_prev)
			p_del->p_prev->p_next = p_del->p_next;
		if (p_del->p_next)
			p_del->p_next->p_prev = p_del->p_prev;

		if (p_del == p_head)
			p_head = p_del->p_next;

		if (p_del == p_tail)
			p_tail = p_del->p_prev;

		delete p_del;
	}
#endif

	DNODE<T>* find_node(T k)
	{
		DNODE<T> *p_tmp;

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
		DNODE<T> *p_tmp;

		p_tmp = p_head;

		while (p_tmp)
		{
			cout << p_tmp->data << " ";
			p_tmp = p_tmp->p_next;
		}
		cout << endl;
	}

	void reverse_print_node(void)
	{
		DNODE<T> *p_tmp;

		p_tmp = p_tail;

		while (p_tmp)
		{
			cout << p_tmp->data << " ";
			p_tmp = p_tmp->p_prev;
		}
		cout << endl;
	}
};

template <typename T>
DNODE<T>* DList<T>::insert_after(DNODE<T> *p_prev, T k)
{
	DNODE<T> *p_new;

	if (p_prev == NULL)
		return NULL;

	p_new = new DNODE<T>;
	if (p_new == NULL)
		return NULL;

	p_new->data = k;

	p_new->p_next = p_prev->p_next;
	p_new->p_prev = p_prev;

	if (p_prev->p_next)
		p_prev->p_next->p_prev = p_new;
	else
		p_tail = p_new;

	p_prev->p_next = p_new;

	return p_new;
}

int main()
{
	DList<int> dl;
	DNODE<int> *p_node;

	dl.insert_node(5);
	dl.insert_node(14);
	dl.insert_node(8);

	p_node = dl.find_node(14);
	dl.insert_after(p_node, 20);
	dl.insert_after(p_node, 7);

	dl.delete_node(8);
	dl.delete_node(5);
	dl.delete_node(14);

	dl.print_node();
	cout <<"-------------" << endl;
	dl.reverse_print_node();

	return 0;
}
