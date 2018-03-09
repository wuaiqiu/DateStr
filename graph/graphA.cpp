#include <iostream>
using namespace std;

struct Graph{
	int arcs[5][5]; //初始化5*5的矩阵,0表示不连接
	int vexnum,arcnum; //vexnum为顶点数，arcnum为边数
};

//创建无向网（带权的无向图）,邻接矩阵法
void createGraphA(Graph &G) {
	int i, j, v1, v2;
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	for (i = 0; i < G.arcnum; i++) {
		cout << i + 1 << ":v1 ->v2(v1 v2):";
		scanf("%d%d", &v1, &v2);
		G.arcs[v1][v2] = 1;
		G.arcs[v2][v1] = 1;
	}
}
