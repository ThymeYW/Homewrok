# ifndef SAVEANDLOAD_H_                // 防止头文件重复引入
# define SAVEANDLOAD_H_

# include "Definition.h"
# include <malloc.h>
# include <stdio.h>

status SaveList(LinkList ,char []);   // 函数声明
status LoadList(LinkList&, char []);

# endif