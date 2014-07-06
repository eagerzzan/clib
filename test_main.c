#include "queue.h"
#include "deque.h"
#include "prioq.h"
#include "dynarray.h"
#include "sllist.h"
#include "dllist.h"
#include "stack.h"

#include <stdio.h>

void test_dll(void)
{
	DLL_LIST *p_list = NULL;
	DLL_NODE *p_tmp;
	ELEMENT_TYPE data;

	p_list = dll_create();
	data = 1;
	p_tmp = dll_make_node(data);
	dll_insert(p_list, p_tmp, p_tmp);

	data = 2;
	p_tmp = dll_make_node(data);
	dll_insert(p_list, p_list->p_head, p_tmp);
	data = 3;
	p_tmp = dll_make_node(data);
	dll_insert(p_list, p_list->p_head, p_tmp);
	data = 4;
	p_tmp = dll_make_node(data);
	dll_insert(p_list, p_list->p_head, p_tmp);
	data = 5;
	p_tmp = dll_make_node(data);
	dll_insert(p_list, p_list->p_head, p_tmp);

	dll_delete(p_list, p_list->p_head);

	dll_print_list(p_list);

	dll_destroy(&p_list);
}

void test_sll(void)
{
	SLL_LIST *p_list = NULL;
	SLL_NODE *p_tmp;
	ELEMENT_TYPE data;

	p_list = sll_create();

	data = 1;
	p_tmp = sll_make_node(data);
	sll_insert(p_list, p_tmp, p_tmp);

	data = 2;
	p_tmp = sll_make_node(data);
	sll_insert(p_list, p_list->p_head, p_tmp);

#if 0
	sll_delete(p_list, p_tmp);
	sll_print_list(p_list);
	sll_delete(p_list, p_list->p_head);
	sll_delete(p_list, p_list->p_head);
#endif

	sll_print_list(p_list);

	sll_destroy(&p_list);
}

void test_da(void)
{
	DYN_ARRAY *p_da;
	ELEMENT_TYPE a;

	p_da = da_create(3);

	a = 10;
	da_insert(p_da, 0, a);

	da_destroy(&p_da);
}

void test_deq(void)
{
	QUEUE *p_q;
	int i;

	p_q = deq_create(3);

	deq_push_back(p_q, 10);
	deq_push_back(p_q, 20);
	printf("DEQ empty : %d, full : %d\n", deq_is_empty(p_q), deq_is_full(p_q));
	
	deq_destroy(&p_q);
}

void test_prioq(void)
{
	ARRAY_HEAP *p_pq;
	HEAP_NODE e;

	p_pq = prioq_create(3);

	prioq_peek(p_pq, &e);
	printf("PQ peek : %d, %d\n", e.key, e.data);

	e.key = 10; e.data = 5;	
	prioq_push(p_pq, e);

	prioq_peek(p_pq, &e);
	printf("PQ peek : %d, %d\n", e.key, e.data);

	prioq_destroy(&p_pq);
}

void test_q(void)
{
	QUEUE *p_q;
	int i;

	p_q = q_create(5);

	printf("Q full test : %d\n", q_is_full(p_q));
	printf("Q empty test : %d\n", q_is_empty(p_q));
	q_enqueue(p_q, 10);
	for (i = 0; i < p_q->size; i++)
		printf("Q data : %d\n", p_q->p_data[i]);
	printf("\n");
	q_enqueue(p_q, 11);
	q_enqueue(p_q, 12);
	q_enqueue(p_q, 13);
	q_enqueue(p_q, 14);
	for (i = 0; i < p_q->size; i++)
		printf("Q data : %d\n", p_q->p_data[i]);
	printf("\n");

	printf("Q enqueue test : %d\n", q_enqueue(p_q, 10));

	printf("\n");

	q_dequeue(p_q, &i);
	printf("Q dequeue test : %d\n", i);

	q_enqueue(p_q, 21);
	q_dequeue(p_q, &i);
	printf("Q dequeue test : %d\n", i);
	printf("Q test [f : %d], [b : %d]\n", p_q->front, p_q->back);

	q_enqueue(p_q, 22);
	q_dequeue(p_q, &i);
	printf("Q dequeue test : %d\n", i);
	printf("Q test [f : %d], [b : %d]\n", p_q->front, p_q->back);

	q_enqueue(p_q, 23);
	q_dequeue(p_q, &i);
	printf("Q dequeue test : %d\n", i);
	printf("Q test [f : %d], [b : %d]\n", p_q->front, p_q->back);

	q_enqueue(p_q, 24);
	q_dequeue(p_q, &i);
	printf("Q dequeue test : %d\n", i);
	printf("Q test [f : %d], [b : %d]\n", p_q->front, p_q->back);

	q_enqueue(p_q, 25);
	q_dequeue(p_q, &i);
	printf("Q dequeue test : %d\n", i);
	printf("Q test [f : %d], [b : %d]\n", p_q->front, p_q->back);

	q_enqueue(p_q, 26);
	q_dequeue(p_q, &i);
	printf("Q dequeue test : %d\n", i);
	printf("Q test [f : %d], [b : %d]\n", p_q->front, p_q->back);

	q_dequeue(p_q, &i);
	printf("Q dequeue test : %d\n", i);

	if (q_dequeue(p_q, &i) == 0)
		printf("Q dequeue test : %d\n", i);

	printf("\n");

	for (i = 0; i < p_q->size; i++)
		printf("Q data : %d\n", p_q->p_data[i]);

	printf("Q full test : %d\n", q_is_full(p_q));

	printf("\n");
	q_destroy(&p_q);
}

void test_stack(void)
{
	STACK *s;
	ELEMENT_TYPE a;

	s = s_create(3);

	a = 1;
	s_push(s, a);
	
	s_peek(s, &a);
	printf("Stack : %d\n", a);

	a = 2;
	s_push(s, a);

	s_peek(s, &a);
	printf("Stack : %d\n", a);

	s_destroy(&s);
}

int main(int argc, char **argv)
{
	test_stack();
	test_q();
	test_deq();
	test_prioq();
	test_da();
	test_sll();
	test_dll();

	return 0;
}
