# include "Def.h"

status InitList(SqList& L)
{
    if (L.elem != NULL)       // 线性表已存在，不能初始化！          
        return INFEASIBLE;
    
    L.elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);    // 分配元素空间。

    if (L.elem == NULL)              // 分配失败！返回错误信息。
        return FALSE;
    
    L.listsize = LIST_INIT_SIZE;     // 初始化链表空间长度。
    L.length = 0;                    // 初始化链表元素长度。

    return OK;                       // 初始化完成！返回OK。

}

status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if (L.elem == NULL)                   // 线性表未初始化，不能销毁！
        return INFEASIBLE;
    
    free(L.elem);                         // 将空间释放掉！
    L.elem = NULL;                        // 将其设置为空指针！
    L.listsize = 0;                       // 将表长以及元素个数的参数设置为零！
    L.length = 0;

    return OK;                            // 执行完成返回OK！

}

status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if (L.elem == NULL)                // 线性表不存在，不可清空！
        return INFEASIBLE;

    L.length = 0;                      // 将元素个数设置为0！

    return OK;                         // 清空完成，返回OK！
}

status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem == NULL)                 // 线性表不存在，返回不可执行的信息！
        return INFEASIBLE;   
    
    if (L.length == 0)                  // 线性表长度为零，返回TRUE！
        return TRUE;
    
    if (L.length != 0)                  // 线性表长度不为零，线性表非空，返回FALSE！
        return FALSE;

    return -1;

}

status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if (L.elem == NULL)               // 线性表不存在，返回不可执行的信息！
        return INFEASIBLE;

    return L.length;                  // 返回表长！
}

status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem == NULL)         // 线性表不存在，返回不可执行的信息！
        return INFEASIBLE;
    
    if (i < 1 || i > L.length)  // 位置i不正确，返回错误信息！
        return ERROR;
    
    e = L.elem[i-1];            // 将位置i的元素赋值给e，由于数组下标是从零开始，故需返回第i-1号元素！

    return OK;                  // 执行完成，返回正确信息！

}

int LocateElem(SqList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    if (L.elem == NULL)         // 线性表不存在，返回不可执行的信息！
        return INFEASIBLE;
    
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e)
            return i+1;
    
    return ERROR;
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem == NULL)         // 线性表不存在，返回不可执行的信息！
        return INFEASIBLE;
    
    for (int i = 1; i < L.length; i++)
        if (L.elem[i] == e){
            pre = L.elem[i-1];
            return OK;
        }

    return ERROR;

}

status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem == NULL)         // 线性表不存在，返回不可执行的信息！
        return INFEASIBLE;
    
    for (int i = 0; i < L.length-1; i++)
        if (L.elem[i] == e){
            next = L.elem[i+1];
            return OK;
        }

    return ERROR;

}

status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem == NULL)         // 线性表不存在，返回不可执行的信息！
        return INFEASIBLE;
    
    //printf("%d %d", i, L.length);
    if (i < 1 || i > L.length+1)      // 位置信息不正确！
        return ERROR;

    if (L.length >= L.listsize){
        L.elem = (ElemType*)realloc(L.elem, sizeof(ElemType)*(L.listsize + LISTINCREMENT));
        if (L.elem == NULL)
            return ERROR;
        L.listsize += LISTINCREMENT;
    }
    
    for (int j = L.length; j >= i; j--){
        L.elem[j] = L.elem[j-1];
    }
    L.elem[i-1] = e;
    L.length ++;
    return OK;

}

status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem == NULL)         // 线性表不存在，返回不可执行的信息！
        return INFEASIBLE;
    
    if (i < 1 || i > L.length)      // 位置信息不正确！
        return ERROR;
    
    e = L.elem[i-1];
    for (int j = i; j < L.length; j++){
        L.elem[j-1] = L.elem[j];
    }
    L.length --;
    return OK;

}

status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem == NULL)         // 线性表不存在，返回不可执行的信息！
        return INFEASIBLE;
    
    for (int i = 0; i < L.length; i++){
        printf("%d", L.elem[i]);
        // if (i != L.length-1)
            putchar(' ');
    }
    return OK;
}

ElemType MaxSubArray(SqList L){
    int len = ListLength(L);

    if (len == 0){
        return 0;
    }

    int f[len];                                         // f[i] 表示以第i个元素结尾的最大子数组和
    f[0] = L.elem[0];
    ElemType max = f[0];
    for (int i = 1; i < len; i++){
        f[i] = Max(f[i-1] + L.elem[i], L.elem[i]);
        max = Max(f[i], max);
    }

    return max;
}

int SubArrayNum(SqList L, int k, int& cnt){
    if (L.elem == NULL){
        return INFEASIBLE;
    }

    cnt = 0;
    for (int i = 1; i < L.length; i++){
        L.elem[i] += L.elem[i-1];
    }

    for (int i = 0; i < L.length; i++){
       if (L.elem[i] == k)
            cnt ++;
    }

    for (int i = 0; i < L.length-1; i++){
        for (int j = i+1; j < L.length; j++){
            if (L.elem[j] - L.elem[i] == k)
                cnt ++;
        }
    }

    return OK;
    
}

