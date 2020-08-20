//
//  main.c
//  stack
//
//  Created by edz on 2020/8/14.
//  Copyright © 2020 jianghao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
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
*/

typedef struct stack{
    
    int elem;
    struct stack *next;
}Stack;

Stack* init(){
    Stack* s=malloc(sizeof(Stack));
    s->elem=0;
    s->next=NULL;
    return s;
}

int peek(Stack* s){
    return s->next->elem;
}

bool isEmpty(Stack* s){
    if (s->next==NULL) {
        return true;
    }else{
        return false;
    }
}



Stack* Find(Stack* st, int pos){
    if (pos >= st->elem) {
        return NULL;
    }
    //pos=0:pl->next
    //pos=1:pl->next->next
    while (pos >= 0) {
        st = st->next;
        pos--;
    }
    return st;
}

void push(Stack* st, int value, int pos){
    //1.创建一个新的节点
    Stack* pNew=(Stack *)malloc(sizeof(Stack));
    pNew->elem = value;
    //2.找到pos-1
    Stack *pre=Find(st, pos-1);
    
    //3.pl->next=pos-1->next
    pNew->next=pre->next;
    
    //4.pos-1->next=pl
    pre->next=pNew;
    st->elem++;
}


int pop(Stack* st){
    
    st->next=st->next->next;
    st->elem--;
    return st->next->elem;
    
}

void print(Stack* st){
    //指向第0个节点
    st=st->next;
    while (st != NULL) {
        printf("%4d",st->elem);
        st=st->next;
    }
    printf("\n");
    
}

int main(int argc, const char * argv[]) {
    //Node* pl=initNode();
   
    Stack* st=init();
    
    for (int i=0; i<10; i++) {
        push(st, i*100, 0);
        peek(st);
        print(st);
    }
    
    for (int i=0; i<10; i++) {
        pop(st);
        peek(st);
        print(st);
    }
    
    
    
    
    /*
    for (int i=0; i<10; i++) {
        insert(pl, i*100, i);
        print(pl);
    }
    
    
    Node* pr = search(pl, 300);
       if (pr != NULL) {
           printf("找到了%d\n", pr->elem);
       } else
           printf("没找到\n");
    
    
    for (int i=0; i<10; i++) {
        del(pl, pl->elem-1);
        print(pl);
    }
    
    
    */
   
    return 0;
}
