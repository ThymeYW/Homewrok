# include "Init.h"

status InitList(LinkList &L)
{
    if (L != NULL)                            // 若L已经非空，则不能初始化
        return INFEASIBLE;
    
    L = (LinkList)malloc(sizeof(LNode));     // 创建头节点

    L->next = NULL;                          // 头节点的下一个节点设为空

    return OK;

}