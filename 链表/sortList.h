# ifndef SORTLIST_H_                // 防止头文件重复引入
# define SORTLIST_H_

# include "Definition.h"
# include "ListLength.h"

status sortList(LinkList);   // 函数声明
void quickSort(ElemType[], int, int);
# endif