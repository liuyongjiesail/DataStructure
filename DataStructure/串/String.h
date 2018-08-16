//
//  String.h
//  DataStructure
//
//  Created by 刘永杰 on 2018/8/8.
//  Copyright © 2018年 刘永杰. All rights reserved.
//

#ifndef String_h
#define String_h

/*
 
 字符串（简称串），可以将其看作是种特殊的线性表，其特殊性在于线性表的数据元素的类型总是字符型，字符串的数据对象约束为字符集。
 串是由0个或多个字符组成的有限序列。一般记作：s = "s1 s2 s3 …… sn"，其中，s是串名，用双引号括起来的字符序列称为串的值，si(1<=i<=n)称为串的元素，可以是字母，数字或者其他字符，是构成串的基本单位，字符的个数n称为串的长度。
 
 1.串的定义：串是由零个或者多个组成的有序队列
 2.串的长度：串中字符的数目称为串的长度
 3.空串：有零个字符组成的串叫做空串，空串不包括任何字符，其长度是零
 4.子串：串中任意个连续的字符组成的子序列称为该串的子串，空串是任何串的子串。
 5.主串：包含子串的串相应的称为主串。
 
 串的表示：
 串有两种表示形式：顺序存储表示和链式存储表示。
 顺序存储表示：串的顺序存储结构简称顺序串，顺序串中的字符序列被顺序地存放在一组连续的存储单元中，主要有三种实现顺序串的的方式。
 
 这里的串和字符串的区别就是字符串会以“\n”终止符来判定字符串的长度，串中我们lenght值就是用来直接记录串的长度
 
 */

#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

typedef struct Str {
    char arr[SIZE];  //arr数组用来存放串的元素
    int length;      //定义一个串的长度
    
}Str;

//测试
void StringTest(void);

//初始化串
Str *InitStr(const char *chars);
//拷贝串
Str *StrCopy(Str *s);
//获取串的长度
int StrLength(Str *s);
//清空串
void Clear(Str *s);
//在串s的pos位置插入串t
bool Insert(Str *s, int pos, Str *t);
//打印串
void PrintStr(Str *s);
//查找子串的位置
int Search(Str *s, Str *sub, int pos);
//从pos位置删除长度为lenght的子串
bool DeleteFromIndexWithLenght(Str *s, int pos, int length);
//从pos位置删除子串substr
bool DeleteFromIndexWihtSubstr(Str *s, int pos, Str *substr);
//字符替换
bool ReplaceFromIndex(Str *s, Str *t, Str *v, int pos);
bool ReplaceAll(Str *s, Str *t, Str *v);

#endif /* String_h */
