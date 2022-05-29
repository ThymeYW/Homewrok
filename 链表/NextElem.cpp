# include "NextElem.h"

status NextElem(LinkList L,ElemType e,ElemType &next)
{
    if (L == NULL)                             // 链表不存在，直接返回错误！
        return INFEASIBLE;

    int flag = 0;
    LinkList p = L->next;
    while (p && p->next){                     // 移动指针定位元素！
        if (p->data == e){
            flag = 1;
            next = p->next->data;
            return OK;
        }
        p = p->next;
    }

    if (p->next == NULL && p->data == e)
        return ERROR;

    if (flag == 0)
        return -11;

    return ERROR;

}
