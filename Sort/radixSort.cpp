#include <iostream>
using namespace std;

typedef struct {
	int r[5];
	int length;
} SqList;
//节点对象
typedef struct {
	int key;
	int next;
} node;

//采用静态链表形式
typedef struct {
	node link[14];
	int length;	//链表头节点数量（0-9）
} linkTable;

//分配比较第几位数
void distribute(SqList L, linkTable &li, int pos) {
	int i, index, current = 10;	//下一个空节点下标
	//初始化链表
	for (i = 0; i < 14; i++) {
		li.link[i].key = i;
		li.link[i].next = 0;	//清空链表
	}
	li.length = 10;
	for (i = 1; i <= L.length; i++) {
		switch (pos) {
		case 1:	//个位数
			index = L.r[i] % 10;
			break;
		case 2:	//十位数
			index = L.r[i] % 100 / 10;
			break;
		default:	//百位数
			index = L.r[i] / 100;
			break;
		}

		while (li.link[index].next != 0) { //若链表节点有子节点时
			index = li.link[index].next;
		}
		li.link[index].next = current;
		li.link[current++].key = L.r[i];
	}
}

//搜集分配后的元素
void collect(SqList &L, linkTable li) {
	int i, j = 1, temp; //temp为下一个节点的下标，j为SqList的下标
	for (i = 0; i < li.length; i++) {
		temp = li.link[i].next;
		while (temp != 0) {
			L.r[j++] = li.link[temp].key;
			temp = li.link[temp].next;
		}
	}
}

//基数排序,3位数排序
void radixSort(SqList &L) {
	int i;
	linkTable links;
	for (i = 1; i < 4; i++) {	//i为位数
		distribute(L, links, i);
		collect(L, links);
	}
}
