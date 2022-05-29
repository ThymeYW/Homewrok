# include "Graph.h"
int que[MAX_VERTEX_NUM], front, back;
bool visited[MAX_VERTEX_NUM];
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (V[0].key == -1)
        return ERROR;

    int i = 0, hs[10000] = {0}, table[1000] = {0};
    G.vexnum = 0;
    G.arcnum = 0;
    G.kind = UDG;
    while (V[i].key != -1){
        G.vexnum ++;
        if (G.vexnum > MAX_VERTEX_NUM)
            return ERROR;

        table[V[i].key] ++;
        if (table[V[i].key] == 2)
            return ERROR;
        hs[V[i].key] = i;
        G.vertices[i].data = V[i];
        G.vertices[i++].firstarc = NULL;

    }

    while (VR[G.arcnum++][0] != -1);

    G.arcnum --;

    for (int j = 0; j < G.arcnum; j++){
        if (table[VR[j][0]] == 0 || table[VR[j][1]] == 0)
            return ERROR;
    }


    for (i = 0; i < G.vexnum; i++){
        ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
        p->nextarc = NULL;
        ArcNode* tail = p;
        for (int j = G.arcnum-1; j >= 0; j--){
            if (VR[j][0] == G.vertices[i].data.key){
                ArcNode* newNode = (ArcNode*)malloc(sizeof(ArcNode));
                newNode->adjvex = hs[VR[j][1]];
                tail->nextarc = newNode;
                tail = newNode;
            }else if (VR[j][1] == G.vertices[i].data.key){
                ArcNode* newNode = (ArcNode*)malloc(sizeof(ArcNode));
                newNode->adjvex = hs[VR[j][0]];
                tail->nextarc = newNode;
                tail = newNode;
            }
        }
        tail->nextarc = NULL;
        tail = p->nextarc;
        free(p);
        G.vertices[i].firstarc = tail;
    }
    return OK;

    /********** End **********/
}

status DestroyGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; i++){
        ArcNode* p = G.vertices[i].firstarc;
        while (p){
            ArcNode* tmp = p->nextarc;
            free(p);
            p = tmp;
        }
    }
    G.vexnum = G.arcnum = 0;
    return OK;

    /********** End **********/
}

int LocateVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; i++){
        if (G.vertices[i].data.key == u)
            return i;
    }

	return -1;

}

status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    bool assigned = false;

    for (int i = 0; i < G.vexnum; i++){
        if (G.vertices[i].data.key == u){
            assigned = true;
            G.vertices[i].data = value;
        }
    }
    bool hs[1000] = {false};

    for (int i = 0; i < G.vexnum; i++){
        if (!hs[G.vertices[i].data.key]){
            hs[G.vertices[i].data.key] = true;
        }else{
            return ERROR;
        }
    }

    return assigned ? OK : ERROR;
    /********** End **********/
}

int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; i++){
        if (G.vertices[i].data.key == u){
            if (!G.vertices[i].firstarc)
                return -2;            // 没有连节点;
            return G.vertices[i].firstarc->adjvex;
        }
    }

    return -1;

    /********** End **********/
}

int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//根据u在图G中查找顶点，查找成功返回顶点v的邻接顶点相对于w的下一邻接顶点的位序，查找失败返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; i++){
        if (G.vertices[i].data.key == v){
            ArcNode* p = G.vertices[i].firstarc;
            while (p){
                if (G.vertices[p->adjvex].data.key == w){
                    if (p->nextarc)
                        return p->nextarc->adjvex;
					else
						return -2; // 没有下一个!
                }
                p = p->nextarc;
            }
        }
    }

    return -1;         // v and w 不相恋;

    /********** End **********/
}

status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (G.vexnum >= MAX_VERTEX_NUM)
        return ERROR;

    for (int i = 0; i < G.vexnum; i++)
        if (G.vertices[i].data.key == v.key)
            return ERROR;

    G.vertices[G.vexnum].data = v;
    G.vertices[G.vexnum++].firstarc = NULL;

    return OK;

    /********** End **********/
}

