#include "stack_bt.h"
#include <malloc.h>
#include <stdio.h>

ST_PTR init_st() {
	ST_PTR st = (ST_PTR)malloc(sizeof(STACK));
	st->datas = (st_data_t *)malloc(sizeof(st_data_t) * MAXSIZE);
	st->base = 0;
	st->top = 0;

	return st;
};

void destory_st(ST_PTR _st) {
	free(_st->datas);
	_st->datas = NULL;
	free(_st);
	_st = NULL;
};

void push_in(ST_PTR _st, st_data_t _new_data) {
	if (is_full(_st)) {
		printf("STACK IS FULL! PUSH_IN FAIELD!\n");
	}
	else {
		_st->datas[_st->top++] = _new_data;
	}
};

void pull_out(ST_PTR _st) {
	if (is_empty(_st)) {
		printf("STACK IS EMPTY! PULL_OUT FAIELD!\n");
		exit(1);
	}
	else {
		--_st->top;
	}
};

st_data_t get_top(ST_PTR _st) {
	return _st->datas[_st->top - 1];
};

BOOL is_empty(ST_PTR _st) {
	BOOL bl;
	return (bl = _st->base == _st->top ? TRUE : FALSE);
};

BOOL is_full(ST_PTR _st) {
	BOOL bl;
	return (bl = _st->top == MAXSIZE ? TRUE : FALSE);
};
