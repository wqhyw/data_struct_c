#ifndef _ST_PTRACK_H_
#define _ST_PTRACK_H_

#define MAXSIZE 100
#define data_t char
#define size_t unsigned
#define DT_PTR char*

typedef enum{FALSE, TRUE} BOOL;
typedef struct stack{
	DT_PTR datas;
	size_t top;
	int base;
}STACK, *ST_PTR;

extern ST_PTR init_st();
extern void destory_st(ST_PTR _st);
extern void push_in(ST_PTR _st, data_t _new_data);
extern void pull_out(ST_PTR _st, DT_PTR _top_data);
extern data_t get_top(ST_PTR _st);
extern size_t get_size(ST_PTR _st);
extern BOOL is_empty(ST_PTR _st);
extern BOOL is_full(ST_PTR _st);


#endif
