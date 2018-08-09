//
//  LinkStack.c
//  DataStructure
//
//  Created by 刘永杰 on 2018/8/9.
//  Copyright © 2018年 刘永杰. All rights reserved.
//

#include "LinkStack.h"

void LinckStackTest() {
    
    LinkStack *s;
    s = InitLinkStack();
    
    PopLink(s);
    
    PrintLinkStack(s);
    
    PushLink(s, 1);
    PushLink(s, 2);
    PushLink(s, 3);
    PushLink(s, 4);
    PushLink(s, 5);

    PrintLinkStack(s);
    
    PopLink(s);
    PopLink(s);

    PrintLinkStack(s);

}

// 初始化栈
LinkStack *InitLinkStack() {
    
    LinkStack *s;
    s = (LinkStack *)malloc(sizeof(LinkStack));
    if (!s) {
        printf("空间不足\n");
    }
    s->next = NULL;
    
    return s;
}

// 判断栈是否为空
int IsEmptyLink(LinkStack *s) {
    return (s->next == NULL);
}

// 入栈
void PushLink(LinkStack *s, ElementType data) {
    LinkStack *cell;
    cell = (LinkStack *)malloc(sizeof(LinkStack));
    if (!cell) {
        printf("空间不足\n");
    }
    cell->data = data;
    cell->next = s->next;
    s->next = cell;
}

// 出栈
ElementType PopLink(LinkStack *s) {
    LinkStack *firstCell;
    ElementType topData;
    if (IsEmptyLink(s)) {
        printf("空栈\n");
        return ERROR;
    }
    firstCell = s->next;        // s最上面元素 赋值给firstCell;
    s->next = firstCell->next;  // firstCell最上面 赋值给s->next;
    topData = firstCell->data;  // firstCell数据 赋值给topData,用于返回值
    free(firstCell);
    
    return topData;
}

// 打印栈
void PrintLinkStack(LinkStack *s) {
    printf("当前栈的元素是：\n");
    LinkStack *p;
    p = s;
    while (p->next != NULL) {
        p = p->next;
        printf("%d\n", p->data);
    }
}
