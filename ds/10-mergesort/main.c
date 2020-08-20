//
//  main.c
//  10-mergesort
//
//  Created by edz on 2020/8/19.
//  Copyright © 2020 jianghao. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArray(int a[], int n){
    for (int i=0; i<n; i++) {
        printf("%5d",a[i]);
    }
    printf("\n");
}

void merge(int a[], int n, int m){
    int c[n];
    int *b=a+m;
    int i=0,j=0,k=0;
    while (i<m && j<n-m) {
        if (a[i]<b[j]) {
            c[k]=a[i];
            i++;k++;
        }else{
            c[k]=b[j];
            j++;k++;
        }
    }
    if (i != m) {
        //a里面有剩余
        for (; i<m; i++) {
            c[k++]=a[i];
        }
    }else{
        //b里面有剩余
        for (; j<n-m; j++) {
            c[k++]=b[j];
        }
    }
    for (i=0; i<n; i++) {
        a[i]=c[i];
    }
}

void mergesorted(int a[], int n){
    if (n<=1) {
        return ;
    }
    int m=n/2;
    mergesorted(a, m);
    mergesorted(a+m, n-m);
    merge(a, n, m);
    printArray(a, n);
}

int main(int argc, const char * argv[]) {
    int a[10];
    srand((unsigned int)time(NULL));
    for (int i=0; i<10; i++) {
        a[i]=rand()%100;
    }
    printArray(a, 10);
    mergesorted(a, 10);
    return 0;
}
