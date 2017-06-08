#include <iostream>
using namespace std;

//链式存储实现线性表(双向链表，无循环)，其中（1）等指与单链表比较
typedef struct LNode {
	int data;
	struct LNode *next;
	struct LNode *prior; //前驱节点（1），头结点无前驱，尾节点无后驱
} LNode, *TwoWayLinkList; //从1开始

//插入数据,位置pos[1..n],L为头结点，L->next为第一个节点
void insertTwoWayLinkList(TwoWayLinkList &L, int pos, int data) {
	if (!L) {
		L = (TwoWayLinkList) malloc(sizeof(LNode));
		TwoWayLinkList s = (TwoWayLinkList) malloc(sizeof(LNode));
		s->data = data;
		s->next = NULL;
		s->prior = L; //s的前驱（2）
		L->next = s;
		L->prior = NULL; //头结点无前驱（3）
	} else {
		int j = 0;
		TwoWayLinkList l = L; //赋值，不能在原链表上操作
		while (l && j < pos - 1) { //寻找前一个节点
			l = l->next;
			j++;
		}
		if (j != pos - 1)
			return; //没有找到
		TwoWayLinkList s = (TwoWayLinkList) malloc(sizeof(LNode));
		s->data = data;
		s->next = l->next;
		if (l->next) { //当l不为尾节点时
			l->next->prior = s; //改变l->next的前驱（3）
		}
		s->prior = l; //s的前驱（4）
		l->next = s;
	}
}

//删除数据
int deleteTwoWayLinkList(TwoWayLinkList &L, int pos) {
	int j = 0, data;
	TwoWayLinkList l = L;
	while (l && j < pos - 1) { //寻找前一个节点
		l = l->next;
		j++;
	}
	if (j != pos - 1)
		return -1; //没有找到
	TwoWayLinkList p = l->next; //要删除的数据
	data = p->data;
	l->next->next->prior = l; //改变删除数据的后一个节点（5）
	l->next = l->next->next;
	free(p);
	return data;
}

//向后查询数据
int locateTwoWayLinkList(TwoWayLinkList L, int pos) {
	int j = 0;
	TwoWayLinkList l = L;
	while (l && j < pos) { //寻找节点
		l = l->next;
		j++;
	}
	if (j != pos)
		return -1; //没有找到
	return l->data;
}

