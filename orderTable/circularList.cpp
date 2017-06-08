#include <iostream>
using namespace std;

//链式存储实现线性表(循环链表)，其中（1）等指与单链表比较
typedef struct LNode {
	int data;
	struct LNode *next;
} LNode, *CircularList; //从1开始

//插入数据,位置pos[1..n],L为头结点，L->next为第一个节点
void insertCircularList(CircularList &L, int pos, int data) {
	if (!L) {
		L = (CircularList) malloc(sizeof(LNode));
		CircularList s = (CircularList) malloc(sizeof(LNode));
		s->data = data;
		s->next = L; //s的下一节点不在是NULL（1）
		L->next = s;
	} else {
		int j = 0;
		CircularList l = L; //赋值，不能在原链表上操作
		while (l && j < pos - 1) { //寻找前一个节点
			l = l->next;
			j++;
			if (l == L)
				return; //没有找到（2）
		}
		if (j != pos - 1)
			return; //没有找到
		CircularList s = (CircularList) malloc(sizeof(LNode));
		s->data = data;
		s->next = l->next;
		l->next = s;
	}
}

//删除数据
int deleteCircularList(CircularList &L, int pos) {
	int j = 0, data;
	CircularList l = L;
	while (l && j < pos - 1) { //寻找前一个节点
		l = l->next;
		j++;
		if (l->next == L)
			return -1; //没有找到（3）
	}
	if (j != pos - 1)
		return -1; //没有找到
	CircularList p = l->next; //要删除的数据
	data = p->data;
	l->next = l->next->next;
	free(p);
	return data;
}

//查询数据
int locateCircularList(CircularList L, int pos) {
	int j = 0;
	CircularList l = L;
	while (l && j < pos) { //寻找节点
		l = l->next;
		j++;
		if (l == L)
			return -1; //没有找到（4）
	}
	if (j != pos)
		return -1; //没有找到
	return l->data;
}

