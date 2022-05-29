# include "BinaryTree.h"

int i; 
BiTree create(TElemType definition[]){
    BiTree now = NULL;												// 创建一个用于储存的节点
	//printf("i = %d\n", i);
    if (definition[i].key == 0 || definition[i].key == -1){
        i ++;
        return NULL;
    }

    now = (BiTree)malloc(sizeof(BiTNode));                          // 为节点分配空间
	now->data = definition[i];
    i ++;

    now->lchild = create(definition);                              // 根据先序遍历递归创建二叉树
    now->rchild = create(definition);
	//printf("now = %d, now->lchild = %p, now->rchild = %p\n", now->data.key, now->lchild, now->rchild);
    return now;
}

status CreateBiTree(BiTree &T,TElemType definition[])
{
    i = 0;                                                // 将用于读取definition数组中的元素的变量初始化为0
    int hs[10000] = {0};
    int j = 0;
    while (definition[j].key != -1){
        hs[definition[j].key+1000] ++;
        if (hs[definition[j].key+1000] == 2 && definition[j].key != 0){ // 用hs表判断是否有相同的关键字
            return ERROR;
        }
        j ++;
    }
    T = create(definition);                               // 调用函数创建T;
    return OK;
}

status DestroyBiTree(forest& frs, int index){
	ClearBiTree(frs.elem[index].root);

	for (int i = index+1; i < frs.length; i++){
		frs.elem[i-1] = frs.elem[i];

	}

	frs.elem[frs.length].root = NULL;
	for (int i = 0; i < 20; i++){
		frs.elem[frs.length].name[i] = '\0';
	}

	frs.length --;

	return OK;
}

status ClearBiTree(BiTree &T)
{
 	if (T == NULL)
		return INFEASIBLE;

    if (T->lchild != NULL)                                // 根据递归清空二叉树;
        ClearBiTree(T->lchild);

    if (T->rchild != NULL)
        ClearBiTree(T->rchild);

    free(T);                                              // 搞完孩子搞爸妈;
    T = NULL;
    return OK;
}

bool BiTreeEmpty(forest frs, int index){
	return frs.elem[index].root == NULL;
}

int BiTreeDepth(BiTree T)
{
    if (T == NULL)                                        // 二叉树不存在，深度为零
        return 0;

    BiTree q[1000];                                       // 创建一个队列
    int front = 0, back = 0, depth = 0;
    q[back++] = T;
    while (front != back){                                // 利用层序遍历计算深度;
        depth ++;
        int size = back-front;
        while (size --){
            BiTree now = q[front++];
            if (now->lchild){
                q[back++] = now->lchild;
            }
            if (now->rchild){
                q[back++] = now->rchild;
            }
        }
    }

    return depth;                                          // 将深度返回;
}

BiTNode* LocateNode(BiTree T,KeyType e)
{
    if (T == NULL)                                         // T不存在，返回空指针
        return NULL;

	bool flag = false;
    BiTree now = T, p = NULL, ans = NULL;
    while (now){                                           // 根据先序遍历查找节点;
        p = now->lchild;
        if (p != NULL){
            while (p->rchild != NULL && p->rchild != now)  // 线序遍历使用Morris遍历法
                p = p->rchild;                             // 由于涉及过程比较复杂，不再赘述！
            if (p->rchild == NULL){
                if (now->data.key == e){
					flag = true;
					ans = now;
				}

                p->rchild = now;
                now = now->lchild;
                continue;
            }else{
                p->rchild = NULL;
                now = now->rchild;
                continue;
            }
        }else{
            if (now->data.key == e){
				flag = true;
				ans = now;
			}
            now = now->rchild;
        }
    }
   	return flag ? ans : NULL;                                            // 先序遍历后没找到则返回NULL;
}

status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
        return INFEASIBLE; 									// 树为空;

    bool flag = false;
    int hs[10000]= {0};
    BiTree now = T, p = NULL;
    while (now){                        					// 先序遍历查找;
        p = now->lchild;
        if (p != NULL){
            while (p->rchild != NULL && p->rchild != now)
                p = p->rchild;
            if (p->rchild == NULL){

                if (now->data.key == e){
                    now->data = value;
                    flag = true;
                }

	 			hs[now->data.key+1000] ++;
                if (hs[now->data.key+1000] == 2)
                    return ERROR;

                p->rchild = now;
                now = now->lchild;
                continue;
            }else{
                p->rchild = NULL;
                now = now->rchild;
                continue;
            }
        }else{
            if (now->data.key == e){
                now->data = value;
                flag = true;
            }

            hs[now->data.key+1000] ++;
            if (hs[now->data.key+1000] == 2)
                return ERROR;

            now = now->rchild;
        }
    }

    return flag ? OK : ERROR;                  // OK：成功， ERROR：没找到;
    /********** End **********/
}

