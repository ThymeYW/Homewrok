# include "sortList.h"

void quickSort(ElemType arr[], int i, int j){       // 快速排序！
    if (i >= j)
        return;

    int low = i;
    int high = j;
    ElemType k = arr[low];
    
    while (low < high){
        while (low < high && k <= arr[high]){
            high --;
        }

        if (low < high && k > arr[high]){
            arr[low] = arr[high];
            low ++;
        }

        while (low < high && k >= arr[low]){
            low ++;
        }

        if (low < high && k < arr[low]){
            arr[high] = arr[low];
            high --;
        }
    }
    arr[low] = k;

    quickSort(arr, i, low-1);                      // 递归进行快速排序！
    quickSort(arr, low+1, j);
}

status sortList(LinkList L){
    if (L == NULL)                       // 链表不存在， 直接返回错误！
        return INFEASIBLE;
    
    if (L ->next == NULL)                       // 链表为空， 直接返回OK！
        return OK;

    int len = ListLength(L);
    ElemType arr[len];
    LinkList p = L->next;
    
    for (int i = 0; i < len; p = p->next, i++){
        arr[i] = p->data;
    }

    quickSort(arr, 0, len-1);                // 数组排序！

    p = L->next;

    for (int i = 0; i < len; p = p->next, i++){
        p->data = arr[i];
    }

    return OK;
}