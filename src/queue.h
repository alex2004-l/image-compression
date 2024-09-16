#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct queue_node {
    void *data;
    size_t size;
    struct queue_node *next;
} qnode;

typedef struct queue {
    qnode *first;
    qnode *last;
    int size;
} *queue;


queue init_queue(void);
qnode *create_node(void *data, size_t size);
int queue_is_empty(queue q);
void enqueue(queue *q, void *data, size_t size);
qnode *dequeue(queue q);
void destroy_queue_node(qnode *node);
void destroy_queue(queue q);

#endif