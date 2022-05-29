# include "ListInsert.h"

status ListInsert(LinkList &L,int i,ElemType e)
{
    if (L == NULL)                    //链表不存在，直接走！
        return INFEASIBLE;
    
    if (i < 1)                       // 下标错误！
        return ERROR;

    int index = 1;
    LinkList p = L;
    while (p && index < i){
        p = p->next;
        index ++;                     // 定位指针！
    }
    
    if (p == NULL)                     // 没有找到元素！
        return ERROR;

    if (p->next == NULL){                       // 进行判断是否为尾巴节点选择插入方式
        p->next = (LinkList)malloc(sizeof(LNode));
        p = p->next;
        p->data = e;
        p->next = NULL;
    }else{
        LinkList tmp = (LinkList)malloc(sizeof(LNode));
        tmp->data = e;
        tmp->next = p->next;
        p->next = tmp;
    }
    return OK;
}
