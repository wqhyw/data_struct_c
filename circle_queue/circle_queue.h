#ifndef _CIRCLE_QUEUE_H_
#define _CIRCLE_QUEUE_H_

#define MAXSIZE 15
#define data_t char
#define size_t unsigned
#define DT_PTR char*
#define index_t int

typedef enum { FALSE, TRUE } BOOL;
typedef struct circl_queue {
	DT_PTR datas;
	index_t rear;
	index_t front;
	size_t size;
}CIRCLE_QUEUE, *CQ_PTR;

extern CQ_PTR init_cq();
extern void destory_cq(CQ_PTR _cq);
extern void in_queue(CQ_PTR _cq, data_t _in_data);
extern void out_queue(CQ_PTR _cq, DT_PTR _out_data);
extern void front_move(index_t* _front, size_t _maxsize);
extern void rear_move(index_t* _rear, size_t _maxsize);
extern data_t get_front(CQ_PTR _cq);
extern size_t get_size(CQ_PTR _cq);
extern BOOL is_empty(CQ_PTR _cq);
extern BOOL is_full(CQ_PTR _cq);

#endif
