//
//  LinkStack.h
//  DataStructure
//
//  Created by 刘永杰 on 2018/8/9.
//  Copyright © 2018年 刘永杰. All rights reserved.
//

/*
 
 栈的链式存储结构实际上就是一个单链表，叫做链栈，插入和删除操作只能在链栈的栈顶进行。
 那栈顶指针Top应该在链表的哪一头？我们要插入删除操作，很显然在链头是方便操作的
 
 */

#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>
#include <stdlib.h>

#define ElementType int    // 存储元素的类型
#define ERROR (-99)        // 错误编码

typedef struct Node {
    ElementType data;
    struct Node *next;
}LinkStack;

void LinckStackTest(void);

// 初始化栈
LinkStack *InitLinkStack(void);

// 判断栈是否为空
int IsEmptyLink(LinkStack *s);

// 入栈
void PushLink(LinkStack *s, ElementType data);

// 出栈
ElementType PopLink(LinkStack *s);

// 打印栈
void PrintLinkStack(LinkStack *s);

#endif /* LinkStack_h */
