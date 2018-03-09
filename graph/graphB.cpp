#include <iostream>
using namespace std;
//链表节点定义
struct ArcNode {
	int index; //下标
	ArcNode *next; //下一节点
};

struct Graph{
	ArcNode list[5];
	int vexnum,arcnum;
};

//创建有向图，邻接表法
void createGraphB(Graph &G) {
	int i, v1, v2;
	ArcNode *temp;
	//初始化链表头
	for (i = 0; i < G.vexnum; i++) {
		G.list[i].index=i;
		G.list[i].next = NULL;
	}
	for (i = 0; i < G.arcnum; i++) {
		cout << "v1->v2(v1 v2):";
		scanf("%d%d", &v1, &v2);
		ArcNode *node=(ArcNode*)malloc(sizeof(ArcNode));
		node->index = v2;
		node->next = NULL;
		temp = G.list[v1].next;
		if (temp) {
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = node;
		} else {
			G.list[v1].next = node;
		}
	}
}