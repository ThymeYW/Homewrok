# include "Destroy.h"

status DestroyList(LinkList &L)
{

    if (L == NULL)                              // 表是空的不能销毁
        return INFEASIBLE;

    LinkList p = L->next;                       // 从第一个元素开始销毁
    while (p != NULL){
        LinkList tmp = p->next;
        free(p);
        p = tmp;
    }

    free(L);                                    // 将表头节点销毁后设置为空
    L = NULL;
    return OK;
}
