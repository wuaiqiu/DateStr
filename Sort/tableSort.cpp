#include <iostream>
using namespace std;
struct node{
	int key;
	int next;
};

struct SqListA{
	node r[5];
	int length;
};

//重构表结构
void restructure(SqListA &L) {
	int i, q, p = L.r[0].next;
	for (i = 1; i <= L.length; i++) {
		while (p < i)
			p = L.r[p].next; //i的右边已经排好序
		q = L.r[p].next;
		if (p != i) {
			//r[p]与r[i]交换位置,r[0]为中间位置
			L.r[0] = L.r[p];
			L.r[p] = L.r[i];
			L.r[i] = L.r[0];
			//r[i].next重新赋值，保存原来的next指向
			L.r[i].next = p;
		}
		p = q;
	}
}

//表排序，采用静态链表结果，不需要移动位置
void tableSort(SqListA &L) {
	int i, front, current;
	L.r[0].next = 1;
	L.r[1].next = 0;
	for (i = 2; i <= L.length; i++) {
		front = 0;
		current = L.r[0].next;
		//顺序比较
		while (L.r[i].key >= L.r[current].key && current != 0) {
			current = L.r[current].next;
			front = L.r[front].next;
		}
		L.r[front].next = i;
		L.r[i].next = current;
	}
	restructure(L);
}
