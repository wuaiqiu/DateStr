#include <iostream>
using namespace std;

//====================================================

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

//================================================================
int visited[5] = { 0, 0, 0, 0, 0 }; //0表示没有访问，1表示访问过
int queue[5]; //初始化一个队列
int first = 0, final = 0; //列队的头，尾指针
//循环遍历
void BFS(Graph &G, int i) {
	ArcNode *temp = NULL;
	queue[final++] = i; //进队
	visited[i]=1;
	while (final != first) {
		int v = queue[first++]; //出队
		cout << v << "-->";
		temp = G.list[v].next;
		while (temp) {
			if (!visited[temp->index]){
				queue[final++] = temp->index; //进队
				visited[temp->index]=1;
			}
			temp = temp->next;
		}
   }
}
//广度遍历
void BFSTraverse(Graph &G) {
	for (int i = 0; i < G.vexnum; i++) { //防止非连通
		if (!visited[i])
			BFS(G, i);
	}
}