status DeleteVex(ALGraph &G,KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //if (G.vexnum == 1)
    //   return ERROR;

    int targetIndex = -1;
    for (int i = 0; i < G.vexnum; i++){
        if (G.vertices[i].data.key == v){
            targetIndex = i;
        }
    }

    if (targetIndex == -1)
        return ERROR;

    ArcNode* p = G.vertices[targetIndex].firstarc;
    while (p){
        ArcNode* t = G.vertices[p->adjvex].firstarc;
        if (G.vertices[t->adjvex].data.key == v){
            if (t->nextarc){
                ArcNode* tmp = t;
                G.vertices[p->adjvex].firstarc = t->nextarc;
                free(tmp);
            }else{
                free(t);
                G.vertices[p->adjvex].firstarc = NULL;
            }
        }

        while (t && t->nextarc){
            if (G.vertices[t->nextarc->adjvex].data.key == v){
                if (t->nextarc->nextarc){
                    ArcNode* tmp = t->nextarc;
                    t->nextarc = t->nextarc->nextarc;
                    free(tmp);
                }else{
                    free(t->nextarc);
                    t->nextarc = NULL;
                }
            }
            t = t->nextarc;
        }
        G.arcnum --;
        ArcNode* tmp = p->nextarc;
        free(p);
        p = tmp;
    }

    for (int i = targetIndex+1; i < G.vexnum; i++){
        G.vertices[i-1] = G.vertices[i];
    }

    G.vexnum --;

    for (int i = 0; i < G.vexnum; i++){
        ArcNode* p = G.vertices[i].firstarc;
        while (p){
            if (p->adjvex > targetIndex)
                p->adjvex --;
            p = p->nextarc;
        }
    }

    return OK;

    /********** End **********/
}

status InsertArc(ALGraph &G,KeyType v,KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int index_of_v = -1, index_of_w = -1;

    for (int i = 0; i < G.vexnum; i++)
        if (G.vertices[i].data.key == v)
            index_of_v = i;

    for (int i = 0; i < G.vexnum; i++)
        if (G.vertices[i].data.key == w)
            index_of_w = i;

    if (index_of_v == -1 || index_of_w == -1)
        return ERROR;

    ArcNode* arc_of_v = G.vertices[index_of_v].firstarc;
    ArcNode* arc_of_w = G.vertices[index_of_w].firstarc;

    while (arc_of_v){
        if (arc_of_v->adjvex == index_of_w)
            return ERROR;
        arc_of_v = arc_of_v->nextarc;
    }                                     // 检查v和w原来是否相连;

    arc_of_v = G.vertices[index_of_v].firstarc;

    ArcNode* tmpv = (ArcNode*)malloc(sizeof(ArcNode));
    tmpv->adjvex = index_of_w;
    tmpv->nextarc = arc_of_v;
    G.vertices[index_of_v].firstarc = tmpv;

    ArcNode* tmpw = (ArcNode*)malloc(sizeof(ArcNode));
    tmpw->adjvex = index_of_v;
    tmpw->nextarc = arc_of_w;
    G.vertices[index_of_w].firstarc = tmpw;

    G.arcnum ++;

    return OK;

    /********** End **********/
}

status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int index_of_v = -1, index_of_w = -1;

    for (int i = 0; i < G.vexnum; i++)
        if (G.vertices[i].data.key == v)
            index_of_v = i;

    for (int i = 0; i < G.vexnum; i++)
        if (G.vertices[i].data.key == w)
            index_of_w = i;

    if (index_of_v == -1 || index_of_w == -1)
        return ERROR;

    ArcNode* arc_of_v = G.vertices[index_of_v].firstarc;
    ArcNode* arc_of_w = G.vertices[index_of_w].firstarc;

    bool flagv = false, flagw = false;

    if (arc_of_v && arc_of_v->adjvex == index_of_w){
        G.vertices[index_of_v].firstarc = arc_of_v->nextarc;
        free(arc_of_v);
        flagv = true;
    }else{
        while (arc_of_v && arc_of_v->nextarc){
            if (arc_of_v->nextarc->adjvex == index_of_w){
                ArcNode* tmp = arc_of_v->nextarc;
                arc_of_v->nextarc = tmp->nextarc;
                free(tmp);
                flagv = true;
            }
            arc_of_v = arc_of_v->nextarc;
        }
    }

    if (arc_of_w && arc_of_w->adjvex == index_of_v){
        G.vertices[index_of_w].firstarc = arc_of_w->nextarc;
        free(arc_of_w);
        flagw = true;
    }else{
        while (arc_of_w && arc_of_w->nextarc){
            if (arc_of_w->nextarc->adjvex == index_of_v){
                ArcNode* tmp = arc_of_w->nextarc;
                arc_of_w->nextarc = tmp->nextarc;
                free(tmp);
                flagw = true;
            }
            arc_of_w = arc_of_w->nextarc;
        }
    }

    if (flagw && flagv){
        G.arcnum --;
        return OK;
    }

    return ERROR;

    /********** End **********/
}

