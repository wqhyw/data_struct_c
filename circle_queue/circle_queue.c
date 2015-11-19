#include "circle_queue.h"
#include <malloc.h>

CQ_PTR init_cq() {
	CQ_PTR temp_cq = (CQ_PTR)malloc(sizeof(CIRCLE_QUEUE));
	DT_PTR temp_datas = (DT_PTR)malloc(sizeof(data_t) * MAXSIZE);
	
	temp_cq->datas = temp_datas;
	temp_cq->front = 0;
	temp_cq->rear = 0;
	temp_cq->size = 0;

	return temp_cq;
};

void destory_cq(CQ_PTR _cq) {
	free(_cq->datas);
	_cq->datas = NULL;
	free(_cq);
	_cq = NULL;
};

void in_queue(CQ_PTR _cq, data_t _in_data) {
	_cq->datas[_cq->rear] = _in_data;
	rear_move(&(_cq->rear), MAXSIZE);
	++_cq->size;
};

void out_queue(CQ_PTR _cq, DT_PTR _out_data) {
	*_out_data = _cq->datas[_cq->front];
	front_move(&(_cq->front), MAXSIZE);
	--_cq->size;
};

void front_move(index_t* _front, size_t _maxsize) {
	*_front = (*_front + 1) % _maxsize;
};

void rear_move(index_t* _rear, size_t _maxsize) {
	*_rear = (*_rear + 1) % _maxsize;
};

data_t get_front(CQ_PTR _cq) {
	return _cq->datas[_cq->front];
};

size_t get_size(CQ_PTR _cq) {
	return _cq->size;
};

BOOL is_empty(CQ_PTR _cq) {
	BOOL bl;
	return (bl = _cq->front == _cq->rear ? TRUE : FALSE);
};

BOOL is_full(CQ_PTR _cq) {
	BOOL bl;
	return (bl = (_cq->rear + 1) % MAXSIZE == _cq->front ? TRUE : FALSE);
};