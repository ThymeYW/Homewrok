# include "saveandload.h"

status SaveList(LinkList L,char FileName[])
{
    if (L == NULL)                       // 链表不存在， 直接返回错误！
        return INFEASIBLE;
    
    FILE* fp = NULL;                        // 打开文件！
    fp = fopen(FileName, "wb");
    if (fp == NULL)                      // 打开错误！
        return ERROR;
    
    LinkList p = L->next;
    while (p){                            // 移动指针， 存储！
        fwrite(&p->data, sizeof(ElemType), 1, fp);
        p = p->next;
    }
    fclose(fp);

    return OK;

}

status LoadList(LinkList &L,char FileName[])
{
    if (L != NULL && L->next != NULL)      // 链表不存且不为空， 直接返回错误！
        return INFEASIBLE;
    
    FILE* fp = NULL;                   // 打开文件！
    fp = fopen(FileName, "rb");
    if (fp == NULL)
        return ERROR;                   // 打开错误！
    
    free(L);
    L = NULL;
    L = (LinkList)malloc(sizeof(LNode));
    LinkList tail = L;
    while (fgetc(fp) != EOF){                   // 判断是否到达文件尾！
        fseek(fp, -1, SEEK_CUR);
        
        LinkList tmp = (LinkList)malloc(sizeof(LNode));
        fread(&tmp->data, sizeof(ElemType), 1, fp);
        tail->next = tmp;
        tail = tmp;
    }
    tail->next = NULL;
    fclose(fp);                         // 关闭文件！
    return OK;

}
