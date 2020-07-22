#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#define QSIZE 10

// Queue
struct queue {
	long first;
	long last;
	int *data;
};

struct queue cqueue;

// Operation status
short op_status;

// Display Queue
void display_queue(struct queue *);

// Insert queue element
struct queue *queue_insert(struct queue *, int, short *);

// Remove element from the queue
int queue_remove(struct queue *, short *);

// Return first
int queue_first(struct queue *, short *);

#endif
