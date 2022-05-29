# ifndef DEF_H_
# define DEF_H_

# include <malloc.h>                                  // 头文件引入
# include <stdio.h>
# include <string.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

# define Max(x, y) ((x) > (y) ? (x) : (y))           // 宏定义Max函数;

typedef int status;
typedef int ElemType;                                //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct{                                      //顺序表（顺序结构）的定义
	      ElemType * elem;
	      int length;
	      int listsize;
         }SqList;

typedef struct{                                      //线性表的管理表定义
     struct { char name[30];
     		  SqList L;	
      } elem[50];
      int length;
      int listsize;
 }LISTS;

status InitList(SqList& );                           // 函数声明
status DestroyList(SqList& );
status ClearList(SqList& );
status ListEmpty(SqList );
status ListLength(SqList );
status GetElem(SqList ,int ,ElemType &);
int LocateElem(SqList ,ElemType );
status PriorElem(SqList ,ElemType ,ElemType &);
status NextElem(SqList ,ElemType ,ElemType &);
status ListInsert(SqList &,int ,ElemType );
status ListDelete(SqList &,int ,ElemType &);
status ListTraverse(SqList );
status  SaveList(SqList ,char []);
status  LoadList(SqList &,char []);
ElemType MaxSubArray(SqList);
int SubArrayNum(SqList, int, int &);
status sortList(SqList&);
void quickSort(ElemType [], int , int );
status AddList(LISTS &,char []);
status RemoveList(LISTS &,char []);
int LocateList(LISTS ,char []);
void showMenu();

# endif