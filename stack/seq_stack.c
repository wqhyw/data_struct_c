#include "seq_stack.h"
#include <malloc.h>
#include <stdio.h>

ST_PTR init_st() {
	ST_PTR st = (ST_PTR)malloc(sizeof(STACK));
	st->datas = (DT_PTR)malloc(sizeof(data_t) * MAXSIZE);
	st->base = 0;
	st->top = 0;

	return st;
};

void destory_st(ST_PTR _st) {
	free(_st->datas);
	free(_st);
	_st->datas = NULL;
	_st = NULL;
};

void push_in(ST_PTR _st, data_t _new_data) {
	if (is_full(_st)) {
		printf("STACK IS FULL! PUSH_IN FAIELD!\n");
	}
	else {
		_st->datas[_st->top++] = _new_data;
	}
};

void pull_out(ST_PTR _st, DT_PTR _top_data) {
	if (is_empty(_st)) {
		printf("STACK IS EMPTY! PULL_OUT FAIELD!\n");
		exit(1);
	}
	else {
		_top_data = _st->datas[--_st->top];
	}
};

data_t get_top(ST_PTR _st) {
	return _st->datas[_st->top - 1];
};

size_t get_size(ST_PTR _st) {
	return _st->top - _st->base;
};

BOOL is_empty(ST_PTR _st) {
	BOOL bl;
	return (bl = _st->base == _st->top ? TRUE : FALSE);
};

BOOL is_full(ST_PTR _st) {
	BOOL bl;
	return (bl = _st->top == MAXSIZE ? TRUE : FALSE);
};