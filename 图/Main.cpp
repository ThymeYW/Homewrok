# include <stdio.h>
# include "Graph.h"


void showMenu(){          // 打印菜单的函数
printf(
"============================================MENU=======================================================\n"
"0 : Show this menu\n"
"1 : Create a graph                                   2 : Destroy your graph\n"
"3 : Search for a vertex in your graph                4 : Assign a new value to a vertex\n"
"5 : Get the first adjacent vertex of a given vertex  6 : Get the next adjacent vertex of a given vertex\n"
"7 : Insert a vertex to your graph                    8 : Delete a vertex with its arcs\n"
"9 : Insert an arc between two vertices               10: Delete the arc between two vertices\n"
"11: Traverse your graph with DFS method              12: Traverse your graph with BFS method\n"
"13: Get vertices whose distance from a given vertex is less than a given integer\n"
"14: Get the shortest path length between two vertices\n"
"15: Count the connected components in your graph     16: Save your graph in a file\n"
"17: Load a graph from a file                         18: Add a new Graph\n"
"19: Remove a graph                                   20: Locate your graph\n"
"21: Quit\n"
"============================================MENU=======================================================\n"
"\n");
}               // 菜单函数

bool readAndCheckVertices(VertexType vertices[]){
	int key, count = 0;
	char str[25];
	bool hash[10000] = {false}, valid = true; // 用valid mark 一下输入是否正确

	scanf("%d %s", &key, str);

	while (key != -1){
		if (hash[key+1000])               // 关键字重复, 直接错误;
			valid = false;
		hash[key+1000] = true;

		vertices[count].key = key;
		strcpy(vertices[count].others, str);
		++ count;
		scanf("%d %s", &key, str);
	}

	vertices[count].key = -1;

	return valid;
}

bool readAndCheckEdges(KeyType edges[][2],VertexType vertices[]){   //读取边的函数
	bool hash[10000] = {false}, table[1000][1000] = {false}, valid = true;
	int i = 0;

	while (vertices[i].key != -1){
		hash[vertices[i].key+1000] = true;
		++ i;
	}

	int u, v, count = 0;

	scanf("%d %d", &u, &v);

	while (u != -1){
		if (!hash[u+1000] || !hash[v+1000])   // 输入了不存在的节点;
			valid = false;

		if (table[u+100][v+100] || table[v+100][u+100]){
			scanf("%d %d", &u, &v);
			continue;
		}             // 去除重复边;

		table[u+100][v+100] = table[v+100][u+100] = true;

		edges[count][0] = u;				// 记录读取到的边
		edges[count][1] = v;

		++ count;

		scanf("%d %d", &u, &v);
	}
	edges[count][0] = -1;
	edges[count][1] = -1;
	
	return valid;
}

inline void visit(VertexType value){
	printf("%d,%s ", value.key, value.others);
}

