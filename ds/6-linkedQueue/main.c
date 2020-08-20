//
//  main.c
//  6-linkedQueue
//
//  Created by edz on 2020/8/14.
//  Copyright © 2020 jianghao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int elem;
    struct node *next;
}Node;

typedef Node Queue;

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

int isEmpty(Queue* qu);

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

int del(Node* pl, int pos) {
    // 1. 找到上一个节点
    Node* pre = find(pl, pos-1);

    if (pre == NULL) {
        // 找不到这个位置
        printf("找不到这个节点(%d), 总长度为%d\n", pos-1, pl->elem);
        return -1;
    }

    // 2. 上一个节点指向下一个节点
    int ret = pre->next->elem;
    pre->next = pre->next->next;
    pl->elem--;
    return ret;
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

//enqueue:insert(Queue* qu,value,qu->elem)
//dequeue:del(Queue* qu,0)
//peek:return qu->next->elem
//isEmpty:return qu->elem==0;

void enqueue(Queue* qu,int value){
    insert(qu, value, qu->elem);
}

int dequeue(Queue* qu){
    int res=qu->next->elem;
    del(qu, 0);
    return res;
}

int peek(Queue* qu){
    return qu->next->elem;
}

int isEmpty(Queue* qu){
    return (qu->elem == 0);
}

int main(int argc, const char * argv[]) {
    //Node* pl=initNode();
   
    Queue* qu=initNode();
    
    /*
    for (int i = 0; i < 10; i++) {
        enqueue(qu, i);
    }
    while(!isEmpty(qu)) {
        printf("%3d", dequeue(qu));
    }
    printf("\n");
    */
    
    for (int i=0; i<10; i++) {
        enqueue(qu, i);
        print(qu);
    }
    printf("\n");
    
    
    while(!isEmpty(qu)) {
        printf("%4d", dequeue(qu));
    }
    printf("\n");
    
    /*
    for (int i=0; i<10; i++) {
        dequeue(qu);
        print(qu);
    }

    */
   
    return 0;
}
