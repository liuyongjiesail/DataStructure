//
//  String.c
//  DataStructure
//
//  Created by 刘永杰 on 2018/8/8.
//  Copyright © 2018年 刘永杰. All rights reserved.
//

#include "String.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void StringTest() {
    
    Str *s = InitStr("abcdefghijab");
    
    PrintStr(s);
    
    Str *t = StrCopy(s);
    
    PrintStr(t);
    
    printf("s->length:%d\n", StrLength(s));
    printf("t->length:%d\n", StrLength(t));
    
    Clear(t);
    
    PrintStr(t);
    
    Str *subStr = InitStr("ij");
    
    printf("subStr->index:%d\n", Search(s, subStr, 0));
    
    Insert(s, 12, subStr);
    
    PrintStr(s);
    
    DeleteFromIndexWithLenght(s, 0, 2);
    
    PrintStr(s);
    
    DeleteFromIndexWihtSubstr(s, 0, subStr);
    
    PrintStr(s);
    
    ReplaceFromIndex(s, subStr, InitStr("c"), 0);
    
    PrintStr(s);
    
    ReplaceAll(s, InitStr("g"), subStr);
    
    PrintStr(s);
}

//初始化串
Str *InitStr(const char *chars) {
    Str *s = malloc(sizeof(Str));
    int len = (int)strlen(chars);
    s->length = len;
    for (int i = 0; i < len; i++) {
        s->arr[i] = chars[i];
    }
    return s;
}

//拷贝串
Str *StrCopy(Str *s) {
    Str *result = malloc(sizeof(Str));
    for (int i = 0; i < s->length; i++) {
        result->arr[i] = s->arr[i];
    }
    result->length = s->length;
    return result;
}

//获取串的长度
int StrLength(Str *s) {
    return s->length;
}

//清空串
void Clear(Str *s) {
    s->length = 0;
}

//在串s的pos位置插入串t
bool Insert(Str *s, int pos, Str *t) {
    assert(s != NULL);
    assert(t != NULL);
    if (pos < 0 || pos > StrLength(s) || pos + StrLength(t) > SIZE) {
        return false;
    }
    for (int i = StrLength(s) - 1; i >= pos; i--) {
        s->arr[i+StrLength(t)] = s->arr[i];
    }
    for (int j = 0; j < StrLength(t); j++) {
        s->arr[j+pos] = t->arr[j];
    }
    s->length += t->length;
    return true;
}

//打印串
void PrintStr(Str *s) {
    for (int i = 0; i < StrLength(s); i++) {
        printf("%c", s->arr[i]);
    }
    printf("\n");
}

//查找子串的位置
int Search(Str *s, Str *sub, int pos) {
    if (pos < 0 || pos > StrLength(s)) {
        return -1;
    }
    int i = pos;
    int j = 0;
    
    int lens = StrLength(s);
    int lensub = StrLength(sub);
    
    while (i < lens && j < lensub) {
        if (s->arr[i] == sub->arr[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= lensub) {
        return i - j;
    } else {
        return -1;
    }
}

//从pos位置删除长度为lenght的子串
bool DeleteFromIndexWithLenght(Str *s, int pos, int length) {
    assert(s != NULL);
    if (pos < 0 || pos + length > StrLength(s) || length < 0) {
        return false;
    }
    for (int i = pos; i < StrLength(s) - length; i++) {
        s->arr[i] = s->arr[i+length];
    }
    s->length -= length;
    return true;
}

//从pos位置删除子串substr
bool DeleteFromIndexWihtSubstr(Str *s, int pos, Str *substr) {
    assert(s != NULL);
    assert(substr != NULL);
    if (pos < 0 || pos > StrLength(s) || StrLength(substr) > StrLength(s)) {
        return false;
    }
    int index = Search(s, substr, pos);
    if (index < 0) {
        return false;
    }
    return DeleteFromIndexWithLenght(s, index, StrLength(substr));
}

//字符替换
bool ReplaceFromIndex(Str *s, Str *t, Str *v, int pos) {
    assert(s != NULL);
    assert(t != NULL);
    assert(v != NULL);
    
    int index = Search(s, t, pos);
    if (index < 0) {
        return false;
    }
    DeleteFromIndexWithLenght(s, index, StrLength(t));
    return Insert(s, index, v);
}

bool ReplaceAll(Str *s, Str *t, Str *v) {
    assert(s != NULL);
    assert(t != NULL);
    assert(v != NULL);
    while (ReplaceFromIndex(s, t, v, 0));
    return true;
}
