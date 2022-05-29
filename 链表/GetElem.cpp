# include "GetElem.h"

status GetElem(LinkList L,int i,ElemType &e)
{

    if (L == NULL)                      //链表不存在，不可以操作！
        return INFEASIBLE;
    
    int length = ListLength(L);

    if (i < 1 || i > length)            // 判断序号是否正确
        return ERROR;
    
    LinkList p = L;

    while (i--){                       // 移动定位指针
        p = p->next;
    }

    e = p->data;

    return OK;
}
