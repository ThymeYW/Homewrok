# include "PriorElem.h"

status PriorElem(LinkList L,ElemType e,ElemType &pre)
{
    if (L == NULL)                        // 链表不存在， 直接返回错误！
        return INFEASIBLE;

    if (L->next && L->next->data == e)
        return ERROR;

    int flag = 0;
    LinkList p = L->next;
    while (p && p->next){                // 移动指针定位元素！
        if (p->next->data == e){
            flag = 1;
            pre = p->data;
            return OK;
        }
        p = p->next;
    }

    if (flag == 0){
        return -11;
    }

    return ERROR;

}