#include <iostream>
using namespace std;

//循环队列，顺序存储，动态数组
typedef struct {
	int *base; //动态数组的基址,此处为5个单位空间
	int front; //头指针
	int rear; //尾指针
} SqQueue;

//初始化队列
void initQueue(SqQueue &L) {
	L.base = (int *) malloc(5 * sizeof(int));
	if (!L.base)
		exit(0);
	L.front = L.rear = 0;
}

//进队
void enterQueue(SqQueue &L, int data) {

	if ((L.rear + 1) % 5 == L.front)
		return; //队满退出
	L.base[L.rear] = data;
	L.rear = (L.rear + 1) % 5;
}

//出队，队空返回-1
int exitQueue(SqQueue &L) {
	if (L.front == L.rear)
		return -1; //队空时
	int data = L.base[L.front]; //队头第一个元素
	L.front = (L.front + 1) % 5;
	return data;
}
