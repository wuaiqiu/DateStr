#include <iostream>
using namespace std;

//====================================================

typedef struct ArcNode {
	int index; //下标
	struct ArcNode *next; //下一节点的指针
} ArcNode, *ArcNodes;

//链表头定义
typedef struct {
	ArcNodes frist; //头结点的下一个节点指针
} node, nodelist[5];

//图定义
typedef struct {
	nodelist list;
	int vexnum, arcnum;
} Graph, *MGraph;

//创建有向图，邻接表法
void createGraphB(MGraph &G) {
	int i, v1, v2;
	ArcNodes temp;
	//初始化链表头
	for (i = 0; i < G->vexnum; i++) {
		G->list[i].frist = NULL;
	}

	for (i = 0; i < G->arcnum; i++) {
		cout << "v1->v2(v1 v2):";
		scanf("%d%d", &v1, &v2);
		ArcNodes node = (ArcNodes) malloc(sizeof(ArcNode));
		node->index = v2;
		node->next = NULL;
		temp = G->list[v1].frist; //临时指针
		if (temp) {
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = node;
		} else {
			G->list[v1].frist = node; //不写temp，因为temp=null
		}
	}
}

//================================================================
int visited[5] = { 0, 0, 0, 0, 0 }; //0表示没有访问，1表示访问过
int queue[10]; //初始化一个队列
int first = 0, final = 0; //列队的头，尾指针
//循环遍历
void BFS(MGraph G, int i) {
	ArcNodes temp = NULL;
	queue[final++] = i; //进队
	while (final != first) {
		int v = queue[first++]; //出队
		visited[v] = 1;
		cout << v << "-->";
		temp = G->list[v].frist;
		while (temp) {
			if (!visited[temp->index])
				queue[final++] = temp->index; //进队
			temp = temp->next;
		}

	}

}

//广度遍历
void BFSTraverse(MGraph G) {
	int i;

	for (i = 0; i < G->vexnum; i++) { //防止非连通
		if (!visited[i])
			BFS(G, i);
	}
}
