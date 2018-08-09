//
//  Stack.c
//  DataStructure
//
//  Created by 刘永杰 on 2018/8/8.
//  Copyright © 2018年 刘永杰. All rights reserved.
//

#include "Stack.h"
#include <stdlib.h>

void StackTest(void) {
    
    Stack *stack;
    stack = InitStack();
    
    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    Push(stack, 4);
    Push(stack, 5);
    
    PrintStack(stack);
    
    Pop(stack);
    Pop(stack);
    
    PrintStack(stack);
    
    printf("%d\n",Peek(stack));
    printf("%d\n",Peek(stack));
    
    PrintStack(stack);
    
    DestroyStack(stack);
        
    PrintStack(stack);
    
}

// 初始化栈
Stack *InitStack() {
    Stack *stack;
    stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) {
        printf("空间不足\n");
        return NULL;
    }
    stack->top = -1;
    return stack;
}

// 栈是否已满
int IsFull(Stack *stack) {
    if (stack->top == MAXSIZE - 1) {
        printf("栈已满\n");
        return 1;
    }
    return 0;
}

// 栈是否为空
int IsEmpty(Stack *stack) {
    if (stack->top == -1) {
        printf("栈为空\n");
        return 1;
    }
    return 0;
}

// 入栈
void Push(Stack *stack, ElementType item) {
    if (IsFull(stack)) {
        return;
    }
    stack->data[++stack->top] = item;
}

// 出栈
ElementType Pop(Stack *stack) {
    if (IsEmpty(stack)) {
        return ERROR;
    }
    return stack->data[stack->top--];
}

// 返回栈顶元素
ElementType Peek(Stack *stack) {
    if (IsEmpty(stack)) {
        return ERROR;
    }
    return stack->data[stack->top];
}

// 打印栈
void PrintStack(Stack *stack) {
    int i;
    for (i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

// 销毁栈
int DestroyStack(Stack *stack) {
    if (stack) {
        free(stack);
        stack = NULL;
        printf("栈已销毁\n");
    }
    return 0;
}

