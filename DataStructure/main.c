//
//  main.c
//  DataStructure
//
//  Created by 刘永杰 on 2018/8/8.
//  Copyright © 2018年 刘永杰. All rights reserved.
//

#include <stdio.h>
#include "Stack.h"
#include "LinkStack.h"
#include "Queue.h"
#include "NodeQueue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    //顺序栈
    StackTest();
    //链栈
    LinckStackTest();
    
    //顺序队列
    QueueTest();
    //链式队列
    NodeQueueTest();
    
    return 0;
}
