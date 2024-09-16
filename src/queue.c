#include "queue.h"


queue init_queue(void) {
    queue new_queue = malloc(sizeof(struct queue));

    new_queue->first = new_queue->last = NULL;
    new_queue->size = 0;

    return new_queue;
}


qnode *create_node(void *data, size_t size) {
    qnode *new_node = malloc(sizeof(struct queue_node));

    new_node->data = malloc(size);
    memcpy(new_node->data, data, size);

    new_node->size = size;
    new_node->next = NULL;

    return new_node;
}


int queue_is_empty(queue q) {
    return q == NULL || q->first == NULL || q->size == 0;
}


void enqueue(queue *q, void *data, size_t size) {
    if (*q == NULL)
        *q = init_queue();

    qnode *node = create_node(data, size);

    if ((*q)->first == NULL) {
        (*q)->first = (*q)->last = node;
        (*q)->size = 1;
    } else {
        (*q)->last->next = node;
        (*q)->last = node;
        (*q)->size += 1;
    }
}


qnode *dequeue(queue q) {
    if (q == NULL || q->first == NULL)
        return NULL;

    qnode *result = q->first;
    q->first = q->first->next;
    q->size --;
    if (q->size == 0)
        q->last = NULL;

    return result;
}


void destroy_queue_node(qnode *node) {
    free(node->data);
    free(node);
}


void destroy_queue(queue q) {
    if (q == NULL)
        return;

    qnode *tmp, *iter = q->first;
    while(iter != NULL) {
        tmp = iter;
        iter = iter->next;

        free(tmp->data);
        free(tmp);
    }

    free(q);
}