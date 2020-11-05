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


typedef struct node{
    int elem;
    struct node *next;
}Node;

Node* initNode(){
    Node* pHead = (Node *)malloc(sizeof(Node));
    pHead->elem = 0;
    pHead->next = NULL;
    return pHead;
}

Node* find(Node* pl, int pos){
    if (pos >= pl->elem) {
        return NULL;
    }
    //pos=0:pl->next
    //pos=1:pl->next->next
    while (pos >= 0) {
        pl = pl->next;
        pos--;
    }
    return pl;
}

void insert(Node* pl, int value, int pos){
    //1.创建一个新的节点
    Node* pNew=(Node *)malloc(sizeof(Node));
    pNew->elem = value;
    //2.找到pos-1
    Node *pre=find(pl, pos-1);
    
    //3.pl->next=pos-1->next
    pNew->next=pre->next;
    
    //4.pos-1->next=pl
    pre->next=pNew;
    pl->elem++;
}

void del(Node* pl,int pos){
    
    //找到pos-1位置
    Node* pre=find(pl, pos-1);
    if (pre == NULL) {
        // 找不到这个位置
        printf("找不到这个节点(%d), 总长度为%d\n", pos-1, pl->elem);
        return;
    }

    //pos-1->next=pos-1->next->next
    pre->next = pre->next->next;
    pl->elem--;
    
}


Node* search(Node* pl, int x){
    pl=pl->next;
    while (pl != NULL) {
        if (pl->elem == x) {
            return pl;
        }
        pl=pl->next;
    }
    return NULL;
}



void print(Node* pl){
    //指向第0个节点
    pl=pl->next;
    while (pl != NULL) {
        printf("%4d",pl->elem);
        pl=pl->next;
    }
    printf("\n");
    
}
    
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
