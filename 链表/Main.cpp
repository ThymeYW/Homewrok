# include <stdio.h>
# include "Definition.h"
# include "Init.h"
# include "Destroy.h"
# include "LocateElem.h"
# include "NextElem.h"
# include "PriorElem.h"
# include "ListInsert.h"
# include "ListTraverse.h"
# include "reverseList.h"
# include "RemoveNthFromEnd.h"
# include "sortList.h"
# include "saveandload.h"
# include "Clear.h"
# include "ListEmpty.h"
# include "GetElem.h"
# include "Lists.h"
# include "ListDelete.h"
# include "ListLength.h"

void showMenu(){
    printf("========================================MENU===================================================\n"
           "0 : Show this menu\n"
           "1 : Initialize your list                     2 : Destroy your list\n"
           "3 : Clear your list                          4 : Make sure if your list is empty\n"
           "5 : Get the length of your lists             6 : Get one particular element\n"
           "7 : Find the index of a particular element   8 : Get the prior of one element\n"
           "9 : Get the next of one element              10: Insert element\n"
           "11: Delete element                           12: Traverse your list\n"
           "13: Reverse your list                        14: Delete one element from the end of your list\n"
           "15: Sort your list                           16: Save your list in the file\n"
           "17: Load your list from a file               18: Add some elements to your list\n"
           "19: Add a list to your lists                 20: Locate a list in your lists\n"
           "21: Remove a list from your lists            22: Quit\n"
           "========================================MENU===================================================\n"
           "\n");
}

