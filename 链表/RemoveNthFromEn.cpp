# include "RemoveNthFromEnd.h"

status RemoveNthFromEnd(LinkList& L, int n, int& e){
    if (L == NULL)                       // 链表不存在， 直接返回错误！
        return ERROR;
    
    int len = ListLength(L);         // 进行转化n
    n = len - n + 1;

    return ListDelete(L, n, e);      // 直接调用之前写好的函数
}