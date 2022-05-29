# ifndef BINARYTREE_H_
# define BINARYTREE_H_

#include <stdio.h>
#include <stdlib.h>
# include <string.h>
# include <stdbool.h>
// # include "queue.h"                                    // 层序遍历用到队列

#define TRUE 1                                          // 宏定义
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int KeyType;
typedef struct {
    KeyType  key;
    char others[20];
} TElemType;                                            //二叉树结点类型定义

typedef struct BiTNode{                                 //二叉链表结点的定义
    TElemType  data;
	struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

typedef struct{                                         // 森林定义
    struct{
        char name[20];
        BiTree root;
    }elem[50];

    int length;
    int size;
}forest;

typedef struct {                                        // 存储单元定义
    int index;
    TElemType data;
}unit;
 
status CreateBiTree(BiTree &,TElemType []);            // 函数声明
BiTree create(TElemType []);
status DestroyBiTree(forest&, int);
status ClearBiTree(BiTree &);
bool BiTreeEmpty(forest, int);
int BiTreeDepth(BiTree );
BiTNode* LocateNode(BiTree ,KeyType );
status Assign(BiTree &,KeyType ,TElemType );
BiTNode* GetSibling(BiTree ,KeyType );
status InsertNode(BiTree &,KeyType ,int ,TElemType );
status DeleteNode(BiTree &,KeyType );
status PreOrderTraverse(BiTree ,void (*)(BiTree));
status InOrderTraverse(BiTree ,void (*)(BiTree));
status PostOrderTraverse(BiTree ,void (*)(BiTree));
status LevelOrderTraverse(BiTree ,void (*)(BiTree));
void save(int , BiTree , FILE* );
status SaveBiTree(BiTree , char []);
status LoadBiTree(BiTree &,  char []);
void dfs(BiTree, int&, int);
status addBinaryTree(forest&, char[], TElemType[]);
int maxPathSum(BiTree);
bool isAncestor(BiTree, BiTree, BiTree, BiTree&);
BiTree lowestCommonAncestor(BiTree, BiTree, BiTree);
void dfsInvert(BiTree&);
status invertTree(BiTree&);
int getBiTree(forest, char[]);

# endif
