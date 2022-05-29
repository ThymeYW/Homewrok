# ifndef DEFINITION_H_                // 防止头文件重复引入
# define DEFINITION_H_

#define TRUE 1                        // 状态宏定义 
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#include <stdio.h>

typedef int status;
typedef int ElemType;                 //数据元素类型定义

#define LIST_INIT_SIZE 100            // 初始大小以及增量的宏定义
#define LISTINCREMENT  10

typedef struct LNode{                 //单链表（链式结构）结点的定义
      ElemType data;
      struct LNode *next;
    }LNode,*LinkList;                 //单链表（链式结构）结点的定义


# endif
