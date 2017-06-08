#include <iostream>
using namespace std;

//顺序存储实现线性表，动态实现

typedef struct {
	int *elem;   //数组基址
	int length;
	int size;
} SqList; //SqList.elem[0..n];从零开始

//初始化线性表
void initSqList(SqList &L) {
	L.elem = (int *) malloc(10 * sizeof(int)); //初始化10的存储空间
	if (!L.elem)
		exit(0); //申请未成功则退出
	L.length = 0;
	L.size = 10;
}

//向前插入数据，pos(1...n)插入位置，data待插入数据
void insertSqList(SqList &L, int pos, int data) {
	int *p, *q;
	if (pos < 1 || pos > L.length + 1)
		return; //pos为非法数据
	if (L.length == L.size) { //当数组已满时，扩充数组
		int *NL = (int *) realloc(L.elem, (L.size + 10) * sizeof(int)); //复制L.elem数组并扩展数组
		if (!NL)
			exit(0); //申请失败退出
		L.elem = NL;
		L.size += 10;
	}
	p = &(L.elem[pos - 1]); //插入位置pos的地址
	for (q = &(L.elem[L.length - 1]); q >= p; q--)
		*(q + 1) = *q; //向后移位
	*p = data;
	L.length++;
}

//删除数据
int deleteSqList(SqList &L, int pos) {
	int *p, *q;
	int data;
	if (pos < 1 || pos > L.length + 1)
		return -1;
	p = &(L.elem[pos - 1]); //删除元素的位置
	data = *p;
	for (q = &(L.elem[L.length - 1]), p++; p <= q; p++)
		*(p - 1) = *p;
	L.length--;
	return data;
}

//查找数据，返回位置
int locateSqList(SqList L, int data) {
	int i = 0;
	while (i < L.length && *(L.elem++) != data)
		i++;
	if (i < L.length)
		return i + 1;
	else
		return -1;
}
