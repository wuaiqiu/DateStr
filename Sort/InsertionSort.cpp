#include <iostream>
using namespace std;

typedef struct {
	int r[5];	//需要排序的数组，r[0]预留
	int length;	//需要排序的元素个数,4个
} SqList;	//预定义数据类型SqList

//=========================================================
//直接插入排序
void directInsertion(SqList &L) {
	int i, j;
	for (i = 2; i <= L.length; ++i) {
		if (L.r[i] < L.r[i - 1]) {
			L.r[0] = L.r[i];		//r[0]保留最小的数据
			L.r[i] = L.r[i - 1];
			for (j = i - 2; L.r[0] < L.r[j]; --j) {	//后移元素
				L.r[j + 1] = L.r[j];
			}
			L.r[j + 1] = L.r[0];
		}
	}
}

//=========================================================
//折半排序:直接排序的改进，利用折半查找插入元素，减少查找次数
void binarySort(SqList &L, int from, int end) {
	int i, j, low, high, mid;
	for (i = from; i <= end; i++) {
		if (L.r[i] < L.r[i - 1]) {
			L.r[0] = L.r[i];
			low = from;		//折半查找插入点
			high = i - 1;
			while (low <= high) {
				mid = (low + high) / 2;
				if (L.r[0] < L.r[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}
			//后移数据
			for (j = i - 1; j >= high + 1; j--) {
				L.r[j + 1] = L.r[j];
			}
			L.r[high + 1] = L.r[0];
		}
	}
}

//=========================================================
//2-路插入排序：利用分割点分割数据元素，减少移动元素过程，但需要额外空间
void wayInsertionSort(SqList &L) {
	SqList list;		//开辟一个新空间
	list.length = L.length;
	int first = list.length + 1, final = 1; //初始化两个“指针”
	list.r[1] = L.r[1];
	int i, j, b = 0;
	//分割
	for (i = 2; i <= L.length; i++) {
		if (list.r[1] > L.r[i])
			list.r[--first] = L.r[i];
		else
			list.r[++final] = L.r[i];
	}
	//折半排序
	binarySort(list, first, L.length);
	binarySort(list, 1, final);
	//复制list to L
	for (i = first; i <= L.length; i++)
		L.r[++b] = list.r[i];
	for (i = 1; i <= final; i++)
		L.r[++b] = list.r[i];
}

//=========================================================

//哈希排序，直接排序的改进版，需要一个增量inc来使得元素序列局部有序，inc=1
//则为直接排序
void hashSort(SqList &L, int inc) {
	int i, j;
	for (i = inc + 1; i <= L.length; i++) {
		if (L.r[i] < L.r[i - inc]) {
			L.r[0] = L.r[i];
			L.r[i] = L.r[i - inc];
			for (j = i - 2 * inc; j > 0 && L.r[0] < L.r[j]; j -= inc)
				L.r[j + inc] = L.r[j];
			L.r[j + inc] = L.r[0];
		}
	}
}

