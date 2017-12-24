#include <iostream>
using namespace std;
/*
 * 静态查找：只对数据进行查找，不坐任何操作
 * 动态查找：不仅对数据进行查找操作，还需要进行增删操作
 * */

typedef struct {
	int r[5];
	int length;
} SqList;

//===============================================================
//顺序查找
int searchSeq(SqList L, int key) {
	int i;
	L.r[0] = key; //r[0]存放待查找的数值，同时用于退出循环
	for (i = L.length; L.r[0] != L.r[i]; i--)
		;
	return i; //返回0，为不存在
}

//==============================================================
//折半查找(只对有序表有作用，可以减少查找次数)
int searchBin(SqList L, int key) {
	L.r[0] = key;
	int mid, low = 1, high = L.length;
	while (low <= high) {
		mid = (low + high) / 2;
		if (L.r[mid] == L.r[0])
			return mid;
		else if (L.r[mid] < L.r[0])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return 0;
}

//============================================================

//构建节点类型
typedef struct BitNode {
	int data; //节点数据
	int index; //节点在数组的下标
	struct BitNode *lchild, *rchild; //节点的右孩子，左孩子
} BitNode, *Bitree;

typedef struct {
	int key; //数组元素数据
	int weight; //数组元素权重
} node; //数组节点类型

typedef struct {
	node r[5];
	int length;
} SqListA;

//权重和计算
void getSw(int sw[], SqListA &L) {
	sw[0] = 0;
	int i;
	for (i = 1; i <= L.length; i++) {
		sw[i] = sw[i - 1] + L.r[i].weight;
	}
}

//构建次优树
void buildTree(Bitree &T, SqListA L, int sw[], int low, int high) {

	int j, i = low, min = abs(sw[high] - sw[low]); //min为最小两边权重和之差的绝对值
	for (j = i + 1; j <= high; j++) {
		if (abs((sw[high] - sw[i]) - (sw[j - 1] - sw[low - 1])) < min) {
			i = j;
			min = abs((sw[high] - sw[i]) - (sw[j - 1] - sw[low - 1]));
		}
	}
	T = (Bitree) malloc(sizeof(BitNode));
	T->data = L.r[i].key;
	T->index = i;
	if (i == low)
		T->lchild = NULL;
	else
		buildTree(T->lchild, L, sw, low, i - 1);
	if (i == high)
		T->rchild = NULL;
	else
		buildTree(T->rchild, L, sw, i + 1, high);
}

//构造次优树
void createTree(Bitree &T, SqListA L) {
	int sw[5]; //初始化权重和
	if (L.length == 0) {
		T = NULL;
	} else {
		getSw(sw, L);
		buildTree(T, L, sw, 1, L.length);

	}

}

//次优查找，折半查找的改进，对元素有不同的权重有区分，也是有序表
int searchSubop(SqListA L, int key) {
	Bitree tree = NULL;
	createTree(tree, L);
	while (tree != NULL) {
		if (tree->data > key)
			tree = tree->lchild;
		else if (tree->data < key)
			tree = tree->rchild;
		else
			return tree->index;
	}
	return 0;
}

