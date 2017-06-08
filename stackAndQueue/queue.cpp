#include <iostream>
using namespace std;

//列队，（链式存储）

typedef struct QNode { //链接节点
	int data;
	struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
	QueuePtr front; //队头指针
	QueuePtr rear; //队尾指针
} LinkQueue; //队列头节点（不使用）

//初始化列队，L->next为第一个节点
void initQueue(LinkQueue &L) {
	L.front = L.rear = (QueuePtr) malloc(sizeof(QNode)); //初始化列队头，尾指针
	if (!L.front)
		exit(0); //申请失败退出
	L.front->next = NULL;
}

//进队
void enterQueue(LinkQueue &L, int data) {
	QueuePtr p = (QueuePtr) malloc(sizeof(QNode)); //初始化节点
	if (!p)
		exit(0);
	p->data = data;
	p->next = NULL;
	L.rear->next = p; //改变列尾指针
	L.rear = p;
}

//出队,队空返回-1，否则返回对应数据
int exitQueue(LinkQueue &L) {

	if (L.front == L.rear)
		return -1; //当队空时
	QueuePtr p = L.front->next; //p指向队头第一个元素
	int data = p->data; //队头第一个元素的数据
	L.front->next = p->next; //出队
	if (L.rear == p)
		L.rear = L.front; //当只有一个元素时L.rear=L.front=NULL
	return data;
}
