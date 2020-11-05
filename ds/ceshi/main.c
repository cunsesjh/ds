//
//  main.c
//  ceshi
//
//  Created by edz on 2020/8/15.
//  Copyright © 2020 jianghao. All rights reserved.
//

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct stack{
    int elem;
    struct stack *next;
} Stack, Queue;

Stack* init_stack(void);
void free_stack(Stack* head);
int push(Stack* head, int elem);
int pop(Stack* head);
int top(Stack* head);
int is_full(Stack* head);
int is_empty(Stack* head);


Stack* init_stack(void) {
    Stack* head = malloc(sizeof(Stack));
    head->next = NULL;
    return head;
}


void free_stack(Stack* head) {
    Stack* t;
    while(head->next != NULL) {
        t = head->next;
        free(head);
        head = t;
    }
    free(head);
}

/*
 * ===  FUNCTION  =============================================================
 *         Name:  push
 *  Description:  将元素elem压栈
 *       Return:  成功-1；失败-0
 * ============================================================================
 */
int push(Stack* head, int elem) {
    Stack *new_node = malloc(sizeof(Stack));
    if (new_node == NULL) {
        // 分配内存失败
        return 0;
    }
    new_node->elem = elem;
    new_node->next = head->next;
    head->next = new_node;
    return 1;
}


/*
 * ===  FUNCTION  =============================================================
 *         Name:  pop
 *  Description:  弹出栈顶节点, 返回该节点的元素值
 *                注意栈为空时应报错
 * ============================================================================
 */
int pop(Stack* head) {
    if (is_empty(head)) {
        printf("stack is empty\n");
        return INT_MIN;
    }
    Stack* t = head->next;
    head->next = t->next;
    int elem = t->elem;
    free(t);
    return elem;
}


/*
 * ===  FUNCTION  =============================================================
 *         Name:  top
 *  Description:  返回栈顶节点元素的值
 *                注意栈为空时应报错
 * ============================================================================
 */
int top(Stack* head) {
    if (is_empty(head)) {
        printf("stack is empty\n");
        return INT_MIN;
    }
    return head->next->elem;
}


/*
 * ===  FUNCTION  =============================================================
 *         Name:  is_empty
 *  Description:
 *       Return: 1: 为空； 0: 不为空
 * ============================================================================
 */
int is_empty(Stack* head) {
    return (head->next == NULL)?1:0;
}

int enqueue(Queue* queue, int data){
    return push(queue, data);
}

int dequeue(Queue* queue){
    Stack* s = init_stack();
    while (queue != NULL) {
        int temp = pop(queue);
        push(s, temp);
        queue=queue->next;
    }
    
    int a=pop(s);
    
    while (s != NULL) {
        int temp=pop(s);
        push(queue, temp);
        s=s->next;
    }
    return a;
    
}

int main(void) {
    Queue* queue = init_stack();
    int a[5] = {1, 2, 3, 4, 5};
    for( int i = 0; i < 5; i++) {
        enqueue(queue, a[i]);  // 可按照自己的函数定义进行修改
        printf("%d\n",top(queue));
    }
    

    for (int i = 0; i < 5; i++) {
    int out = dequeue(queue); // 可按照自己的函数定义进行修改
        printf("%3d", out);
    }
    printf("\n");
 
    return 0;
}
