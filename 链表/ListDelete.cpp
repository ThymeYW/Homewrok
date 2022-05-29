# include "ListDelete.h"

status ListDelete(LinkList &L,int i,ElemType &e)
{
    if (L == NULL)                    // 链表不存在，不能够删除
        return INFEASIBLE;
    
    if (i < 1)                        // 下标错误！
        return ERROR;

    int index = 1;
    LinkList p = L;
    while (p && index < i){
        p = p->next;
        index ++;
    }
    
    if (p == NULL || p->next == NULL)  // 找不到元素!
        return ERROR;

    e = p->next->data;
    LinkList tmp = p->next;
    p->next = tmp->next;
    free(tmp);
    
    return OK;
}
