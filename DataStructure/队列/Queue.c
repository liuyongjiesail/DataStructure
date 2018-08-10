//
//  Queue.c
//  DataStructure
//
//  Created by 刘永杰 on 2018/8/8.
//  Copyright © 2018年 刘永杰. All rights reserved.
//

#include "Queue.h"

// 队列测试
void QueueTest(void) {
    
    Queue *q = InitQueue();
    
    AddQueue(q, 0);
    AddQueue(q, 1);
    AddQueue(q, 2);
    AddQueue(q, 3);
    AddQueue(q, 4);
    
    PrintQueue(q);
    
    DeleteQueue(q);
    DeleteQueue(q);
    DeleteQueue(q);

    PrintQueue(q);
    
    AddQueue(q, 5);
    AddQueue(q, 6);
    AddQueue(q, 7);
    AddQueue(q, 8);
    AddQueue(q, 9);
    AddQueue(q, 10);

    
    PrintQueue(q);

}

// 初始化
Queue * InitQueue(void) {
    Queue *q;
    q = (Queue *)malloc(sizeof(QUEUEMAXSIZE));
    if (!q) {
        printf("空间不足\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

// 入队
void AddQueue(Queue *q, ElementType item) {
    if (IsFullQueue(q)) {
        printf("队列已满\n");
        return;
    }
    q->rear++;
    q->rear %= QUEUEMAXSIZE;
    q->size++;
    q->data[q->rear] = item;
}

// 出队
ElementType DeleteQueue(Queue *q) {
    if (IsEmptyQueue(q)) {
        printf("队列为空\n");
        return QUEUEERROR;
    }
    q->front++;
    q->front %= QUEUEMAXSIZE;
    q->size--;
    return q->data[q->front];
}

// 打印队列
void PrintQueue(Queue *q) {
    if (IsEmptyQueue(q)) {
        printf("空队列\n");
        return;
    }
    printf("队列数据元素如下：\n");
    int index = q->front;
    for (int i = 0; i < q->size; i++) {
        index++;
        index %= QUEUEMAXSIZE;
        printf("%d\n", q->data[index]);
    }
}

// 判断队列是否已满
int IsFullQueue(Queue *q) {
    return (q->size == QUEUEMAXSIZE);
}

// 判断队列是否为空
int IsEmptyQueue(Queue *q) {
    return (q->size == 0);
}
