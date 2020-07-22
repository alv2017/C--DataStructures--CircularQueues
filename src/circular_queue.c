#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

void display_queue(struct queue *q) {
	long cnt = 1;
	long i = q->first;
	if (q->first == -1) {
		printf("The queue is empty.\n");
		return;
	}

	while (i != q->last ) {
		printf("Queue: %ld; position: %ld; value: %d\n", cnt, i, q->data[i]);
		i = (i+1) % QSIZE;
		cnt++;
	}
	printf("Queue: %ld; position: %ld; value: %d\n", cnt, i, q->data[i]);
}

struct queue *queue_insert(struct queue *q, int value, short *op_status) {
	*op_status = 0;
	if (q->first==0 && q->last==QSIZE-1) {
		printf("The queue is full.\n");
		return q;
	}
	*op_status = 1;
	if (q->first==-1 && q->last==-1) {
		q->first = 0;
		q->last = 0;
		q->data[q->last] = value;

	} else {
		q->last = (q->last + 1) % QSIZE;
	}
	q->data[q->last] = value;
	return q;
}

int queue_remove(struct queue *q, short *op_status) {
	*op_status = 0;
	int val = 0;
	if (q->first == -1) {
		printf("The queue is empty. There is nothing to remove.\n");
		return val;
	}

	*op_status = 1;
	val = q->data[q->first];

	if (q->first == q->last) {
		q->first = -1;
		q->last = -1;
	} else {
		q->first = (q->first + 1) % QSIZE;
	}

	return val;
}

int queue_first(struct queue *q, short *op_status) {
	*op_status = 0;
	int val = 0;
	if (q->first == -1) {
		printf("The queue is empty.\n");
		return val;
	}
	*op_status = 1;
	val = q->data[q->first];
	return val;
}