BiTNode* GetSibling(BiTree T,KeyType e)
//实现获得兄弟结点
{
    /********** Begin *********/
    if (T == NULL || T->data.key == e)
        return NULL;                        	// 树为空或则节点为根节点;

	BiTree now = T;
	BiTree p = NULL;
    while (now != NULL){ 						// 先续遍历;
        p = now->lchild;
        if (p != NULL){
            while (p->rchild != NULL && p->rchild != now){
                p = p->rchild;
            }
            if (p->rchild == NULL){
				if (now->lchild != NULL && now->lchild->data.key == e){
                    return now->rchild;
                }

                if (now->rchild != NULL && now->rchild->data.key == e){
					return now->lchild;
                }

                p->rchild = now;
                now = now->lchild;
                continue;
            }else{
                p->rchild = NULL;
                now = now->rchild;
                continue;
            }
        }else{
            if (now->lchild != NULL && now->lchild->data.key == e){
				return now->rchild;
            }

            if (now->rchild != NULL && now->rchild->data.key == e){
				return now->lchild;
            }

            now = now->rchild;
        }
    }

    return NULL;

    /********** End **********/
}

status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTree newNode = (BiTree)malloc(sizeof(BiTNode));
    newNode->data = c;
    newNode->lchild = NULL;

    if (LR == -1){
        newNode->rchild = T;
        T = newNode;
        return OK;
    }

    if (T == NULL)
        return INFEASIBLE; 						// 树为空，不可执行！

    bool flag = false;
    int hs[10000] = {0};

    BiTree now = T, p = NULL;
    while (now != NULL){
        p = now->lchild;
        if (p != NULL){
            while (p->rchild != NULL && p->rchild != now){
                p = p->rchild;
            }
            if (p->rchild == NULL){

                if (now->data.key == e){
                    flag = true;
                    if (LR == 0){
                        BiTree tmp = now->lchild;
                        now->lchild = newNode;
                        newNode->rchild = tmp;
                    }else{
                        BiTree tmp = now->rchild;
                        now->rchild = newNode;
                        newNode->rchild = tmp;
                    }
                }

                hs[now->data.key+1000] ++;
                if (hs[now->data.key+1000] == 2)
                    return ERROR;

                p->rchild = now;
                now = now->lchild;
                continue;
            }else{
                p->rchild = NULL;
                now = now->rchild;
                continue;
            }
        }else{
            if (now->data.key == e){
                flag = true;
                if (LR == 0){
                    BiTree tmp = now->lchild;
                    now->lchild = newNode;
                    newNode->rchild = tmp;
                }else{
                    BiTree tmp = now->rchild;
                    now->rchild = newNode;
                    newNode->rchild = tmp;
                }
            }

            hs[now->data.key+1000] ++;
           if (hs[now->data.key+1000] == 2)
                return ERROR;

            now = now->rchild;
        }
    }
    return flag ? OK : ERROR;
    /********** End **********/
}

