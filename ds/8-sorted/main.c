//
//  main.c
//  8-selection
//
//  Created by edz on 2020/8/18.
//  Copyright © 2020 jianghao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int a[], int n){
    for (int i=0; i<10; i++) {
        printf("%4d",a[i]);
    }
    printf("\n");
}

void selection(int a[],int n){
    //i从0到n-2
    for (int i=0; i<n-1; i++) {
        //从i到n-1选一个最小的出来，和i进行交换
        int iMin=i;
        for (int j=i+1; j<n; j++) {
            if (a[j]<a[iMin]) {
                iMin=j;
            }
        }
        if (iMin != i) {
            int t=a[iMin];
            a[iMin]=a[i];
            a[i]=t;
        }
        printArray(a, n);
    }
}

void insertSorted(int a[], int n){
    for (int i=1; i<n; i++) {
        int j=i;
        while (j>0 && a[j]<a[j-1]) {
            int t=a[j];
            a[j]=a[j-1];
            a[j-1]=t;
            j--;
        }
        printArray(a, n);
    }
}

void Bubble(int a[], int n){
    for (int i=0; i<n-1; i++) {
        int flag=1;
        for (int j=0; j<n-1-i; j++) {
            if (a[j]>a[j+1]) {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                flag=0;
            }
        }
        if (flag==1) {
            break;
        }
        printArray(a, n);
    }
}

void quick(int a[],int n){
    if (n<=1) {
        return;
    }
    //1.使用a[0]将n个元素分为两个部分，a[0]放到j的位置
    int j=n-1;
    int i=1;
    while (1) {
        while (i<n && a[i]<a[0]) {
            i++;
        }
        while (j>=i && a[j]>=a[0]) {
            j--;
        }
        //如果找到了i，j，交换元素
        if (i<=j) {
            int t=a[i];a[i]=a[j];a[j]=t;
        }else {
            if (j != 0) {
                int t=a[0];a[0]=a[j];a[j]=t;
            }
            break;
        }
    }
    //2.再对0,...,j-1进行处理
    quick(a, j);
    //3.对j+1,...,n-1进行处理
    quick(a+j+1, n-(j+1));
    printArray(a, n);
}

int main(int argc, const char * argv[]) {
    int a[10];
    srand((int)time(NULL));
    for (int i=0; i<10; i++) {
        a[i]=rand()%100;
    }
    printArray(a, 10);
    
    //selection(a, 10);
    
    //insertSorted(a, 10);
    
    //Bubble(a, 10);
    
    quick(a, 10);

    
    return 0;
}
