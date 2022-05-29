# include "reverseList.h"

status reverseList(LinkList& L){
    if (L == NULL)                       // 链表不存在， 直接返回错误！
        return INFEASIBLE;

    if (L->next == NULL)               // 空链表不需要反转！
        return OK;

    LinkList p = L, tmp = p->next;

    while (p && tmp){                 // 移动指针并反转！
        LinkList tmpp = tmp->next;
        if (p != L)
            tmp->next = p;
        else
            tmp->next = NULL;
        p = tmp;
        tmp = tmpp;
    }

    L->next = p;
    
    return OK;
}