int main(){
   
    int tmp;
    int choice, e, i, index, pre, next;           // 用到的变量声明！
    Lists lists;
    // LinkList L = NULL;
    int nowIndex = 0, listIndex = -1;                     
    initLists(lists);                                // 多链表初始化！
    LinkList tmpl = NULL, tailOftmpl;   
    status sta;\
    char listName[20];
    char f[100];

    printf("you must add a list before your operation!\n");

    // 进行信息提示！    

    
    showMenu();            // 先展示一次菜单！
    printf("MAKE YOUR CHOICE!\n");
    while(true){
        scanf("%d", &choice);            // 用switch—case语句进行选择！
        switch(choice){
            case 0:
                showMenu();
                break;
            case 1:                                                // 功能1
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = InitList(lists.list[nowIndex]);
                lists.listTail[nowIndex] = lists.list[nowIndex];

                if (sta == OK){
                    printf("OK!\n");
                }else{
                    printf("this list can not be initialized!\n");
                }
                break;
            case 2:                                               // 功能2

                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                if (lists.list[nowIndex] == NULL){
                    printf("this list hasn't been initialized!\n");
                    break;
                }
                sta = DestroyList(lists.list[nowIndex]);
                if (sta == OK){
                    printf("OK!\n");
                }else{
                    printf("this list can not be Destroyed!\n");
                }
                break;
            case 3:                                               // 功能3
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                if (lists.list[nowIndex] == NULL){
                    printf("this list hasn't been initialized!\n");
                    break;
                }
                sta = ClearList(lists.list[nowIndex]);
                if (sta == OK){
                    printf("OK!\n");
                }else{
                    printf("this list can not be cleared!\n");
                }
                break;
            case 4:                                               // 功能4
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = ListEmpty(lists.list[nowIndex]);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta == true){
                    printf("this list is empty!\n");
                }else{
                    printf("this list is not empty!\n");
                }
                break;
            case 5:                                               // 功能5
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = ListLength(lists.list[nowIndex]);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else{
                    printf("this list's length = %d!\n", sta);
                }
                break;
            case 6:                                               // 功能6
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input the index of the element in the list!\n");
                scanf("%d", &index);
                sta = GetElem(lists.list[nowIndex],index,e);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this index does not exist in the list!\n");
                }else{
                    printf("you get it : %d!\n", e);
                }
                break;
            case 7:                                               // 功能7
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input the element you want to find in the list!\n");
                scanf("%d", &e);
                sta = LocateElem(lists.list[nowIndex],e);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this element does not exist in the list!\n");
                }else{
                    printf("you get its index : %d!\n", sta);
                }
                break;
            case 8:                                               // 功能8
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input the element whose prior element you want to find in the list!\n");
                scanf("%d", &e);
                sta = PriorElem(lists.list[nowIndex],e,pre);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this prior does not exist in the list!\n");
                }else if (sta != -11){
                    printf("you get its prior one : %d!\n", pre);
                }else{
                    printf("this element does not exist in the list!\n");
                }
                break;
            case 9:                                               // 功能9
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input the element whose next element you want to find in the list!\n");
                scanf("%d", &e);
                sta = NextElem(lists.list[nowIndex],e,next);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this next does not exist in the list!\n");
                }else if (sta != -11){
                    printf("you get its next one : %d!\n", next);
                }else{
                    printf("this element does not exist in the list!\n");
                }
                break;
            case 10:                                               // 功能10

                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                if (lists.list[nowIndex] == NULL){
                    printf("this list hasn't been initialized!\n");
                    break;
                }
                printf("input the element you want to insert in the list!\n");
                scanf("%d", &e);
                printf("input the index you want to insert in the list!\n");
                int index;
                scanf("%d", &index);
                sta = ListInsert(lists.list[nowIndex],index,e);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this index does not exist in the list!\n");
                }else{
                    printf("OK!\n");
                }
                break;
            case 11:                                               // 功能11
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                if (lists.list[nowIndex] == NULL){
                    printf("this list hasn't been initialized!\n");
                    break;
                }
                printf("input the index you want to delete in the list!\n");
                scanf("%d", &index);
                sta = ListDelete(lists.list[nowIndex],index,e);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this index does not exist in the list!\n");
                }else{
                    printf("you have deleted %d\n", e);
                }
                break;
            case 12:                                               // 功能12
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = ListTraverse(lists.list[nowIndex]);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else{
						if (lists.list[nowIndex]->next == NULL){
								printf("this list is empty!\n");
								break;
						}
                    printf("OK!\n");
                }
                break;
            case 13:                                               // 功能13
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = reverseList(lists.list[nowIndex]);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else{
                    printf("OK!\n");
                }
                break;
            case 14:                                               // 功能14
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                if (lists.list[nowIndex] == NULL){
                    printf("this list hasn't been initialized!\n");
                    break;
                }
                printf("input the index (from the bottom) you want to delete in the list!\n");
                scanf("%d", &index);
                sta = RemoveNthFromEnd(lists.list[nowIndex],index, e);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this index does not exist in the list!\n");
                }else{
                    printf("you have deleted %d\n", e);
                }
                break;
            case 15:                                               // 功能15
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = sortList(lists.list[nowIndex]);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else{
                    printf("OK!\n");
                }
                break;
            case 16:                                               // 功能16
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input the filename where you want to save the list!\n");
                scanf("%s", f);
                sta = SaveList(lists.list[nowIndex], f);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta == ERROR){
                    printf("open error!\n");
                }else{
                    printf("OK!\n");
                }
                break;
            case 17:                                               // 功能17
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input the filename where you want to load the list!\n");
                scanf("%s", f);
                sta = LoadList(lists.list[nowIndex], f);
                if (sta == INFEASIBLE){
                    printf("this list isn't empty so you can't load anything onto it!\n");
                }else if (sta == ERROR){
                    printf("open error!\n");
                }else{
                    printf("OK!\n");
                }
                break;
            case 18:                            //添加一串元素;
                                                               // 功能18
                if (lists.length == 0){
                    printf("you have no list, please add a new list to your lists!\n");
                    break;
                }

                printf("choose a list to operate, input its name!\n");
                scanf("%s", listName);
                nowIndex = getList(lists, listName);
                if (nowIndex == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                if (lists.list[nowIndex] == NULL){
                    printf("this list hasn't been initialized!\n");
                    break;
                }

                printf("input a list ended with 0!\n");
                
                tmpl = (LinkList)malloc(sizeof(LNode));
                tailOftmpl = tmpl;
                scanf("%d", &tmp);
                while(tmp != 0){
                    LinkList p = (LinkList)malloc(sizeof(LNode));
                    p->data = tmp;
                    tailOftmpl->next = p;
                    tailOftmpl = p;
                    scanf("%d", &tmp);
                }
                tailOftmpl->next = NULL;
                lists.listTail[nowIndex]->next = tmpl->next;
                lists.listTail[nowIndex] = tailOftmpl;
                free(tmpl);
                printf("OK!\n");
                break;
            case 19:                                               // 功能19
                printf("input a name for your new list!\n");
                scanf("%s", listName);
                AddList(lists, NULL, listName);
                printf("OK!\n");
                break;
            case 20:
                printf("input a name of a list!\n");
                scanf("%s", listName);
                listIndex = getList(lists, listName);
                if (listIndex == -1){
                    printf("this list does not exist!\n");
                    break;
                }
                printf("you got its index : %d!\n", listIndex + 1);
                break;
            case 21:
                printf("input a name of a list!\n");
                scanf("%s", listName);
                listIndex = getList(lists, listName);
                if (listIndex == -1){
                    printf("this list does not exist!\n");
                    break;
                }
                RemoveList(lists, listName);
                printf("you have removed %s!\n", listName);
                break;
            case 22:                                               // 功能20
                goto out;
        }     
    }
    out :

    return 0;
}
