# ifndef LISTS_H_               // 防止头文件重复引入
# define LISTS_H_

# include "Definition.h"
# include "Destroy.h"
# include <malloc.h>
# include <string.h>


#define LISTS_INIT_SIZE 51
#define LISTSINCREMENT 10

typedef struct {              // 多链表定义！  
      LinkList* list;
      LinkList* listTail;
      char (*name)[20];      // char*[20]
      int length;
      int size;
}Lists;


status initLists(Lists&);          // 函数声明！
status AddList(Lists& , LinkList , char* );
int getList(Lists , char* );
void RemoveList(Lists& lists, char* name);

// status findList(Lists, int, LinkList&);
// status addList(Lists& , int , LinkList , LinkList );
// status delList(Lists&, int);


# endif
