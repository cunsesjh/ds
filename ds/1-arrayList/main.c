//
//  main.c
//  1-arrayList
//
//  Created by edz on 2020/8/12.
//  Copyright © 2020 jianghao. All rights reserved.
//



#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int *head;
    int lenth;
    int capacity;
}SeqList;

//初始化顺序表
SeqList* initSeqList(int cap){
    
    SeqList* pl = (SeqList*)malloc(sizeof(SeqList));
    pl ->capacity =cap;
    pl ->head=(int *)malloc(sizeof(int)*cap);
    pl ->lenth=0;
    return pl;
}

//增加数据
void add(SeqList* pl, int value, int pos){
    if (pos > pl->lenth || pos < 0) {
        printf("插入位置有误\n");
    }
    
    for (int i = pl->lenth-1; i>=pos; i--) {
        pl->head[i+1] = pl->head[i];
    }
    pl->head[pos] = value;
    pl->lenth++;
    
    if (pl->lenth > pl->capacity) {
        printf("容量已满\n");
    }
    
}

//删除数据
void del(SeqList* pl, int pos){
    if (pos > pl->lenth-1 || pos < 0) {
        printf("删除位置有误\n");
    }
    
    for (int i=pos; i< pl->lenth-1; i++) {
        pl->head[i] = pl->head[i+1];
    }
    pl->lenth--;
    
    if (pl ->lenth == 0) {
        printf("已空,无法删除\n");
    }
}


//打印数据
void print(SeqList* pl){
    for (int i=0; i<pl->lenth; i++) {
        printf("%4d",pl->head[i]);
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    SeqList* pl=initSeqList(10);
    /*
    for (int i=0; i<10; i++) {
        add(pl, i*100, i);
    }
    print(pl);
    */
    
    /*
    for (int i=0; i<10; i++) {
        del(pl);
    }
    print(pl);
    */
     
    
    add(pl, 100, 0);
    add(pl, 200 ,1);
    print(pl);
    
    del(pl, 1);
    print(pl);
     
    return 0;
}