status DeleteNode(BiTree &T,KeyType e)
//删除结点。此题允许通过增加其它函数辅助实现本关任务
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/             
    if (T == NULL)
        return INFEASIBLE;

    if (T->data.key == e){               // 特别判断e是否为头节点;
        if (T->rchild && T->lchild){
            BiTree tmp = T->lchild;
            while (tmp->rchild){
                tmp = tmp->rchild;
            }
            tmp->rchild = T->rchild;
            tmp = T->lchild;
            free(T);
            T = tmp;
            return OK;
        }else if (T->rchild && !T->lchild){
            BiTree tmp = T->rchild;
            free(T);
            T = tmp;
            return OK;
        }else if (!T->rchild && T->lchild){
            BiTree tmp = T->lchild;
            free(T);
            T = tmp;
            return OK;
        }else{
            free(T);
            T = NULL;
            return OK;
        }
    }

    BiTree now = T, p = NULL;
    while (now != NULL){
        p = now->lchild;
        if (p != NULL){
            while (p->rchild != NULL && p->rchild != now){
                p = p->rchild;
            }
            if (p->rchild == NULL){
                
                
                if (now->lchild && now->lchild->data.key == e){
                    BiTree tmp = now->lchild;
                    if (!tmp->rchild && !tmp->lchild){
                        now->lchild = NULL;
                        free(tmp);
                        return OK;
                    }else if (tmp->rchild && !tmp->lchild){
                        now->lchild = tmp->rchild;
                        free(tmp);
                        return OK;
                    }else if (!tmp->rchild && tmp->lchild){
                        now->lchild = tmp->lchild;
                        free(tmp);
                        return OK;
                    }else{
                        now->lchild = tmp->lchild;
                        BiTree find = tmp->lchild;
                        while (find->rchild)
                            find = find->rchild;
                        find->rchild = tmp->rchild;
                        free(tmp);
                        return OK;
                    }
                }

                
                if (now->rchild && now->rchild->data.key == e){
                    BiTree tmp = now->rchild;
                    if (!tmp->rchild && !tmp->lchild){
                        now->rchild = NULL;
                        free(tmp);
                        return OK;
                    }else if (tmp->rchild && !tmp->lchild){
                        now->rchild = tmp->rchild;
                        free(tmp);
                        return OK;
                    }else if (!tmp->rchild && tmp->lchild){
                        now->rchild = tmp->lchild;
                        free(tmp);
                        return OK;
                    }else{
                        now->rchild = tmp->lchild;
                        BiTree find = tmp->lchild;
                        while (find->rchild)
                            find = find->rchild;
                        find->rchild = tmp->rchild;
                        free(tmp);
                        return OK;
                    }
                }



                p->rchild = now;
                now = now->lchild;
                continue;
            }else{
                p->rchild = NULL;
                now = now->rchild;
                continue;
            }
        }else{
            if (now->lchild && now->lchild->data.key == e){
                    BiTree tmp = now->lchild;
                    if (!tmp->rchild && !tmp->lchild){
                        now->lchild = NULL;
                        free(tmp);
                        return OK;
                    }else if (tmp->rchild && !tmp->lchild){
                        now->lchild = tmp->rchild;
                        free(tmp);
                        return OK;
                    }else if (!tmp->rchild && tmp->lchild){
                        now->lchild = tmp->lchild;
                        free(tmp);
                        return OK;
                    }else{
                        now->lchild = tmp->lchild;
                        BiTree find = tmp->lchild;
                        while (find->rchild)
                            find = find->rchild;
                        find->rchild = tmp->rchild;
                        free(tmp);
                        return OK;
                    }
                }
                if (now->rchild && now->rchild->data.key == e){
                    BiTree tmp = now->rchild;
                    if (!tmp->rchild && !tmp->lchild){
                        now->rchild = NULL;
                        free(tmp);
                        return OK;
                    }else if (tmp->rchild && !tmp->lchild){
                        now->rchild = tmp->rchild;
                        free(tmp);
                        return OK;
                    }else if (!tmp->rchild && tmp->lchild){
                        now->rchild = tmp->lchild;
                        free(tmp);
                        return OK;
                    }else{
                        now->rchild = tmp->lchild;
                        BiTree find = tmp->lchild;
                        while (find->rchild)
                            find = find->rchild;
                        find->rchild = tmp->rchild;
                        free(tmp);
                        return OK;
                    }
                }
            now = now->rchild;
        }
    }

    return ERROR;

    /********** End **********/
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//先序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
        return INFEASIBLE;                        // 树为空， 不可执行;

    BiTree now = T, p = NULL;
    while (now != NULL){
        p = now->lchild;
        if (p != NULL){
            while (p->rchild != NULL && p->rchild != now){
                p = p->rchild;
            }
            if (p->rchild == NULL){
                visit(now);
                p->rchild = now;
                now = now->lchild;
                continue;
            }else{
                p->rchild = NULL;
                now = now->rchild;
                continue;
            }
        }else{
            visit(now);
            now = now->rchild;
        }
    }
    return OK;

    /********** End **********/
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
        return INFEASIBLE;

    BiTree now = T, p = NULL;
    while (now != NULL){
        p = now->lchild;
        if (p != NULL){
            while (p->rchild != NULL && p->rchild != now){
                p = p->rchild;
            }
            if (p->rchild == NULL){
                p->rchild = now;
                now = now->lchild;
                continue;
            }else{
                visit(now);
                p->rchild = NULL;
                now = now->rchild;
                continue;
            }
        }else{
            visit(now);
            now = now->rchild;
        }
    }
    return OK;

    /********** End **********/
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//后序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
        return OK;

    PostOrderTraverse(T->lchild, visit);
    PostOrderTraverse(T->rchild, visit);
    visit(T);
    return OK;

    /********** End **********/
}

# include <stdbool.h>
typedef struct{
    BiTree data[1000];
    int front;
    int back;
}queue;

BiTree getFront(queue& q){
    return q.data[q.front];
}

BiTree getBack(queue& q){
    return q.data[q.back-1];
}

bool isEmpty(queue& q){
    return q.front == q.back;
}

void pop(queue& q){
    q.front ++;
}

