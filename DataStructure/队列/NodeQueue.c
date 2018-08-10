//
//  NodeQueue.c
//  DataStructure
//
//  Created by 刘永杰 on 2018/8/10.
//  Copyright © 2018年 刘永杰. All rights reserved.
//

#include "NodeQueue.h"

// 链式队列测试
void NodeQueueTest(void) {
    
    NodeQueue *q = InitNodeQueue();
    
    AddNodeQueue(q, 0);
    AddNodeQueue(q, 1);
    AddNodeQueue(q, 2);
    AddNodeQueue(q, 3);
    AddNodeQueue(q, 4);

    PrintNodeQueue(q);
    
    DeleteNodeQueue(q);
    DeleteNodeQueue(q);
    DeleteNodeQueue(q);
    
    PrintNodeQueue(q);
    
    for (ElementType i = 10; i < 20; i++) {
        AddNodeQueue(q, i);
    }
    
    PrintNodeQueue(q);
    
}

// 初始化
NodeQueue * InitNodeQueue(void) {
    NodeQueue *q = (NodeQueue *)malloc(sizeof(NodeQueue));
    if (!q) {
        printf("空间不足\n");
        return NULL;
    }
    
    q->front = NULL;
    q->rear = NULL;
    
    return q;
}

// 入队
void AddNodeQueue(NodeQueue *q, ElementType item) {
    
    QNode *node = (QNode *)malloc(sizeof(QNode));
    if (!node) {
        printf("空间不足\n");
        return;
    }
    node->data = item;
    node->next = NULL;
    if (q->front == NULL) {   //如果对头节点为NULL，优先赋值
        q->front = node;
    }
    if (q->rear == NULL) {    //如果队尾节点为NULL，node也为队尾
        q->rear = node;
    } else {
        q->rear->next = node;  //如果队尾节点不为NULL，队尾的下一个为node
        q->rear = node;        //队尾为node
    }
}

// 出队
ElementType DeleteNodeQueue(NodeQueue *q) {
    if (IsEmptyNodeQueue(q)) {
        printf("空队列\n");
        return NodeQueueError;
    }
    QNode *temp = q->front;
    ElementType item;
    if (q->front == q->rear) {  //如果队列中只有一个元素
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
    }
    item = temp->data;
    free(temp);
    
    return item;
}

// 打印链式队列
void PrintNodeQueue(NodeQueue *q) {
    if (IsEmptyNodeQueue(q)) {
        printf("空队列\n");
        return;
    }
    printf("当前链式队列的元素如下：\n");
    QNode *node = q->front;
    while (node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

// 判空处理
int IsEmptyNodeQueue(NodeQueue *q) {
    return (q->front == NULL);
}
