#include <iostream>
using namespace std;

//定长顺序存储
typedef unsigned char SString[10]; //预定义9个字符的字符串（SString[0]为字符串的长度）

//普通串模式匹配(S为主串，T为模式串，pos为起始位置)
int index(SString S, SString T, int pos) {
	int i = pos, j = 1;
	int s = S[0] - 48;
	int t = T[0] - 48;
	while (i <= s && j <= t) {
		if (S[i] == T[j]) {
			++i;
			++j;
		} else {
			i = i - j + 2;
			j = 1;
		}
	}

	if (j > t)
		return i - t;
	else
		return 0;
}

//=================================================================

//getNext算法
int getNext(SString T, int index) {
	int next[3]; //next[0]为空，kmp算法要用
	int i = 1, j = 0;
	int t = T[0] - 48;
	next[1] = 0;
	while (i < t) {
		if (j == 0 || T[i] == T[j]) {
			++j;
			++i;
			next[i] = j;
		} else
			j = next[j];
	}
	return next[index];
}

//kmp字符串模式匹配
int kmpIndex(SString S, SString T, int pos) {
	int i = pos, j = 1;
	int s = S[0] - 48;
	int t = T[0] - 48;
	while (i <= s && j <= t) {
		if (j == 0 || S[i] == T[j]) {
			++i;
			++j;
		} else {
			j = getNext(T, j);
		}
	}
	if (j > t)
		return i - t;
	else
		return 0;
}
