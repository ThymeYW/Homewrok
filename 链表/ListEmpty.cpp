# include "ListEmpty.h"

status ListEmpty(LinkList L)
{
    if (L == NULL)                          // 表不存在，不能判断！
        return INFEASIBLE;

    return L->next == NULL;                 // 表是空的意味着头节点的下一个节点是空！

}
