#include <iostream>
using namespace std;
/*
 * 静态查找：只对数据进行查找，不坐任何操作
 * 动态查找：不仅对数据进行查找操作，还需要进行增删操作
 * */

struct SqList{
	int r[5];
	int length; //数组长度
};

//===============================================================

//顺序查找
int searchSeq(SqList &L, int key) {
	int i;
	L.r[0] = key; //r[0]存放待查找的数值，同时用于退出循环
	for (i = L.length-1; L.r[0] != L.r[i]; i--);
	return i; //返回0，为不存在
}

//==============================================================

//折半查找(只对有序表有作用，可以减少查找次数)
int searchBin(SqList &L, int key) {
	L.r[0] = key;
	int mid, low = 1, high = L.length - 1;
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

//构建树节点类型
struct BitNode {
	int index;//元素下标位置
	BitNode *lchild, *rchild; //节点的右孩子，左孩子
};

struct SqListA{
	int r[5]; 	//元素，零位置的零为Sl
	int weight[5];	//权重，零位置的零为SWl
	int length; 	//数组长度
};

//权重和计算
void getSw(int sw[], SqListA &L) {
	sw[0] = 0;
	for (int i = 1; i < L.length; i++) {
		sw[i] = sw[i - 1] + L.weight[i];
	}
}

//构建次优树
void buildTree(BitNode* &T, SqListA &L, int sw[], int low, int high) {
	int j, i = low, min = abs(sw[high] - sw[low]); //min为最小的两边权重和之差的绝对值
	for (j = i + 1; j <= high; j++) {
		if (abs((sw[high] - sw[j]) - (sw[j - 1] - sw[low - 1])) < min) {
			i = j;
			min = abs((sw[high] - sw[j]) - (sw[j - 1] - sw[low - 1]));
		}
	}
	T = (BitNode*) malloc(sizeof(BitNode));
	T->index =i;
	if (i == low)
		T->lchild = NULL;
	else
		buildTree(T->lchild, L, sw, low, i - 1);
	if (i == high)
		T->rchild = NULL;
	else
		buildTree(T->rchild, L, sw, i + 1, high);
}


//次优查找，折半查找的改进，对元素有不同的权重有区分，也是有序表
int searchSubop(SqListA &L, int key) {
	BitNode* tree = NULL;
	int sw[5]; //初始化权重和
	getSw(sw, L);
	buildTree(tree, L, sw, 1, L.length-1);
	while (tree != NULL) {
		if (L.r[tree->index] > key)
			tree = tree->lchild;
		else if (L.r[tree->index] < key)
			tree = tree->rchild;
		else
			return tree->index;
	}
	return 0;
}