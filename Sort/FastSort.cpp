#include <iostream>
using namespace std;

struct SqList{
	int r[5];
	int length;
};

//========================================================

//冒泡排序
void bubbleSort(SqList &L) {
	int i, j;
	for (i = 1; i < L.length; i++) {
		for (j = i + 1; j <= L.length; j++) {
			if (L.r[j] < L.r[j - 1]) {
				L.r[j] = L.r[j - 1] + L.r[j];
				L.r[j - 1] = L.r[j] - L.r[j - 1];
				L.r[j] = L.r[j] - L.r[j - 1];
			}
		}
	}
}

//============================================================

//分割，返回枢纽（分割点），low为初始点,high为终点
int partion(SqList &L, int low, int high) {
	L.r[0] = L.r[low];
	while(low<high){
		while (low < high && L.r[high] > L.r[0])
		--high;
		L.r[low] = L.r[high];
		while (low < high && L.r[low] <= L.r[0])
		++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}

//快速排序
void fastSort(SqList &L, int low, int high) {
	int piv;
	if (low < high) {
		piv = partion(L, low, high);
		fastSort(L, low, piv - 1);
		fastSort(L, piv + 1, high);
	}
}