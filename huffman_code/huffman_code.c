#include <stdio.h>
#include <stdlib.h>
#include "huffman_code.h"

#define FUNCTION_TEST 1

HTN hc_init(int _node_amount) {
	int size = 2 * _node_amount;
	HTN ht = (HTN)malloc(sizeof(h_t_n) * size);
	int index = 0;

	while (++index <= _node_amount) {
		printf("第%d个字符: ", index);
		scanf("%s", &ht[index].data);	
		printf("%c的权重: ", ht[index].data);
		scanf("%d", &ht[index].weight);
		ht[index].l_child = 0;
		ht[index].r_child = 0;
		ht[index].parent = 0;
		ht[index].flag = FALSE;
	}
	while (index < size) {
		ht[index].data = ' ';
		ht[index].weight = 0;
		ht[index].l_child = 0;
		ht[index].r_child = 0;
		ht[index].parent = 0;
		ht[index].flag = FALSE;
		index++;
	}
	ENDL;

	return ht;
}

void hc_select(HTN _ht, int _size, int *_t_1, int *_t_2) {
	int index, i = 0;
	int *temp = (int *)malloc(sizeof(int) * _size);

	for (index = 1; index < _size; index++) {
		if (!_ht[index].flag)
			temp[i++] = index;
	}

	hc_sort(_ht, temp, i);

	*_t_1 = temp[1];
	*_t_2 = temp[0];

	free(temp);
}

void hc_sort(HTN _ht, int *_arr, int _size) {
	int i, j, m;
	int temp;

	for (i = 1; i < _size; i++) {
		for (j = 0; j < i; j++) {
			if (_ht[_arr[i]].weight < _ht[_arr[j]].weight)
				break;
		}

		temp = _arr[i];
		for (m = i; m > j; m--) {
			_arr[m] = _arr[m - 1];
		}
		_arr[j] = temp;
	}
}

void hc_create(HTN _ht, int _node_amount) {
	int size = 2 * _node_amount;
	int index, t_1, t_2;

	for (index = _node_amount + 1; index < size; index++) {
		hc_select(_ht, index, &t_1, &t_2);
		_ht[index].weight = _ht[t_1].weight + _ht[t_2].weight;
		_ht[index].l_child = t_1;
		_ht[index].r_child = t_2;
		_ht[t_1].parent = _ht[t_2].parent = index;
		_ht[t_1].flag = _ht[t_2].flag = TRUE;
	}
};

HC hc_encode(HTN _ht, int _node_amount) {
	HC cw_table = (HC)malloc(sizeof(h_c) * _node_amount);
	char *temp = (char *)malloc(sizeof(char) * _node_amount);
	int index = 1;
	int ht_flag, temp_flag = 0;

	while (index <= _node_amount) {
		ht_flag = index;
		cw_table[index - 1].data = _ht[index].data;

		while (_ht[ht_flag].parent) {
			if (ht_flag == _ht[_ht[ht_flag].parent].l_child)
				temp[temp_flag++] = '0';
			else if(ht_flag == _ht[_ht[ht_flag].parent].r_child)
				temp[temp_flag++] = '1';
			ht_flag = _ht[ht_flag].parent;
		}
		temp[temp_flag] = '\0';

		cw_table[index - 1].h_code = (char *)malloc(sizeof(char) * temp_flag);

		for (ht_flag = 0; ht_flag < temp_flag; ht_flag++) {
			cw_table[index - 1].h_code[ht_flag] = temp[temp_flag - 1 - ht_flag];
		}
		
		cw_table[index - 1].h_code[ht_flag] = '\0';
		temp_flag = 0;
		index++;
	}

	free(temp);

	return cw_table;
}

char *hc_uncode(HTN _ht, int _node_amount,char *_hf_code) {
	char *result = (char *)malloc(sizeof(char) * _node_amount);
	int index = 0, index_r = 0;
	int root = 2 * _node_amount - 1;
	int flag = root;
	int flag_move = 0;

	while (_hf_code[index] != '\0') {
		if (_hf_code[index++] == '0') {
			flag = _ht[flag].l_child;
			flag_move++;
		}	
		else {
			flag = _ht[flag].r_child;
			flag_move++;
		}
			
		if (!_ht[flag].l_child) {
			result[index_r++] = _ht[flag].data;
			flag = root;
			flag_move = 0;
		}

		else if (_hf_code[index] == '\0' && flag_move != 0) {
			printf("末尾%d位无效\n", flag_move);
		}
	}

	result[index_r] = '\0';

	return result;
}

void hc_print_ht(HTN _ht, int _node_amount) {
	int index;
	int size = 2 * _node_amount;

	printf("序号\t字符\t权重\t左孩子\t右孩子\t父节点\tflag\n");

	for (index = 1; index < size; index++)
		printf("%d\t%c\t%d\t%d\t%d\t%d\t%d\n", index, _ht[index].data, _ht[index].weight, _ht[index].l_child, _ht[index].r_child, _ht[index].parent, _ht[index].flag);

	ENDL;
}

void hc_print_cw(HC _cw_table, int _node_amount) {
	int index = 0;

	while (index < _node_amount) {
		printf("%c哈夫曼编码: %s\n", _cw_table[index].data, _cw_table[index].h_code);
		index++;
	}
	ENDL;
}

void hc_destory(HTN _ht) {
	free(_ht);
	_ht = NULL;
}

#if FUNCTION_TEST
int main() {
	int na = 6;
	HTN ht;

	ht = hc_init(na);
	hc_print_ht(ht, na);

	hc_create(ht, na);
	hc_print_ht(ht, na);
	hc_print_cw(hc_encode(ht, na), na);
	puts(hc_uncode(ht, na, "1101001"));

	hc_destory(ht);

	system("pause");
	return 0;
}

#endif
