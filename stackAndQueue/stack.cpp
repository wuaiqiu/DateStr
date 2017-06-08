#include <iostream>
using namespace std;

//栈（顺序表示，top指向下一个将要插入的元素）动态数组
typedef struct {
	int *base; //栈底指针
	int *top; //栈顶指针
	int size; //栈空间大小,此处为10个空间
} SqStack;

//初始化栈
void initStack(SqStack &S) {
	S.base = (int *) malloc(10 * sizeof(int)); //初始化栈底指针
	if (!S.base)
		exit(0); //未申请成功时退出
	S.top = S.base; // 初始化栈顶指针
	S.size = 10;
}

//栈是否为空,1为空，0不为空
int empty(SqStack S) {
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

//进栈，data为进栈数据
void push(SqStack &S, int data) {
	if (S.top - S.base == S.size) { //栈满时,扩展栈空间
		S.base = (int *) realloc(S.base, (S.size + 10) * sizeof(int));
		if (!S.base)
			exit(0);
		S.top = S.base + S.size;
		S.size += 10;
	}
	*S.top++ = data; //进栈
}

//出栈,当栈空返回-1，否则返回栈顶数据
int pop(SqStack &S) {
	if (S.top == S.base)
		return -1;
	else
		return *--S.top;
}

