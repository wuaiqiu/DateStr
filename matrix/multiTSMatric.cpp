#include <iostream>
using namespace std;

typedef struct {
	int i, j; //非零元素的行，列
	int data; //非零元素的数据
} Triple;

typedef struct {
	Triple datas[26];
	int rpos[6]; //每行非零元素的起始位置
	int mu, nu, tu;//行数,列数,非零元素个数
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
	T.rpos[1] = 1; //初始化rpos
	for (i = 1; i <= tu; i++) {
		int row, col, data;
		cout << i << ".  input row , col and data(row col data):";
		scanf("%d%d%d", &row, &col, &data);
		T.datas[i].i = row;
		T.datas[i].j = col;
		T.datas[i].data = data;
		if (i > 1 && T.datas[i].i != T.datas[i - 1].i)
			T.rpos[T.datas[i].i] = i;
	}
}

//矩阵乘法
void multiMatric(TSMatric M1, TSMatric M2, TSMatric &T) {
	if (M1.nu != M2.mu)
		return; //矩阵相乘的两个矩阵，必须M1的列数等于M2的行数
	T.mu = M1.mu;
	T.nu = M2.nu;
	T.tu = 0;
	if (M1.tu * M2.tu != 0) { //T为非零矩阵
		int i, j, row1, np1, row2, np2, tcol;

		for (i = 0; i <= T.mu * T.nu; i++) { //初始化
			T.datas[i].data = 0;
			T.datas[i].i = 0;
			T.datas[i].j = 0;
		}

		for (row1 = 1; row1 <= M1.mu; row1++) { //遍历M1的每一行
			int sum[6] = { 0, 0, 0, 0, 0, 0 }; //M1当前行与M2列的累加器清零
			T.rpos[row1] = T.tu + 1; //T每行非零元素的起始位置

			if (row1 < M1.mu)
				np1 = M1.rpos[row1 + 1]; //np1为M1当前一行的下一行起始位置
			else
				np1 = M1.tu + 1;

			for (i = M1.rpos[row1]; i < np1; i++) { //遍历M1当前行的所有非零元素
				row2 = M1.datas[i].j; //求出M2所对应的行号

				if (row2 < M2.mu)
					np2 = M2.rpos[row2 + 1]; //np2为M2当前一行的下一行起始位置
				else
					np2 = M2.tu + 1;

				for (j = M2.rpos[row2]; j < np2; j++) { //遍历M2当前行的所有非零元素
					tcol = M2.datas[j].j; //T矩阵的列号
					sum[tcol] += M1.datas[i].data * M2.datas[j].data;
				}
			}

			//记录M1当前行的乘积插入T
			for (tcol = 1; tcol <= T.nu; tcol++) {
				if (sum[tcol]) { //当列存在时
					++T.tu;
					T.datas[T.tu].i = row1;
					T.datas[T.tu].j = tcol;
					T.datas[T.tu].data = sum[tcol];
				}
			}
		}
	}
}
