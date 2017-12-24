#include <iostream>
using namespace std;

typedef struct {
	int r[5];
	int length;
} SqList;

//=======================================================

//简单排序
void selectSort(SqList &L) {

	int i, j;
	for (i = 1; i < L.length; i++) {
		for (j = i + 1; j <= L.length; j++) {
			if (L.r[j] < L.r[i]) {
				L.r[i] = L.r[i] + L.r[j];
				L.r[j] = L.r[i] - L.r[j];
				L.r[i] = L.r[i] - L.r[j];
			}
		}
	}

}

//==========================================================

//堆调整,构造堆,s需要调整的节点元素下标，len节点元素的长度
void adjustHeap(SqList &L, int s, int len) {
	int rc, i;
	rc = L.r[s];	//rc为s节点的记录值
	for (i = 2 * s; i <= len; i *= 2) {
		if (i < len && L.r[i] < L.r[i + 1])
			++i;	//i为记录最大子节点的下标
		if (!(rc < L.r[i]))
			break;	//若rc值比其子节点大于或等于则跳出循环
		L.r[s] = L.r[i];		//否则交换子节点与下标为s节点的位置
		s = i;				//并继续向下调整其子节点，进入下一次循环
	}
	L.r[s] = rc;			//改变最后的s节点的值
}

//堆排序
void heapSort(SqList &L) {
	int i;
	for (i = L.length / 2; i > 0; --i) {	//从下往上构建一个新堆（大顶堆）
		adjustHeap(L, i, L.length);
	}
	for (i = L.length; i > 1; --i) {	//排序操作
		L.r[0] = L.r[1];	//r[0]与r[i]交换位值
		L.r[1] = L.r[i];
		L.r[i] = L.r[0];

		adjustHeap(L, 1, i - 1);	//逐渐减小堆树的大小（i-1）并重新构建一个新堆
	}
}

