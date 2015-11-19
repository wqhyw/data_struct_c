#include "seq_stack.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	ST_PTR s;
	int i;
	data_t temp_data;

	s = init_st();
	for (i = 0; i < 10; i++) push_in(s, 'A' + i);
	printf("top data: %c\n", get_top(s));
	printf("stack size: %d\n", get_size(s));
	printf("is empty: %d\n", is_empty(s));
	printf("is full: %d\n\n", is_full(s));
	pull_out(s, &temp_data);
	printf("top data: %c\n", get_top(s));
	printf("stack size: %d\n", get_size(s));
	printf("is empty: %d\n", is_empty(s));
	printf("is full: %d\n", is_full(s));

	destory_st(s);

	system("pause");

	return 0;
}
