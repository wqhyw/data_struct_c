#ifndef _HUFFMAN_CODE_H_
#define _HUFFMAN_CODE_H_

#define ENDL printf("\n")

typedef enum {
	FALSE,
	TRUE
}BOOL;

typedef struct huffman_tree_node {
	int weight;
	char data;
	int l_child, r_child, parent;
	BOOL flag;
}h_t_n, *HTN;

typedef struct huffman_code {
	char data;
	char *h_code;
}h_c, *HC;

extern HTN hc_init(int _node_amount);
extern void hc_select(HTN _ht, int _size, int *_t_1, int *_t_2);
extern void hc_sort(HTN _ht, int *_arr, int _size);
extern void hc_create(HTN _ht, int _node_amount);
extern HC hc_encode(HTN _ht, int _node_amount);
extern char *hc_uncode(HTN _ht, int _node_amount, char *_hf_code);
extern void hc_destory(HTN _ht);
extern void hc_print_ht(HTN _ht, int _node_amount);
extern void hc_print_cw(HC _cw_table, int _node_amount);

#endif
