//
//  main.c
//  2-linkedList
//
//  Created by edz on 2020/8/12.
//  Copyright © 2020 jianghao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


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




int main(int argc, const char * argv[]) {
    Node* pl=initNode();
    
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
    
    
    
   
    return 0;
}
