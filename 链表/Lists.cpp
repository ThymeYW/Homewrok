# include "Lists.h"
status initLists(Lists& lists){
    lists.length = 0;
    lists.name = (char(*)[20])malloc(sizeof(char(*)[20])*(LISTS_INIT_SIZE));
    lists.size = LISTS_INIT_SIZE;             // 初始化大小
    lists.list = NULL;                          // 初始化长度！

    lists.list = (LinkList*)malloc(sizeof(LinkList)*(LISTS_INIT_SIZE));
    if (lists.list == NULL){                // 没借到内存直接返回错误！
        return ERROR;
    }

    lists.listTail = NULL;
    lists.listTail = (LinkList*)malloc(sizeof(LinkList)*(LISTS_INIT_SIZE));
    if (lists.listTail == NULL){       // 链表尾巴没借到，返回错误！
        return ERROR;
    }

    for (int i = 0; i < lists.size; i++){   // 进行初始化！
        lists.list[i] = NULL;
        lists.listTail[i] = NULL; 
    }

    return OK;
}

int getList(Lists lists, char* name){
    if (lists.list == NULL)
        return -1;
    
    for (int i = 0; i < lists.length; ++i){
        if (!strcmp(lists.name[i], name))
            return i;
    }

    return -1;
}

status AddList(Lists& lists, LinkList list, char* name){
    if (lists.length >= lists.size){
        lists.list = (LinkList*)realloc(lists.list, lists.size + LISTSINCREMENT);
        lists.listTail = (LinkList*)realloc(lists.list, lists.size + LISTSINCREMENT);
        lists.name = (char(*)[20])realloc(lists.list, lists.size += LISTSINCREMENT);
        if (lists.list == NULL)
            return ERROR;
    }

    LinkList tail = list;

    while (tail && tail->next != NULL)
        tail = tail->next;

    lists.list[lists.length] = list;
    lists.listTail[lists.length] = tail;
    strcpy(lists.name[lists.length], name);
    ++ lists.length;

    return OK;
}

void RemoveList(Lists& lists, char* name){
	int index = -1;
	for (int i = 0; i < lists.length; i++){
		if (!strcmp(lists.name[i], name)){
			index = i;
			break;
		}
	}
	if (index == -1){
		return;
	}

	for (int i = index+1; i < lists.length; i++){
		lists.list[i-1] = lists.list[i];
		lists.listTail[i-1] = lists.listTail[i];
		strcpy(lists.name[i-1], lists.name[i]);
	}

	lists.length --;
	return;
}
