//
//  main.c
//  ceshi
//
//  Created by edz on 2020/8/15.
//  Copyright © 2020 jianghao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    unsigned long long j=0;
    for (int i = 0; i <digitsSize; i++) {
        j = j * 10 + digits[i];
    }
    /*
    for (int i=0; i<digitsSize; i++) {
        j+=digits[digitsSize-i-1]*pow(10, i);
        printf("i = %d, j = %lld\n", i, j);
    }
     */
    
    printf("%lld\n", j);

    
    j=j+1;
    
    printf("%lld\n", j);

    
    if (j>pow(10, digitsSize)-1) {
        *returnSize=digitsSize+1;
        int* a=(int *)malloc(sizeof(int)*(digitsSize+1));
        a[0]=1;
        for(int i=1;i<*returnSize;i++){
            a[i]=0;
        }
        return a;
        
    }else{
        *returnSize=digitsSize;
        int* a=(int *)malloc(sizeof(int)*(digitsSize));
        for (int k=*returnSize-1; k>=0; k--) {
            a[k]= j%10;
            printf("k = %d, j = %lld\n", k, j);
            j/=10;
        }
        return a;

    }
}

int main(){
    
    int di[]={
        1,2,3, 4, 5, 6, 7,8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int returnsize=10;
    /*
     *a=plusOne(di, 10,returnsize);
    for (int i=0; i<10; i++) {
        printf("%d",*(a+i));
    }
     */
    int* a = plusOne(di, sizeof(di) / sizeof(di[0]), &returnsize);
    long long l = -1;
    unsigned long long ll = (unsigned long long)-1;
    printf("%d\n", sizeof(ll));
    printf("%x\n", ll);
    for (int i = 0; i < returnsize; i++)
        printf("%3d", a[i]);
    printf("\n");
    return 0;
}
