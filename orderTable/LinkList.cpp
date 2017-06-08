#include <iostream>
using namespace std;

//链式存储实现线性表(单链表)
typedef struct LNode {
	int data;
	struct LNode *next;
} LNode, *LinkList; //从1开始

//插入数据,位置pos[1..n],L为头结点，L->next为第一个节点
void insertLinkList(LinkList &L, int pos, int data) {
	if (!L) {
		L = (LinkList) malloc(sizeof(LNode));
		LinkList s = (LinkList) malloc(sizeof(LNode));
		s->data = data;
		s->next = NULL;
		L->next = s;
	} else {
		int j = 0;
		LinkList l = L; //赋值，不能在原链表上操作
		while (l && j < pos - 1) { //寻找前一个节点
			l = l->next;
			j++;
		}
		if (j != pos - 1)
			return; //没有找到
		LinkList s = (LinkList) malloc(sizeof(LNode));
		s->data = data;
		s->next = l->next;
		l->next = s;
	}
}

//删除数据
int deleteLinkList(LinkList &L, int pos) {
	int j = 0, data;
	LinkList l = L;
	while (l && j < pos - 1) { //寻找前一个节点
		l = l->next;
		j++;
	}
	if (j != pos - 1)
		return -1; //没有找到
	LinkList p = l->next; //要删除的数据
	data = p->data;
	l->next = l->next->next;
	free(p);
	return data;
}

//查询数据
int locateLinkList(LinkList L, int pos) {
	int j = 0;
	LinkList l = L;
	while (l && j < pos) { //寻找节点
		l = l->next;
		j++;
	}
	if (j != pos)
		return -1; //没有找到
	return l->data;
}
