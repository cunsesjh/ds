//
//  main.c
//  4-linkedStack
//
//  Created by edz on 2020/8/14.
//  Copyright © 2020 jianghao. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>

#include "LinkedList.h"
#include "LinkedStack.h"

Stack* initStack() {
    return init();
}

void push(Stack* s, int value) {
    insert(s, 0, value);
}

int pop(Stack* s) {
    return del(s, 0);
}

int peek(Stack* s) {
    return s->pNext->elem;
}

int isEmpty(Stack* s) {
    return (s->pNext == NULL);
}