int main(){
	/*进行变量声明*/

	multiGraph mulG;
	int distance = -1, nowIndex = -1, tmpIndex = -1, choice, vertexIndex = -1, count = 0, graphIndex = -1;
	char fileName[20], graphName[20], ch;
	VertexType vertices[MAX_VERTEX_NUM], value;
	KeyType verticesRelationship[MAX_VERTEX_NUM<<2][2], key, tmpKey;
	ArcNode* arcptr = NULL;

	mulG.length = 0;        //多图管理初始化

	showMenu();
	printf("make your choice!\n");

	while (true){
		scanf("%d", &choice);
		switch (choice){
			case 0:
				showMenu();
				break;
			case 1:                             // 创建图的邻接表
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				if (mulG.elem[nowIndex].G.vexnum != 0){
					printf("your graph is not empty!\n");
					break;
				}

				printf("input each vertex with its key and data(end with -1 nil)!\n");
				printf("note that key must be an integer!\n");

				if (!readAndCheckVertices(vertices)){
					printf("two keys can't be the same!\n");
					while ((ch = getchar()) != '\n' && ch != EOF);     // 清空输入缓冲区;
					break;
				}

				printf("input each edge with its relevant vertices(end with -1 -1)!\n");

				if (!readAndCheckEdges(verticesRelationship, vertices)){
					printf("each vertex you input must exist in your graph!\n");
					while ((ch = getchar()) != '\n' && ch != EOF);     // 清空输入缓冲区;
					break;
				}

				CreateCraph(mulG.elem[nowIndex].G, vertices, verticesRelationship);

				printf("OK!\n");
				break;

			case 2:  // 销毁图;
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				if (mulG.elem[nowIndex].G.vexnum == 0){
					printf("your graph is empty!\n");
					break;
				}

				DestroyGraph(mulG.elem[nowIndex].G);

				printf("OK!\n");
				break;
			case 3:   // 查找顶点;
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				printf("input a key of a vertex!\n");
				scanf("%d", &key);

				vertexIndex = LocateVex(mulG.elem[nowIndex].G, key);

				if (vertexIndex == -1){
					printf("there is no vertex with key %d!\n", key);
					break;
				}

				printf("you got it : %d, %s!\n", key, mulG.elem[nowIndex].G.vertices[vertexIndex].data.others);

				break;
			case 4: // 增加顶点

				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				printf("input a key of a vertex!\n");
				scanf("%d", &key);

				vertexIndex = LocateVex(mulG.elem[nowIndex].G, key);
				if (vertexIndex == -1){
					printf("there is no vertex with key %d!\n", key);
					break;
				}

				printf("input a new vertex with its key and data!\n");
				scanf("%d %s", &value.key, &value.others);

				tmpIndex = LocateVex(mulG.elem[nowIndex].G, value.key);
				if (tmpIndex != -1 && tmpIndex != vertexIndex){
					printf("two keys can't be the same!\n");
					break;
				}

				PutVex(mulG.elem[nowIndex].G, key, value);
				printf("OK!\n");

				break;
				case 5://查找第一啊adjacent 点
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				printf("input a key of a vertex!\n");
				scanf("%d", &key);

				vertexIndex = LocateVex(mulG.elem[nowIndex].G, key);
				if (vertexIndex == -1){
					printf("there is no vertex with key %d!\n", key);
					break;
				}

				vertexIndex = FirstAdjVex(mulG.elem[nowIndex].G, key);

				if (vertexIndex == -2){
					printf("there is no adjacent vertex of vertex %d!\n", key);
					break;
				}

				printf("you got it : %d, %s!\n", mulG.elem[nowIndex].G.vertices[vertexIndex].data.key, mulG.elem[nowIndex].G.vertices[vertexIndex].data.others);
				break;
			case 6://查找下一adjacent 点

				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				printf("input two keys of two vertices!\n");
				scanf("%d %d", &key, &tmpKey);

				vertexIndex = LocateVex(mulG.elem[nowIndex].G, key);
				if (vertexIndex == -1){
					printf("there is no vertex with key %d!\n", key);
					break;
				}

				tmpIndex = LocateVex(mulG.elem[nowIndex].G, tmpKey);
				if (tmpIndex == -1){
					printf("there is no vertex with key %d!\n", tmpKey);
					break;
				}

				vertexIndex = NextAdjVex(mulG.elem[nowIndex].G, key, tmpKey);
				if (vertexIndex == -1){
					printf("vertex %d and vertex %d are not adjacent!\n", key, tmpKey);
					break;
				}

				if (vertexIndex == -2){
					printf("there is no more adjacent vertex of vertex %d after %d!\n", key, tmpKey);
					break;
				}

				printf("you got it : %d, %s!\n", mulG.elem[nowIndex].G.vertices[vertexIndex].data.key, mulG.elem[nowIndex].G.vertices[vertexIndex].data.others);
				break;

			case 7:     //插%入顶点
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				printf("input a new vertex with its key and data!\n");
				scanf("%d %s", &value.key, &value.others);

				vertexIndex = LocateVex(mulG.elem[nowIndex].G, value.key);
				if (vertexIndex != -1){
					printf("there is already a vertex with key %d!\n", value.key);
					break;
				}

				InsertVex(mulG.elem[nowIndex].G, value);
				printf("OK!\n");

				break;

			case 8://删除顶点
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				printf("input a key of a vertex!\n");
				scanf("%d", &key);

				vertexIndex = LocateVex(mulG.elem[nowIndex].G, key);
				if (vertexIndex == -1){
					printf("there is no vertex with key %d!\n", key);
					break;
				}

				DeleteVex(mulG.elem[nowIndex].G, key);
				printf("OK!\n");

				break;

			case 9://插入边
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				printf("input two keys of two vertices!\n");
				scanf("%d %d", &key, &tmpKey);

				vertexIndex = LocateVex(mulG.elem[nowIndex].G, key);
				if (vertexIndex == -1){
					printf("there is no vertex with key %d!\n", key);
					break;
				}

				tmpIndex = LocateVex(mulG.elem[nowIndex].G, tmpKey);
				if (tmpIndex == -1){
					printf("there is no vertex with key %d!\n", tmpKey);
					break;
				}

				if (InsertArc(mulG.elem[nowIndex].G, key, tmpKey) == ERROR){
					printf("vertex %d and vertex %d are already adjacent!\n", key, tmpKey);
					break;
				}

				printf("OK!\n");

				break;

			case 10://删除边
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				printf("input two keys of two vertices!\n");
				scanf("%d %d", &key, &tmpKey);

				if (key == tmpKey){
					printf("two keys can't be the same!\n");
					break;
				}

				vertexIndex = LocateVex(mulG.elem[nowIndex].G, key);
				if (vertexIndex == -1){
					printf("there is no vertex with key %d!\n", key);
					break;
				}

				tmpIndex = LocateVex(mulG.elem[nowIndex].G, tmpKey);
				if (tmpIndex == -1){
					printf("there is no vertex with key %d!\n", tmpKey);
					break;
				}

				if (DeleteArc(mulG.elem[nowIndex].G, key, tmpKey) == ERROR){
					printf("vertex %d and vertex %d are not adjacent!\n", key, tmpKey);
					break;
				}

				printf("OK!\n");

				break;
			case 11://Depth First Search 遍历
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}
				if (mulG.elem[nowIndex].G.vexnum == 0){
					printf("your graph is empty!\n");
					break;
				}
				DFSTraverse(mulG.elem[nowIndex].G, visit);
				printf("OK!\n");

				break;
			case 12: // Breadth First Search 遍历
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}
				if (mulG.elem[nowIndex].G.vexnum == 0){
					printf("your graph is empty!\n");
					break;
				}
				BFSTraverse(mulG.elem[nowIndex].G, visit);
				printf("OK!\n");

				break;
			case 13: //查找距离小于k的顶点
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}
				if (mulG.elem[nowIndex].G.vexnum == 0){
					printf("your graph is empty!\n");
					break;
				}

				printf("input a key of a vertex!\n");
				scanf("%d", &key);

				vertexIndex = LocateVex(mulG.elem[nowIndex].G, key);
				if (vertexIndex == -1){
					printf("there is no vertex with key %d!\n", key);
					break;
				}

				printf("input a distance!\n");
				scanf("%d", &distance);
				if (distance < 0){
					printf("your distance can't be negative!\n");
					break;
				}

				arcptr = VerticesSetLessThanK(mulG.elem[nowIndex].G, key, distance);
				if (arcptr == NULL){
					printf("there is no vertex that is %d unit from vertex %d", distance, key);
					break;
				}

				while (arcptr != NULL){
					ArcNode* tmp = arcptr;
					visit(mulG.elem[nowIndex].G.vertices[tmp->adjvex].data);
					arcptr = tmp->nextarc;
					free(tmp);
				}

				printf("OK!\n");
				break;

			case 14:  //查找顶点之间的最短距离
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				printf("input two keys of two vertices!\n");
				scanf("%d %d", &key, &tmpKey);

				vertexIndex = LocateVex(mulG.elem[nowIndex].G, key);
				if (vertexIndex == -1){
					printf("there is no vertex with key %d!\n", key);
					break;
				}

				tmpIndex = LocateVex(mulG.elem[nowIndex].G, tmpKey);
				if (tmpIndex == -1){
					printf("there is no vertex with key %d!\n", tmpKey);
					break;
				}

				distance = ShortestPathLength(mulG.elem[nowIndex].G, key, tmpKey);

				if (distance == INF){
					printf("vertices %d and %d are not adjacent!\n", key, tmpKey);
					break;
				}

				printf("you got it : %d!\n", distance);

				break;
			case 15:   //计算联通分量个数
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				count = ConnectedComponentsNums(mulG.elem[nowIndex].G);
				printf("you got it : %d\n", count);

				break;
			case 16:    //文件保存图
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				if (mulG.elem[nowIndex].G.vexnum == 0){
					printf("your graph is empty!\n");
					break;
				}

				printf("input a file name!\n");
				scanf("%s", fileName);

				SaveGraph(mulG.elem[nowIndex].G, fileName);

				printf("OK!\n");

				break;
			case 17:   //读取图
				if (mulG.length == 0){
					printf("you have no graph in hand, please add a graph first!\n");
					break;
				}

				printf("input a name of a graph to operate!\n");
				scanf("%s", graphName);

				nowIndex = getGraph(mulG, graphName);
				if (nowIndex == -1){
					printf("this graph isn't exist!\n");
					break;
				}

				if (mulG.elem[nowIndex].G.vexnum != 0){
					printf("your graph is not empty!\n");
					break;
				}

				printf("input a file name!\n");
				scanf("%s", fileName);

				LoadGraph(mulG.elem[nowIndex].G, fileName);

				printf("OK!\n");

				break;
			case 18:   //增加一张新的图
				printf("input a name for your graph!\n");
				scanf("%s", graphName);
				if (getGraph(mulG, graphName) != -1){
					printf("this name has already existed!\n");
					break;
				}
				addGraph(mulG, graphName);
				printf("OK!\n");
				break;

			case 19:  // 删除一张图
				printf("input a name of a graph!\n");
				scanf("%s", graphName);
				if (getGraph(mulG, graphName) == -1){
					printf("this name does not exist!\n");
					break;
				}
				removeGraph(mulG, graphName);
				printf("OK!\n");
				break;
			case 20:     // 定位图
				if (mulG.length == 0){
					printf("you have no graph in hand!\n");
					break;
				}
				printf("input a name of a graph!\n");
				scanf("%s", graphName);
				graphIndex = locateGraph(mulG, graphName);
				if (graphIndex == -1){
					printf("this graph does not exist!\n");
					break;
				}

				printf("you got it : %d!\n", graphIndex+1);
				break;
			case 21:      // 离开
				goto out;
		}
	}

out:

	return 0;
}
