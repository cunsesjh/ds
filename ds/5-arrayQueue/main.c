//
//  main.c
//  5-arrayQueue
//
//  Created by edz on 2020/8/18.
//  Copyright © 2020 jianghao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct queue {
    int* data;
    int head;
    int tail;
} Queue;

Queue* initQueue() {
    Queue * q = malloc(sizeof(Queue));
    q->head = q->tail = 0;
    q->data = malloc(sizeof(int) * 10);
    return q;
}

void enqueue(Queue* q, int value) {
    q->data[q->tail] = value;
    q->tail++;
}

int dequeue(Queue* q) {
    int ret = q->data[q->head];
    q->head++;
    return ret;
}

int isEmpty(Queue* q) {
    return q->head == q->tail;
}

int peek(Queue* q) {
    return q->data[q->head];
}
