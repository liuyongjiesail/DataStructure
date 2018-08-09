//
//  Stack.h
//  DataStructure
//
//  Created by 刘永杰 on 2018/8/8.
//  Copyright © 2018年 刘永杰. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

/*
 栈（Stack）又名堆栈，它是一种运算受限的线性表。
 1.仅允许在表的一端进行插入和删除运算。这一端被称为栈顶，相对地，把另一端称为栈底。
 2.向一个栈插入新元素称为进栈、入栈或压栈，它是把新元素放到栈顶元素的上面，使之成为新的栈顶元素。
 3.从一个栈删除元素又称为出栈或退栈，它是把栈顶元素删除掉，使其相邻的元素成为新的栈顶元素。
 
 栈的顺序存储结构通常由一个一维数组和一个记录栈顶元素位置的变量组成。
 */

#include <stdio.h>

#define ElementType int    //存储元素的类型
#define MAXSIZE 1024       //存储元素的最大个数
#define ERROR (-99)        //ElementType的特殊值，标志错误

typedef struct {
    ElementType data[MAXSIZE];
    int top;
}Stack;

#pragma mark - 栈的数组实现

// 栈测试
void StackTest(void);

// 初始化栈
Stack *InitStack(void);

// 栈是否已满
int IsFull(Stack *stack);

// 栈是否为空
int IsEmpty(Stack *stack);

// 入栈
void Push(Stack *stack, ElementType item);

// 出栈
ElementType Pop(Stack *stack);

// 返回栈顶元素
ElementType Peek(Stack *stack);

// 打印栈
void PrintStack(Stack *stack);

// 销毁栈
int DestroyStack(Stack *stack);

#endif /* Stack_h */
