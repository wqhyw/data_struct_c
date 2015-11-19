#ifndef _ST_PTRACK_H_
#define _ST_PTRACK_H_

#include "bt_tree.h"
#define MAXSIZE 100
#define st_data_t BT_PTR
#define st_size_t unsigned

typedef enum{FALSE, TRUE} BOOL;
typedef struct stack{
	st_data_t * datas;
	st_size_t top;
	int base;
}STACK, *ST_PTR;

extern ST_PTR init_st();
extern void destory_st(ST_PTR _st);
extern void push_in(ST_PTR _st, st_data_t _new_data);
extern void pull_out(ST_PTR _st);
extern st_data_t get_top(ST_PTR _st);
extern BOOL is_empty(ST_PTR _st);
extern BOOL is_full(ST_PTR _st);

#endif
