# ifndef GRAPG_H_
# define GRAPG_H_

#include <stdio.h>
# include <stdbool.h>
# include <malloc.h>
#include <stdlib.h>
# include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 50

typedef int status;                  //用到的数据类型定义
typedef int KeyType;
typedef enum {DG,DN,UDG,UDN} GraphKind;
# define INF 0x3f3f3f3f
typedef struct {
     KeyType  key;
     char others[20];
} VertexType;                        //顶点类型定义


typedef struct ArcNode {             //表结点类型定义
	 int adjvex;                     //顶点位置编号
   	 struct ArcNode  *nextarc;	     //下一个表结点指针
} ArcNode;

typedef struct VNode{				//头结点及其数组类型定义
	 VertexType data;           	//顶点信息
   	 ArcNode *firstarc;      	    //指向第一条弧
   	} VNode,AdjList[MAX_VERTEX_NUM];

typedef  struct {                   //邻接表的类型定义
    AdjList vertices;     	        //头结点数组
    int vexnum,arcnum;   	        //顶点数、弧数
    GraphKind  kind;                //图的类型
} ALGraph;

typedef struct{                     //多图管理
	int length;
	struct {
		char name[20];
		ALGraph G;
	}elem[50];
}multiGraph;

// 接下来是函数的声明:
// 其中G代表图, mulG 代表多图管理结构, V代表顶点集合, VR代表边的集合, value代表新顶点
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2]);
status DestroyGraph(ALGraph &G);
int LocateVex(ALGraph G,KeyType u);
status PutVex(ALGraph &G,KeyType u,VertexType value);
int FirstAdjVex(ALGraph G,KeyType u);
int NextAdjVex(ALGraph G,KeyType v,KeyType w);
status InsertVex(ALGraph &G,VertexType v);
status DeleteVex(ALGraph &G,KeyType v);
status InsertArc(ALGraph &G,KeyType v,KeyType w);
status DeleteArc(ALGraph &G,KeyType v,KeyType w);
void dfs(ALGraph& G, int adjvex, void (*visit)(VertexType));
status DFSTraverse(ALGraph &G,void (*visit)(VertexType));
status BFSTraverse(ALGraph &G,void (*visit)(VertexType));
status SaveGraph(ALGraph G, char FileName[]);
status LoadGraph(ALGraph &G, char FileName[]);

// 附加功能:
ArcNode* VerticesSetLessThanK(ALGraph G, KeyType v, int k);
int ShortestPathLength(ALGraph G, KeyType v, KeyType w);
int ConnectedComponentsNums(ALGraph G);
int getGraph(multiGraph mulG, char* name);
void addGraph(multiGraph& mulG, char* name);
void removeGraph(multiGraph& mulG, char* name);
int locateGraph(multiGraph mulG, char* name);

# endif
