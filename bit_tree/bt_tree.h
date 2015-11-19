#ifndef _BT_PTR_TREE_H_
#define _BT_PTR_TREE_H_

#define bt_data_t char
#define bt_size_t unsigned

typedef struct bit_tree {
	bt_data_t data;
	struct bit_tree* l_child;
	struct bit_tree* r_child;
}bt_node, *BT_PTR;

extern BT_PTR create_bt_pre();
extern void destory_bt(BT_PTR _bt);
extern void visit_node(BT_PTR _bt_node);
extern void pre_traversal(BT_PTR _bt);
extern void in_traversal(BT_PTR _bt);
extern void post_traversal(BT_PTR _bt);
extern void pre_traversal_no_recursion(BT_PTR _bt);
extern void in_traversal_no_recursion(BT_PTR _bt);
extern void post_traversal_no_recursion(BT_PTR _bt);
extern bt_size_t get_depth(BT_PTR _bt);
extern bt_size_t leaf_amount(BT_PTR _bt);

#endif
