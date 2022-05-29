# include "BinaryTree.h"

int j = 0;

void showMenu(){
    printf("========================================MENU===================================================\n"
          "0 : Show this menu\n"
          "1 : Create a binaryTree                      2 : Destroy your binaryTree\n"
          "3 : Clear your binaryTree                    4 : Make sure if your binaryTree is empty\n"
          "5 : Get the depth of your binaryTree         6 : Get one particular element\n"
          "7 : Assign a new value to a node             8 : Get the sibling of one element\n"
          "9 : Insert a node in your binaryTree         10: Delete a node\n"
		  "11: Preordertraverse your binaryTree         12: Inordertraverse your binaryTree\n"
          "13: Postordertraverse your binaryTree        14: Levelordertraverse your binaryTree\n"
          "15: Add a new binaryTree to your forest      16: Get the max path sum of your binaryTree\n"
          "17: Get the lowest ancestor of two nodes     18: Invert your binaryTree\n"
          "19: save your binaryTree in a file           20: Load a binaryTree from a file\n"
		  "21: Remove a binaryTree from your forest\n"
		  "22: Locate a tree in your forest             23: Quit\n"
          "========================================MENU===================================================\n"
          "\n");
}

void preGetdefinition(TElemType input[], int index, int hash[], TElemType definition[]){
	if (!hash[index]){
		definition[j++].key = 0;
		return;
	}
	definition[j++] = input[index];
	preGetdefinition(input, index<<1, hash, definition);
	preGetdefinition(input, (index<<1)+1, hash, definition);
	return;
}

inline void visit(BiTree T){
	if (T){
		printf("%d,%s ", T->data.key, T->data.others);
		//printf("T->lchild = %p, T->rchild  = %p\n", T->lchild, T->rchild);
	}
	return;
}

status getDefinition(TElemType input[], TElemType definition[]){

	int index, key;
	char str[20] = {'\0'};
	j = 0;
	int hs[10000] = {0}, hash[1000] = {0};

	do{
		scanf("%d%d%s", &index, &key, str);
		if (index == 0){
			break;
		}
		if (!hs[key+1000]){
			hs[key+1000] = 1;
		}else{
			printf("Two keys can't be the same!\n");
			while (getchar() != '\n');
			return ERROR;
		}
		if (!hash[index]){
			hash[index] = 1;
		}else{
			printf("Every position can only be assigned with a node!\n");
			while (getchar() != '\n');
			return ERROR;
		}

		input[index].key = key;
		strcpy(input[index].others, str);
	}while (index);

	for (int i = 2; i < 1000; i++){
		if (hash[i] && !hash[i>>1]){
			printf("A child can not have no parent!\n");
			return ERROR;
		}
	}

	preGetdefinition(input, 1, hash, definition);
	definition[j].key = -1;
	return OK;
}

