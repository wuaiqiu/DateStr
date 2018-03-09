#include <iostream>
using namespace std;

struct SqList{
	int r[5];
	int length;
};

//2-路归并排序,两个数组合成一个新数组,返回一个新数组
void mergeSort(SqList &list, SqList L, int start, int endA, int endB) {
	//list为归并后的新数组
	list.length = L.length;	//初始化数组元素长度
	int j, i = start;	//i为[start...endA],j为[endA+1...endB]
	int k = i;	//k为新数组的下标
	for (j = endA + 1; i <= endA && j <= endB; k++) { //小的元素先进入新数组
		if (L.r[i] <= L.r[j])
			list.r[k] = L.r[i++];
		else
			list.r[k] = L.r[j++];
	}
	while (i <= endA)
		list.r[k++] = L.r[i++];
	while (j <= endB)
		list.r[k++] = L.r[j++];
}

//递归归并，start为数组的开始，end为数组的结束
void merge(SqList &list, SqList L, int start, int end) {
	int mid;			//中点位置
	if (start == end)
		list.r[start] = L.r[start];
	else {
		mid = (start + end) / 2;
		merge(list, L, start, mid);
		merge(list, L, mid + 1, end);
		mergeSort(list, L, start, mid, end);
	}
}
