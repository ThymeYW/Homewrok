# include "ListTraverse.h"

status ListTraverse(LinkList L)
{
    if (L == NULL)               // 链表不存在，返回错误信息！
        return INFEASIBLE;

    LinkList p = L->next;

    while (p){                   // 移动指针！
        printf("%d", p->data);
        // if (p->next != NULL)
            putchar(' ');
        p = p->next;
    }
    return OK;

}