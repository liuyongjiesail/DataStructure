//
//  NodeQueue.h
//  DataStructure
//
//  Created by 刘永杰 on 2018/8/10.
//  Copyright © 2018年 刘永杰. All rights reserved.
//

#ifndef NodeQueue_h
#define NodeQueue_h

/*
 队列的链式存储结构也可以用一个单链表实现。插入和删除操作分别在链表的两头进行。队列指针front指向链表头部方便删除操作，队列指针rear指向链表尾部方便插入操作。
 */

#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define NodeQueueError -99

typedef struct{   //链表节点
    ElementType data;  //数据
    struct Node *next; //指向下一个
}QNode;

typedef struct {       //队列
    QNode *front;  //指向对头节点
    QNode *rear;   //指向队尾节点
}NodeQueue;

// 链式队列测试
void NodeQueueTest(void);

// 初始化
NodeQueue * InitNodeQueue(void);

// 入队
void AddNodeQueue(NodeQueue *q, ElementType item);

// 出队
ElementType DeleteNodeQueue(NodeQueue *q);

// 打印链式队列
void PrintNodeQueue(NodeQueue *q);

// 判空处理
int IsEmptyNodeQueue(NodeQueue *q);

#endif /* NodeQueue_h */
