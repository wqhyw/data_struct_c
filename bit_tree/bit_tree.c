#include "bt_tree.h"
#include "DEBUG_SWICTHES.H"
#include "stack_bt.h"
#include <malloc.h>
#include <stdio.h>

BT_PTR create_bt_pre(){
	BT_PTR temp_bt_node;
	bt_data_t temp_data;

#if SCANF_CHECK
	printf("input (Null node instead bny '#' include leafs' leafs): ");
#endif

	scanf("%c", &temp_data);
	if (temp_data == '#')
		temp_bt_node = NULL;
	else {
		temp_bt_node = (BT_PTR)malloc(sizeof(bt_node));
		temp_bt_node->data = temp_data;
		temp_bt_node->l_child = create_bt_pre();
		temp_bt_node->r_child = create_bt_pre();
	}

	return temp_bt_node;
}

void destory_bt(BT_PTR _bt) {
	if (!_bt) return;

	destory_bt(_bt->l_child);
	destory_bt(_bt->r_child);
	free(_bt);
};

void visit_node(BT_PTR _bt_node) {
		printf("%c ", _bt_node->data);
};

void pre_traversal(BT_PTR _bt) {
	if (_bt) {
		visit_node(_bt);
		pre_traversal(_bt->l_child);
		pre_traversal(_bt->r_child);
	}

#if CHILD_NULL_CHECK
	else
		printf("NULL NODE!");
#endif
};

void in_traversal(BT_PTR _bt) {
	if (_bt) {
		in_traversal(_bt->l_child);
		visit_node(_bt);
		in_traversal(_bt->r_child);
	}

#if CHILD_NULL_CHECK
	else
		printf("NULL NODE!");
#endif
};

void post_traversal(BT_PTR _bt) {
	if (_bt) {
		in_traversal(_bt->l_child);
		in_traversal(_bt->r_child);
		visit_node(_bt);
	}

#if CHILD_NULL_CHECK
	else
		printf("NULL NODE!");
#endif
};

void pre_traversal_no_recursion(BT_PTR _bt) {
	ST_PTR temp_st;
	while (!(_bt && is_empty(temp_st)))
	{
		while (!_bt)
		{
			visit_node(_bt);
			push_in(temp_st, _bt);
			_bt = _bt->l_child;
		}
		if (!is_empty(temp_st))
		{
			_bt = get_top(temp_st);
			pull_out(temp_st);
			_bt = _bt->r_child;
		}
	}
};
//void in_traversal_no_recursion(BT_PTR _bt);
//void post_traversal_no_recursion(BT_PTR _bt);
//bt_size_t get_depth(BT_PTR _bt);
//bt_size_t leaf_amount(BT_PTR _bt);