int main(){

	forest frs;
	frs.length = 0;
	frs.size = 50;
	BiTree tmp = NULL, a = NULL, b = NULL;
	TElemType definition[100];
	char name[20] = {'\0'}, filename[20] = {'\0'};
	int nowIndex = -1, choice = -1, depth, LR, pathSum, tmpIndex = -1;
	TElemType value;
	TElemType input[1000];
	KeyType key, e1, e2;
	status sta;

	printf("input a name for your first binaryTree!\n");
	scanf("%s", name);

back1:
	printf("input each node with its index (starting with 1) in a complete binaryTree!\n");
	sta = getDefinition(input, definition);
	if (sta == ERROR){
		printf("input again? choose 1 for yes or 0 to quit!\n");
		scanf("%d", &choice);
		if (choice){
			goto back1;
		}else{
			return 0;
		}
	}
	addBinaryTree(frs, name, definition);
	nowIndex = getBiTree(frs, name);

	showMenu();
	printf("Make your choice!\n");

while(1){
	scanf("%d", &choice);
	switch (choice){
		case 0:
			showMenu();
			break;
		case 1:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}

			if (nowIndex == -1){
				printf("input a name for your new binaryTree!\n");
				scanf("%s", name);
				tmpIndex = getBiTree(frs, name);
				if (tmpIndex != -1){
					printf("there is already a binaryTree named %s\n", name);
					break;
				}
			back3:
				printf("input each node with its index (starting with 1) in a complete binaryTree!\n");
				sta = getDefinition(input, definition);
				if (sta == ERROR){
					printf("input again? choose 1 for yes or 0 to quit!\n");
					scanf("%d", &choice);
					if (choice){
						goto back3;
					}else{
						break;
					}
				}
				addBinaryTree(frs, name, definition);
				nowIndex = getBiTree(frs, name);
				printf("OK!\n");
				break;
			}

			if (frs.elem[nowIndex].root != NULL){
				printf("this tree is not empty!\n");
				break;
			}

			printf("input each node with its index (starting with 1) in a complete binaryTree!\n");

			sta = getDefinition(input, definition);
			if (sta == ERROR)
				break;

			CreateBiTree(frs.elem[nowIndex].root, definition);
			printf("OK!\n");

			break;
		case 2:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			DestroyBiTree(frs, nowIndex);
			nowIndex = -1;
			printf("OK!\n");

			break;
		case 3:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			ClearBiTree(frs.elem[nowIndex].root);
			printf("OK!\n");

			break;
		case 4:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			if (BiTreeEmpty(frs, nowIndex))
				printf("your binaryTree is empty!\n");
			else
				printf("your binaryTree isn't empty!\n");

			break;
		case 5:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			depth = BiTreeDepth(frs.elem[nowIndex].root);
			printf("the depth of your binaryTree equals %d!\n", depth);

			break;
		case 6:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			printf("input the key of a node!\n");
			scanf("%d", &key);
			tmp = LocateNode(frs.elem[nowIndex].root, key);
			if (tmp == NULL){
				printf("this node does not exist!\n");
				break;
			}
			printf("you got it : %d,%s !\n", tmp->data.key, tmp->data.others);
			break;
		case 7:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			printf("input the key of a node in your binaryTree!\n");
			scanf("%d", &key);
			tmp = LocateNode(frs.elem[nowIndex].root, key);
			if (tmp == NULL){
				printf("this node does not exist!\n");
				break;
			}
			printf("input a new node with its key and data!\n");
			scanf("%d%s", &value.key, value.others);
			tmp = LocateNode(frs.elem[nowIndex].root, value.key);
			if (tmp != NULL && value.key != key){
				printf("there is already a node with its key being %d!\n", value.key);
				break;
			}
			Assign(frs.elem[nowIndex].root, key, value);
			printf("OK!\n");
			break;
		case 8:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			printf("input the key of a node!\n");
			scanf("%d", &key);
			tmp = LocateNode(frs.elem[nowIndex].root, key);
			if (tmp == NULL){
				printf("this node does not exist!\n");
				break;
			}
			tmp = GetSibling(frs.elem[nowIndex].root, key);
			if (tmp == NULL){
				printf("this node has no sibling!\n");
				break;
			}
			printf("your got it : %d,%s!\n",tmp->data.key, tmp->data.others);
			break;
		case 9:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			printf("input the key of a node in your binaryTree!\n");
			scanf("%d", &key);
			tmp = LocateNode(frs.elem[nowIndex].root, key);
			if (tmp == NULL){
				printf("this node does not exist!\n");
				break;
			}
			printf("input a new node with its key and data!\n");
			scanf("%d%s", &value.key, value.others);
			tmp = LocateNode(frs.elem[nowIndex].root, value.key);
			if (tmp != NULL){
				printf("there is already a node with its key being %d!\n", value.key);
				break;
			}
			printf("choose a mode:\n"
				   "insert the new node as root : input -1\n"
				   "insert the new node as left child of node %d : input  0\n"
				   "insert the new node as right child of node %d : input 1\n"
				   ,key, key);
			scanf("%d", &LR);
			InsertNode(frs.elem[nowIndex].root, key, LR, value);
			printf("OK!\n");
			break;
		case 10:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			printf("input the key of a node in your binaryTree!\n");
			scanf("%d", &key);
			tmp = LocateNode(frs.elem[nowIndex].root, key);
			if (tmp == NULL){
				printf("this node does not exist!\n");
				break;
			}
			DeleteNode(frs.elem[nowIndex].root, key);
			printf("OK!\n");
			break;
		case 11:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			if (frs.elem[nowIndex].root == NULL){
				printf("your binaryTree is empty!\n");
				break;
			}
			PreOrderTraverse(frs.elem[nowIndex].root, visit);
			printf("ok!\n");
			break;
		case 12:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			if (frs.elem[nowIndex].root == NULL){
				printf("your binaryTree is empty!\n");
				break;
			}

			InOrderTraverse(frs.elem[nowIndex].root, visit);
			printf("ok!\n");
			break;
		case 13:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			if (frs.elem[nowIndex].root == NULL){
				printf("your binaryTree is empty!\n");
				break;
			}

			PostOrderTraverse(frs.elem[nowIndex].root, visit);
			printf("ok!\n");
			break;
		case 14:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			if (frs.elem[nowIndex].root == NULL){
				printf("your binaryTree is empty!\n");
				break;
			}

			LevelOrderTraverse(frs.elem[nowIndex].root, visit);
			printf("ok!\n");
			break;
		case 15:
			printf("input a name for your new binaryTree!\n");
			scanf("%s", name);
			tmpIndex = getBiTree(frs, name);
			if (tmpIndex != -1){
				printf("there is already a binaryTree named %s\n", name);
				break;
			}
		back2:
			printf("input each node with its index (starting with 1) in a complete binaryTree!\n");
			sta = getDefinition(input, definition);
			if (sta == ERROR){
				printf("input again? choose 1 for yes or 0 to quit!\n");
				scanf("%d", &choice);
				if (choice){
					goto back2;
				}else{
					break;
				}
			}
			addBinaryTree(frs, name, definition);
			nowIndex = getBiTree(frs, name);
			printf("OK!\n");
			break;
		case 16:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}
			if (frs.elem[nowIndex].root == NULL){
				printf("your binaryTree is empty!\n");
				break;
			}
			pathSum = maxPathSum(frs.elem[nowIndex].root);
			printf("you got it : %d!\n", pathSum);
			break;
		case 17:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			printf("input two keys of two nodes in your binaryTree!\n");
			scanf("%d%d", &e1, &e2);
			a = LocateNode(frs.elem[nowIndex].root, e1);
			if (a == NULL){
				printf("node %d does not exist!\n", e1);
			}

			b = LocateNode(frs.elem[nowIndex].root, e2);
			if (b == NULL){
				printf("node %d does not exist!\n", e2);
			}
			if (a == NULL || b == NULL)
				break;
			if (a == b){
				printf("two keys are the same!\n");
				break;
			}

			tmp = lowestCommonAncestor(frs.elem[nowIndex].root, a, b);
			printf("you got it : %d,%s !\n",tmp->data.key, tmp->data.others);
			break;
		case 18:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			if (frs.elem[nowIndex].root == NULL){
				printf("your binaryTree is empty!\n");
				break;
			}
			invertTree(frs.elem[nowIndex].root);
			printf("OK!\n");
			break;
		case 19:
			if (frs.length == 0){
				printf("your forest is empty, please add a new binaryTree to your forest!\n");
				break;
			}

			printf("input a name of a binaryTree!\n");
			scanf("%s", name);

			nowIndex = getBiTree(frs, name);

			if (nowIndex == -1){
				printf("this binaryTree doesn't exist!\n");
				break;
			}
			if (nowIndex == -1){
				printf("you have no binaryTree in hand!\n");
				break;
			}

			if (frs.elem[nowIndex].root == NULL){
				printf("your binaryTree is empty!\n");
				break;
			}

			printf("input a file name!\n");
			scanf("%s", filename);
			SaveBiTree(frs.elem[nowIndex].root, filename);
			printf("OK!\n");
			break;
		case 20:
			if (nowIndex == -1){
				printf("input a name for your binaryTree!\n");
				scanf("%s", name);
				strcpy(frs.elem[frs.length].name, name);
				printf("input a file name!\n");
				scanf("%s", filename);
				frs.elem[frs.length].root == NULL;
				LoadBiTree(frs.elem[frs.length].root, filename);
				nowIndex = frs.length ++;
				printf("OK!\n");
				break;
			}

			if (frs.elem[nowIndex].root != NULL){
				printf("your binaryTree isn't empty!\n");
				break;
			}

			printf("input a file name!\n");
			scanf("%s", filename);
			LoadBiTree(frs.elem[nowIndex].root, filename);
			printf("OK!\n");

			break;
		case 21:
			printf("input the name of a binaryTree!\n");
			scanf("%s", name);
			tmpIndex = getBiTree(frs, name);
			if (tmpIndex == -1){
				printf("there is no binaryTree named %s!\n", name);
				break;
			}
			DestroyBiTree(frs, tmpIndex);
			if (tmpIndex == nowIndex){
				nowIndex = -1;
			}
			printf("OK!\n");
			break;
		case 22:
			printf("input the name of a binaryTree!\n");
			scanf("%s", name);
			tmpIndex = getBiTree(frs, name);
			if (tmpIndex == -1){
				printf("there is no binaryTree named %s!\n", name);
				break;
			}
			printf("you got its index : %d!\n", tmpIndex+1);
			if (tmpIndex != nowIndex){
				printf("choose to operate this binaryTree?\n");
				printf("input 1 for yes or 0 for no!\n");
				scanf("%d", &choice);
				if (choice){
					nowIndex = tmpIndex;
					printf("OK!\n");
					break;
				}
				printf("OK!\n");
				break;
			}

			printf("OK!\n");
			break;
		case 23:
			goto out;
			break;
	}

}
out:

	return 0;
}


