void dfs(ALGraph& G, int adjvex, void (*visit)(VertexType))
{
    visit(G.vertices[adjvex].data);
	visited[adjvex] = true;

    for (ArcNode* ptr = G.vertices[adjvex].firstarc; ptr != NULL; ptr = ptr->nextarc){
        if (!visited[ptr->adjvex]){
            dfs(G, ptr->adjvex, visit);
        }
    }
}

status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	for (int i = 0; i < MAX_VERTEX_NUM; ++i)
		visited[i] = false;

    for (int vertex = 0; vertex < G.vexnum; vertex++){
        if (!visited[vertex])
            dfs(G, vertex, visit);
    }

    return OK;

    /********** End **********/
}

status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < MAX_VERTEX_NUM; ++i)
		visited[i] = false;

	front = back = 0;

	if (G.vexnum < 1)
        return ERROR;
    for (int v = 0; v < G.vexnum; v ++){
        if (!visited[v]){
            que[back++] = v;
            if (back == MAX_VERTEX_NUM){
                back = 0;
            }

            while (front != back){
                int vertex = que[front++];
                if (front == MAX_VERTEX_NUM){
                    front = 0;
                }

                if (!visited[vertex]){
                    visited[vertex] = true;
                    visit(G.vertices[vertex].data);

                    for (ArcNode* ptr = G.vertices[vertex].firstarc; ptr != NULL; ptr = ptr->nextarc){
                        if (!visited[ptr->adjvex]){
                            que[back++] = ptr->adjvex;
                            if (back == MAX_VERTEX_NUM)
                                back = 0;
                        }
                    }
                }
            }
        }
    }

    return OK;

    /********** End **********/
}

status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if (G.vexnum == 0)
        return ERROR;

    FILE* fp = NULL;
    fp = fopen(FileName, "wb");
    if (fp == NULL)
        return ERROR;

    fwrite(&G.kind, sizeof(int), 1, fp);
    fwrite(&G.vexnum, sizeof(int), 1, fp);
    fwrite(&G.arcnum, sizeof(int), 1, fp);

    for (int vertex = 0; vertex < G.vexnum; vertex ++){
        fwrite(&G.vertices[vertex].data, sizeof(VertexType), 1, fp);
        ArcNode* ptr = G.vertices[vertex].firstarc;
        while (ptr != NULL){
            fwrite(ptr, sizeof(ArcNode), 1, fp);
            ptr = ptr->nextarc;
        }
        ptr = (ArcNode*)malloc(sizeof(ArcNode));
        ptr->adjvex = -1;
        fwrite(ptr, sizeof(ArcNode), 1, fp);
    }

    fclose(fp);

    return OK;
    /********** End 1 **********/
}

status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    if (G.vexnum != 0)
        return ERROR;

    FILE* fp = NULL;
    fp = fopen(FileName, "rb");
    if (fp == NULL)
        return ERROR;

    fread(&G.kind, sizeof(int), 1, fp);
    fread(&G.vexnum, sizeof(int), 1, fp);
    fread(&G.arcnum, sizeof(int), 1, fp);

    for (int i = 0; i < G.vexnum; i++){

        VertexType tmpVex;
        fread(&tmpVex, sizeof(VertexType), 1, fp);

        G.vertices[i].data = tmpVex;
        ArcNode* head = (ArcNode*)malloc(sizeof(ArcNode)), *tail = head;
        if (head == NULL)
            return ERROR;

        do{
            ArcNode* ptr = NULL;
            ptr = (ArcNode*)malloc(sizeof(ArcNode));
            if (ptr == NULL)
                return ERROR;

            fread(ptr, sizeof(ArcNode), 1, fp);
            if (ptr->adjvex != -1){
                tail->nextarc = ptr;
                tail = ptr;
            }else{
                break;
            }
        }while (1);

        tail->nextarc = NULL;
        G.vertices[i].firstarc = head->nextarc;
        free(head);
    }
    fclose(fp);

    return OK;

    /********** End 2 **********/
}