void push(queue& q, BiTree elem){
    q.data[q.back] = elem;
    q.back ++;
}

int getSize(queue& q){
    return - q.front + q.back;
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
        return OK;

    queue q;
    q.front = 0;
    q.back = 0;
    push(q, T);

    while (!isEmpty(q)){
        int n = getSize(q);
        //printf("%d", n);
        while (n--){
            BiTree p = getFront(q);
            pop(q);
            visit(p);
            if (p->lchild != NULL)
                push(q, p->lchild);
            if (p->rchild != NULL)
                push(q, p->rchild);
        }
    }
    return OK;
    /********** End **********/
}

void save(int index, BiTree T, FILE* fp){
    if (T == NULL)
        return;
    //printf("save me!");
    unit p;
    p.index = index;
    p.data = T->data;

    fwrite(&p, sizeof(unit), 1, fp);

    save(index<<1, T->lchild, fp);
    save((index<<1)+1, T->rchild, fp);

}

status SaveBiTree(BiTree T, char FileName[])
//���������Ľ������д�뵽�ļ�FileName��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin 1 *********/
    if (T == NULL)
        return OK;

    FILE* fp = NULL;
    fp = fopen(FileName, "wb");
    if (fp == NULL)
        return ERROR;

    save(1, T, fp);
    fclose(fp);

    return OK;
    /********** End 1 **********/
}

status LoadBiTree(BiTree &T,  char FileName[])
{
    /********** Begin 2 *********/
    if (T != NULL)
        return INFEASIBLE;

    FILE* fp = NULL;
    fp = fopen(FileName, "rb");
    if (fp == NULL)
        return ERROR;

    BiTree p[1000] = {NULL};
    unit tmp;
    while(fread(&tmp, sizeof(unit), 1, fp)){
        BiTree now = (BiTree)malloc(sizeof(BiTNode));
        now->data = tmp.data;
        now->lchild = NULL;
        now->rchild = NULL;

        p[tmp.index] = now;
        if (tmp.index != 1){
            if (tmp.index&1){
                p[tmp.index>>1]->rchild = now;  // 建立父子关系
            }else{
                p[tmp.index>>1]->lchild = now;
            }
        }
    }

    T = p[1];
    return OK;


    /********** End 2 **********/
}

void dfs(BiTree T, int& ans, int nowSum){
	if (T == NULL){
		if (ans < nowSum)
			ans = nowSum;
		return;
	}

	dfs(T->lchild, ans, nowSum + T->data.key);
	dfs(T->rchild, ans, nowSum + T->data.key);

	return;
}

int maxPathSum(BiTree T){
	int ans = 0x3f3f3f3f;

	if (T == NULL)
		return INFEASIBLE;

	ans = -ans;

	dfs(T->lchild, ans, T->data.key);
	dfs(T->rchild, ans, T->data.key);

	return ans;
}

status addBinaryTree(forest& frs, char name[], TElemType definition[]){
	if (frs.length >= frs.size)
			return ERROR;
	BiTree T = NULL;
	status sta = CreateBiTree(T, definition);
	if (sta == ERROR)
		return ERROR;      //关键字重复;

	frs.elem[frs.length].root = T;
	strcpy(frs.elem[frs.length].name, name);
	frs.length ++;
	//printf("frs.length = %d", frs.length);

	return OK;
}

bool isAncestor(BiTree T, BiTree a, BiTree b, BiTree& ans){
	if (T == NULL)
		return false;

	bool left = isAncestor(T->lchild, a, b, ans);
	bool right = isAncestor(T->rchild, a, b, ans);

	if (left && right)
		ans = T;

	if (left && (T == a || T == b)){
		ans = T;
	}

	if (right && (T == a || T == b)){
		ans = T;
	}

	return left || right || T == a  || T == b;
}

BiTree lowestCommonAncestor(BiTree T, BiTree a, BiTree b){
	BiTree ans = NULL;

	if (T == NULL){
		return NULL;
	}

	isAncestor(T, a, b, ans);

	return ans;
}

void dfsInvert(BiTree& T){
	if (T == NULL)
		return;

	dfsInvert(T->lchild);
	dfsInvert(T->rchild);

	BiTree tmp = NULL;
	tmp = T->rchild;
	T->rchild = T->lchild;
	T->lchild = tmp;

	return;
}

status invertTree(BiTree& T){
	if (T == NULL)
		return INFEASIBLE;

	dfsInvert(T);

	return OK;
}

int getBiTree(forest frs, char name[]){
	for (int i = 0; i < frs.length; i++){
		if (!strcmp(frs.elem[i].name, name))
			return i;
	}
	return -1;
}
