//
//  Queue.h
//  DataStructure
//
//  Created by 刘永杰 on 2018/8/8.
//  Copyright © 2018年 刘永杰. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

/*
 
 队列是一种特殊的线性表，特殊之处在于它允许在表的前端（Front）进行删除操作，而在表的后端（Rear）进行插入操作，和栈一样，队列是一种操作受限制的线性表。
 1.进行插入的端称为队尾，进行删除操作的端称为对头。队列的数据元素又称为队列元素。
 2.在队列中插入一个队列元素称为入队，在队列中删除一个队列元素称为出队。队列中没有元素时，称为空队列。
 3.因为队列只允许在一端插入，在另一端删除，所以只有最早进入队列的元素才能最先从队列中删除，故队列又称为先进先出（FIFO）线性表。
 
 场景：类似现实生活中的排队机制，排在前面的人走了，后面的人跟上。
 
 */

/*
 队列的顺序存储结构通常由一个一维数组、一个记录队列头元素位置的变量front、一个记录队列尾元素位置的变量rear以及记录队列元素个数的变量size组成。
 */

#include <stdio.h>
#include <stdlib.h>

#define ElementType  int   //存储数据元素的类型
#define QUEUEMAXSIZE 6     //存储数据元素的最大个数
#define QUEUEERROR   -99   //ElementType的特殊值，标志错误

typedef struct {
    ElementType data[QUEUEMAXSIZE];
    int front; //记录队头元素的位置
    int rear;  //记录队尾元素的位置
    int size;  //记录队列元素的个数
    
}Queue;

// 队列测试
void QueueTest(void);

// 初始化
Queue * InitQueue(void);

// 入队
void AddQueue(Queue *q, ElementType item);

// 出队
ElementType DeleteQueue(Queue *q);

// 打印队列
void PrintQueue(Queue *q);

// 判断队列是否已满
int IsFullQueue(Queue *q);

// 判断队列是否为空
int IsEmptyQueue(Queue *q);

#endif /* Queue_h */
