# include "Clear.h"
 
status ClearList(LinkList &L)
{
    if (L == NULL || L->next == NULL)        // 表不存在不能清空, 表为空也不能清空！
        return INFEASIBLE;
    
    LinkList p = L->next;                   // 将从表的第一个元素开始清空！
    while (p){
        LinkList tmp = p->next;
        free(p);
        p = tmp;
    }

    L->next = NULL;                         //  清空操作不能删除表头结点！
    return OK;
}
