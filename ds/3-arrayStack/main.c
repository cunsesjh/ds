//
//  main.c
//  3-arrayStack
//
//  Created by edz on 2020/8/18.
//  Copyright © 2020 jianghao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    int capacity;
    int* head;
} Stack;

Stack* init() {
    Stack* s = malloc(sizeof(Stack));
    s->capacity = 10;
    s->top = 0;
    s->head = malloc(sizeof(int) * s->capacity);
    return s;
}

void push(Stack* s, int value) {
    s->head[s->top] = value;
    s->top++;
}

int pop(Stack* s) {
    s->top--;
    return s->head[s->top];
}

int peek(Stack* s) {
    return s->head[s->top-1];
}

int isEmpty(Stack* s) {
    return s->top == 0;
}

int main() {
    Stack* s = init();
    for (int i = 0; i < 10; i++) {
        push(s, i);
    }
    while(!isEmpty(s)) {
        printf("%3d", pop(s));
    }
    printf("\n");
}
