#include "bt_tree.h"
#include <stdlib.h>
#include "DEBUG_SWICTHES.H"

int main() {
	BT_PTR bt;

	bt = create_bt_pre();

#if OREDERS_DEBUG
	printf("pre order: ");
	pre_traversal(bt);
	printf("\n");
	
	printf("in order: ");
	in_traversal(bt);
	printf("\n");
	
	printf("post order: ");
	post_traversal(bt);
	printf("\n");
#endif

#if STACK_BT_DEBUG
	#include "stack_bt.h"
	ST_PTR test_stack;
	
	test_stack = init_st();
	push_in(test_stack, bt);
	push_in(test_stack, bt->l_child);
	pull_out(test_stack);
	push_in(test_stack, bt->r_child);
	destory_st(test_stack);
	
	void pull_out(ST_PTR _st);
	BOOL is_empty(ST_PTR _st);
	BOOL is_full(ST_PTR _st);
#endif

	destory_bt(bt);

	system("pause");

	return 0;
}
