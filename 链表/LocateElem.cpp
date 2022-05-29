# include "LocateElem.h"

status LocateElem(LinkList L,ElemType e)
{

    if (L == NULL)                      // 链表不存在！返回错误信息！
        return INFEASIBLE;

    LinkList p = L->next;
    int index = 1;
    while (p){                          // 移动指针查找元素！
        if (p->data == e)
            return index;
        index ++;
        p = p->next;
    }
    return ERROR;
}