ArcNode* VerticesSetLessThanK(ALGraph G, KeyType v, int k){
	if (k < 0)
		return NULL;

	int distance[G.vexnum+1];
	int vIndex = LocateVex(G, v);

	for (int i = 0; i < MAX_VERTEX_NUM; ++i){
		visited[i] = false;
	}

	for (int i = 0; i <= G.vexnum; ++i)
		distance[i] = INF;

	visited[vIndex] = true;
	distance[vIndex] = 0;

	int n = G.vexnum-1, now = vIndex;

	while (n--){
		ArcNode* p = G.vertices[now].firstarc;

		while (p != NULL){
			if (distance[p->adjvex] > distance[now] + 1){
				distance[p->adjvex] = distance[now] + 1;
			}
			p = p->nextarc;
		}

		int minIndex = -1;
		for (int i = 0; i < G.vexnum; ++i){
			if (!visited[i] && (minIndex == -1 || distance[minIndex] > distance[i]))
				minIndex = i;
		}

		visited[minIndex] = true;
		now = minIndex;
	}
	ArcNode* head = (ArcNode*)malloc(sizeof(ArcNode));
	ArcNode* tail = head;
	for (int i = 0; i < G.vexnum; ++i){
		if (distance[i] < k){
			ArcNode* tmp = (ArcNode*)malloc(sizeof(ArcNode));
			tmp->adjvex = i;
			tail->nextarc= tmp;
			tail = tmp;
		}
	}

	tail->nextarc = NULL;
	tail = head->nextarc;
	free(head);
	return tail;
}

int ShortestPathLength(ALGraph G, KeyType v, KeyType w){
	int vIndex = LocateVex(G, v);
	int wIndex = LocateVex(G, w);

	int distance[G.vexnum+1];

	for (int i = 0; i < MAX_VERTEX_NUM; ++i){
		visited[i] = false;
	}

	for (int i = 0; i <= G.vexnum; ++i)
		distance[i] = INF;

	visited[vIndex] = true;
	distance[vIndex] = 0;

	int n = G.vexnum-1, now = vIndex;

	while (n--){
		ArcNode* p = G.vertices[now].firstarc;

		while (p != NULL){
			if (distance[p->adjvex] > distance[now] + 1){
				distance[p->adjvex] = distance[now] + 1;
			}
            p = p->nextarc;
		}

		int minIndex = -1;
		for (int i = 0; i < G.vexnum; ++i){
			if (!visited[i] && (minIndex == -1 || distance[minIndex] > distance[i]))
				minIndex = i;
		}

		visited[minIndex] = true;
		now = minIndex;
	}

	return distance[wIndex];

}

// 并查集(压缩路径以及按rank分配);

int *parent;
int *rank;

void init_union_find_disjoint_set(int vexNum){
    parent = (int*)malloc(sizeof(int)*(vexNum));
    rank = (int*)malloc(sizeof(int)*(vexNum));;
    for (int i = 0; i < vexNum; ++i){
        parent[i] = i;
        rank[i] = 1;
    }
}

int findRepresentative(int x){
    if (parent[x] == x){
        return x;
    }else{
        parent[x] = findRepresentative(parent[x]);
        return parent[x];
    }
}

void merge(int i, int j){
    int x = findRepresentative(i);
    int y = findRepresentative(j);
    if (rank[x] > rank[y]){
        parent[y] = x;
    }else{
        parent[x] = y;
    }

    if (rank[x] == rank[y]){
        ++ rank[y];
    }
}

int ConnectedComponentsNums(ALGraph G){
	init_union_find_disjoint_set(G.vexnum+2);

	for (int i = 0; i < G.vexnum; ++i){
		ArcNode* p = G.vertices[i].firstarc;
		while (p){
			int adjvexIndex = p->adjvex;
			if (findRepresentative(adjvexIndex) != findRepresentative(i))
				merge(adjvexIndex, i);
			p = p->nextarc;
		}
	}

	for (int i = 0; i < MAX_VERTEX_NUM; ++i){
		visited[i] = false;
	}

	int cnt = 0;

	for (int i = 0; i < G.vexnum; ++i){
		int representative = findRepresentative(i);
		if (!visited[representative]){
			visited[representative] = true;
			++ cnt;
		}
	}

	return cnt;
}


int getGraph(multiGraph mulG, char* name){
	for (int i = 0; i < mulG.length; ++i){
		if (!strcmp(mulG.elem[i].name, name)){
			return i;
		}
	}

	return -1;
}

void addGraph(multiGraph& mulG, char *name){
	strcpy(mulG.elem[mulG.length].name, name);
	mulG.elem[mulG.length].G.vexnum = 0;
	mulG.elem[mulG.length].G.arcnum = 0;
	++ mulG.length;

	return;
}

void removeGraph(multiGraph& mulG, char* name){
	int index = getGraph(mulG, name);

	if (index == -1)
		return;

	for (int i = index+1; i < mulG.length; ++i){
		mulG.elem[i-1] = mulG.elem[i];
	}

	-- mulG.length;
	return;
}

int locateGraph(multiGraph mulG, char* name){

    for (int i = 0; i < mulG.length; ++i){
        if (!strcmp(mulG.elem[i].name, name))
            return i;
    }

    return -1;
}
