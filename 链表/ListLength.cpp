# include "ListLength.h"

int ListLength(LinkList L)
{
    if (L == NULL)                              // 表不存在，不能读取长度！
        return INFEASIBLE;

    int cnt = 0;
    LinkList p = L->next;                       // 从第一个元素开始算！
    while (p){
        cnt ++;
        p = p->next;
    }
    
    return cnt;                                 // 返回结果！
}
