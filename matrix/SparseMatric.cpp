#include <iostream>
using namespace std;

typedef struct {
	int i, j; //非零元素的行，列
	int data; //非零元素的数据
} Triple;

typedef struct {
	Triple datas[26]; //5*5矩阵，data[0]不使用
	int mu, nu, tu; //mu为矩阵的行数，nu为矩阵的列数，tu为矩阵的非零元素的个数
} TSMatric;

//利用三元组顺序表表示，以行为主序
void createMatric(TSMatric &T) {
	int i, mu, nu, tu;
	cout << "input rowNumber , colNumber and NozeroNumber(mu nu tu):";
	scanf("%d%d%d", &mu, &nu, &tu);
	T.mu = mu;
	T.nu = nu;
	T.tu = tu;
	for (i = 0; i <= mu * nu; i++) {
		T.datas[i].data = 0;
		T.datas[i].i = 0;
		T.datas[i].j = 0;
	}
	for (i = 1; i <= tu; i++) {
		int row, col, data;
		cout << i << ".  input row , col and data(row col data):";
		scanf("%d%d%d", &row, &col, &data);
		T.datas[i].i = row;
		T.datas[i].j = col;
		T.datas[i].data = data;
	}
}

//===============================================================

//普通转置（M为需要转置的矩阵，T为转置后的矩阵）
void transposeMatric(TSMatric M, TSMatric &T) {
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;

	int q, col, p, i;
	for (i = 0; i <= T.mu * T.nu; i++) { //初始化
		T.datas[i].data = 0;
		T.datas[i].i = 0;
		T.datas[i].j = 0;
	}
	if (T.tu) {
		q = 1;
		for (col = 1; col <= M.nu; col++) { //遍历M的每一列中的每一个元素，找到与列号对应的元素，放入的T中
			for (p = 1; p <= M.tu; ++p) {
				if (M.datas[p].j == col) { //当元素的列与当前列号相等时
					T.datas[q].j = M.datas[p].i;
					T.datas[q].i = M.datas[p].j;
					T.datas[q].data = M.datas[p].data;
					++q;
				}
			}
		}
	}

}

//===============================================================

//快速转置,并不需要每次都要遍历列
void fastTransposeMatric(TSMatric M, TSMatric &T) {
	int col, p, q, i;
	int num[M.nu + 1]; //每列的非零元素个数,num[0]不使用
	int cpot[M.nu + 1]; //每列非零元素的在T的起始位置
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	for (i = 0; i <= T.mu * T.nu; i++) { //初始化
		T.datas[i].data = 0;
		T.datas[i].i = 0;
		T.datas[i].j = 0;
	}

	if (T.tu) {
		for (col = 0; col <= M.nu; col++)
			num[col] = 0; //初始化num数组
		for (col = 1; col <= M.tu; col++)
			++num[M.datas[col].j]; //赋值num
		cpot[1] = 1;
		for (col = 2; col <= M.tu; col++)
			cpot[col] = cpot[col - 1] + num[col - 1]; //初始化cpot
		for (p = 1; p <= M.tu; p++) {
			col = M.datas[p].j;
			q = cpot[col]; //找到起始位置
			T.datas[q].i = M.datas[p].j;
			T.datas[q].j = M.datas[p].i;
			T.datas[q].data = M.datas[p].data;
			++cpot[col]; //起始位置向后退一步

		}
	}
}