void quickSort(ElemType arr[], int i, int j){           // 快速排序算法!
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

    quickSort(arr, i, low-1);
    quickSort(arr, low+1, j);
}

status sortList(SqList& L){
    if (L.elem == NULL)         // 线性表不存在，返回不可执行的信息！
        return INFEASIBLE;

    int len = ListLength(L);
    if (len == 0 || len == 1){
        return OK;
    }

    quickSort(L.elem, 0, len-1);

    return OK;
}


status  SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem == NULL)         // 线性表不存在，返回不可执行的信息！
        return INFEASIBLE;
    
    FILE* fp = fopen(FileName, "wb");
    if (fp == NULL)                         // 文件打开错误！
        return ERROR;
    
    for (int i = 0; i < L.length; i++){
        //printf("%d ", L.elem[i]);
        fwrite(L.elem+i, sizeof(ElemType), 1, fp);
    }

    fclose(fp);
    
    return OK;

    /********** End **********/
}
status  LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{   
    if (L.elem != NULL && L.length != 0)         // 线性表不存在或线性表不为空，返回不可执行的信息！
        return INFEASIBLE;

    free(L.elem);
    L.elem = NULL;

    L.elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    if (L.elem == NULL){
        printf("memory allocation error!\n");
        return ERROR;
    }
    
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;

    FILE* fp = fopen(FileName, "rb");
    if (fp == NULL){            // 文件打开错误！
        printf("open erro!r\n");
        return ERROR;
    }
    
    while (!feof(fp)){

        if (L.length >= L.listsize){
            L.elem = (ElemType*)realloc(L.elem, sizeof(ElemType)*(L.listsize+LISTINCREMENT));
            if (L.elem == NULL){
                fclose(fp);
                printf("memory allocation error!\n");
                return ERROR;
            }
            L.listsize += LISTINCREMENT;
        }
        if (fread(L.elem+L.length, sizeof(ElemType), 1, fp))
            L.length ++;
    }
    fclose(fp);
    return OK;

}


status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表
{
    if (Lists.length == 50)         // 线性表们已经满了，返回不可执行的信息！
        return ERROR;
        
    Lists.elem[Lists.length].L.elem = NULL;
    Lists.elem[Lists.length].L.length = 0;
    Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;
    
    // printf("input a list ended with 0!\n");
    // int tmp; 
    // scanf("%d", &tmp);
    // while(tmp != 0){
    //     if (Lists.elem[Lists.length].L.length >= Lists.elem[Lists.length].L.listsize){
    //         Lists.elem[Lists.length].L.elem = (ElemType*)realloc(Lists.elem[Lists.length].L.elem, sizeof(ElemType)*(Lists.elem[Lists.length].L.listsize += LISTINCREMENT));
    //         if (Lists.elem[Lists.length].L.elem == NULL){
    //             printf("memory allocation error!\n");
    //             return ERROR;
    //         }
    //     }
    //     Lists.elem[Lists.length].L.elem[Lists.elem[Lists.length].L.length++] = tmp;
    //     scanf("%d", &tmp);
    // }

    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.length ++;

    return OK;
}


status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    for (int i = 0; i < Lists.length; i ++){
        if (!strcmp(Lists.elem[i].name, ListName)){
            free (Lists.elem[i].L.elem);
            for (int j = i+1; j < Lists.length; j++){
                Lists.elem[j-1] = Lists.elem[j];
            }
            Lists.length --;
            return OK;
        }
    }
    
    return ERROR;

}


int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    for (int i = 0; i < Lists.length; i ++){
        if (!strcmp(Lists.elem[i].name, ListName)){
            return i;
        }
    }
    return -1;
}

void showMenu(){                 // 显示菜单！
    printf("=============================================MENU=========================================================\n"
           "0 : Show this menu\n"
           "1 : Initialize your list                     2 : Destroy your list\n"
           "3 : Clear your list                          4 : Make sure if your list is empty\n"
           "5 : Get the length of your lists             6 : Get one particular element\n"
           "7 : Find the index of a particular element   8 : Get the prior of one element\n"
           "9 : Get the next of one element              10: Insert element\n"
           "11: Delete element                           12: Traverse your list\n"
           "13: Get the maxsubarray's sum                14: Get the amount of subarrays whose sum equals to an integer\n"
           "15: Sort your list                           16: Save your list in a file\n"
           "17: Load your list from a file               18: Add some elements to your list\n"
           "19: Add a list to your lists                 20: Remove a list in your lists\n"
           "21: Get a list from your lists               22: Quit\n"
           "=============================================MENU==========================================================\n"
           "\n");
}









