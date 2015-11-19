#include "circle_queue.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	CQ_PTR cq;
	int i;
	char temp;

	cq = init_cq();

	for (i = 0; i < 10; i++)
		in_queue(cq,'A' + i);
	
	printf("old size: %d\n", get_size(cq));
	printf("front data: %c\n", get_front(cq));
	out_queue(cq, &temp);
	printf("temp: %c\n", temp);
	printf("new size: %d\n", get_size(cq));
	printf("is empty: %d\n", is_empty(cq));
	printf("is full: %d\n", is_full(cq));
	
	destory_cq(cq);

	system("pause");

	return 0;
}
