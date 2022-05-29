# include "Def.h"

int main(){
 
    LISTS lists;
    lists.length = 0;
    lists.listsize = 0;
    SqList L;
    int index, choice, count;
    ElemType e, pre, next, max, k, tmp;
    status sta;
    char f[50], ListName[50];
    L.elem = NULL;


    showMenu();
    printf("MAKE YOUR CHOICE!\n");
    while(true){
        scanf("%d", &choice);
        switch(choice){
            case 0:
                showMenu();
                break;
            case 1:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = InitList(lists.elem[index].L);

                if (sta == OK){
                    printf("OK!\n");
                }else if (sta == INFEASIBLE){
                    printf("this list can not be initialized!\n");
                }else{
                    printf("memory alloction error!\n");
                }
                break;

            case 2:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break; 
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = DestroyList(lists.elem[index].L);
                if (sta == OK){
                    printf("OK!\n");
                }else{
                   printf("this list hasn't been initialized!\n");
                }
                break;
                
            case 3:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }
                sta = ClearList(lists.elem[index].L);
                if (sta == OK){
                    printf("OK!\n");
                }else{
                    printf("this list hasn't been initialized!\n");
                }
                break;

            case 4:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = ListEmpty(lists.elem[index].L);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta == TRUE){
                    printf("this list is empty!\n");
                }else{
                    printf("this list is not empty!\n");
                }
                break;

            case 5:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = ListLength(lists.elem[index].L);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else{
                    printf("this list's length = %d!\n", sta);
                }
                break;

            case 6:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input the index of the element in the list!\n");
                scanf("%d", &index);
                sta = GetElem(lists.elem[index].L,index,e);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this index does not exist in the list!\n");
                }else{
                    printf("you get it : %d!\n", e);
                }
                break;

            case 7:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input the element you want to find in the list!\n");
                scanf("%d", &e);
                sta = LocateElem(lists.elem[index].L,e);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this element does not exist in the list!\n");
                }else{
                    printf("you get its index : %d!\n", sta);
                }
                break;

            case 8:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input the element whose prior element you want to find in the list!\n");
                scanf("%d", &e);
                sta = PriorElem(lists.elem[index].L,e,pre);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this prior does not exist in the list!\n");
                }else{
                    printf("you get its prior one : %d!\n", pre);
                }
                break;

            case 9:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }
            
                printf("input the element whose next element you want to find in the list!\n");
                scanf("%d", &e);
                sta = NextElem(lists.elem[index].L,e,next);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this next does not exist in the list!\n");
                }else{
                    printf("you get its next one : %d!\n", next);
                }
                break;
            case 10:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                if (lists.elem[index].L.elem == NULL){
                    printf("this list hasn't been initialized!\n");
                    break;
                }
                printf("input the element you want to insert in the list!\n");
                scanf("%d", &e);
                printf("input the index you want to insert in the list!\n");
                int index;
                scanf("%d", &index);
                sta = ListInsert(lists.elem[index].L,index,e);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this index does not exist in the list!\n");
                }else{
                    printf("OK!\n");
                }
                break;

            case 11:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                if (L.elem == NULL){
                    printf("this list hasn't been initialized!\n");
                    break;
                }
                printf("input the index you want to delete in the list!\n");
                scanf("%d", &index);
                sta = ListDelete(lists.elem[index].L,index,e);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta ==ERROR){
                    printf("this index does not exist in the list!\n");
                }else{
                    printf("you have deleted %d\n", e);
                }
                break;

            case 12:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = ListTraverse(lists.elem[index].L);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else{
                    printf("OK!\n");
                }
                break;

            case 13:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                max = MaxSubArray(lists.elem[index].L);
                printf("you got the maxsubarray's sum : %d!\n", max);
                break;

            case 14:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input a key integer as your target sum : \n");
                scanf("%d", &k);
                sta = SubArrayNum(lists.elem[index].L, k, count);
                if (sta == OK)
                    printf("you got the amount of subarrays whose sum equals to %d : %d!\n", k, count);
                else
                    printf("this list does not exist!\n");
                break;

            case 15:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                sta = sortList(lists.elem[index].L);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else{
                    ListTraverse(lists.elem[index].L);
                    printf("OK!\n");
                }
                break;

            case 16:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input the filename where you want to save the list!\n");
                scanf("%s", f);
                sta = SaveList(lists.elem[index].L, f);
                if (sta == INFEASIBLE){
                    printf("this list does not exist!\n");
                }else if (sta == ERROR){
                    printf("open error!\n");
                }else{
                    printf("OK!\n");
                }
                break;

            case 17:
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                printf("input the filename where you want to load the list!\n");
                scanf("%s", f);
                sta = LoadList(lists.elem[index].L, f);
                if (sta == INFEASIBLE){
                    printf("this list isn't empty so you can't load anything onto it!\n");
                }else if (sta == ERROR){
                    // do nothing;
                }else{
                    printf("OK!\n");
                }
                break;

            case 18:                            //添加一串元素;
                if (lists.length == 0){
                    printf("you have no list in hand, please add a list before your operation!\n");
                    break;
                }

                printf("input a name of a list!\n");
                scanf("%s", ListName);

                index = LocateList(lists, ListName);

                if (index == -1){
                    printf("this list doesn't exist!\n");
                    break;
                }

                
                if (lists.elem[index].L.elem == NULL){
                    printf("this list hasn't been initialized!\n");
                    break;
                }

                printf("input a list ended with 0!\n");
                scanf("%d", &tmp);
                while(tmp != 0){
                    if (lists.elem[index].L.length >= lists.elem[index].L.listsize){
                        lists.elem[index].L.elem = (ElemType*)realloc(lists.elem[index].L.elem, sizeof(ElemType)*(lists.elem[index].L.listsize += LISTINCREMENT));
                        if (lists.elem[index].L.elem == NULL){
                            printf("memory allocation error!\n");
                            goto skip;
                        }
                    }
                    L.elem[L.length++] = tmp;
                    scanf("%d", &tmp);
                }

                printf("OK!\n");
                skip:
                break;
            case 19:
                printf("add a list to your lists!\n"
                       "input its name : ");
                scanf("%s", ListName);
                sta = AddList(lists, ListName);
                if (sta == OK){
                    printf("OK!\n");
                }else{
                    printf("there is no more space in the lists!\n");
                }

                break;
            case 20:

                printf("remove a list in your lists!\n"
                       "input its name : ");
                scanf("%s", ListName);
                sta = RemoveList(lists, ListName);
                if (sta == OK){
                    printf("OK!\n");
                }else{
                    printf("this list does not exist in the lists!\n");
                }

                break;

            case 21:
                printf("input the name of a list you want to get!\n");
                scanf("%s", ListName);
                index = LocateList(lists, ListName);
                if (index){
                    printf("you got its index : %d!\n", index);
                    ListTraverse(lists.elem[index].L);
                    printf("OK!\n");
                }else{
                    printf("this list does not exist in the lists!\n");
                }
                break;

            case 22:
                goto out;
        }     
    }
    out :

    return 0;
}