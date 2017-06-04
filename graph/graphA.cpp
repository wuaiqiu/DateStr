#include <iostream>
using namespace std;

typedef struct {
	int weight;  //弧上的权重，0表示不到达
} ArcCell, ArcTable[5][5]; //临接矩阵，10个节点的图分别为0...4

typedef struct {
	ArcTable arcs;
	int vexnum, arcnum; //vexnum顶点数，arcnum边数
} Graph, *MGraph; //图定义

//创建无向网（带权的无向图）,邻接矩阵法
void createGraphA(MGraph &G) {
	int i, j, v1, v2, weight;
	//初始化临接矩阵
	for (i = 0; i < G->vexnum; i++)
		for (j = 0; j < G->vexnum; j++)
			G->arcs[i][j].weight = 0;
	for (i = 0; i < G->arcnum; i++) {
		cout << i + 1 << ":v1 ->v2  and weight(v1 v2 weight):";
		scanf("%d%d%d", &v1, &v2, &weight);
		G->arcs[v1][v2].weight = weight;
		G->arcs[v2][v1].weight = weight;
	}
}

