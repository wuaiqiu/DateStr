#include <iostream>
using namespace std;

struct BitNode{
	int index;
	BitNode *lchild,*rchild;
};

//利用先序构建二叉树,叶子节点要以两个子空节点结束
void createTree(BitNode* &T){
	int index;
	cout<<"input:";
	scanf("%d",&index);
	if(!index)T=NULL; //0表示空节点
	else {
		T=(BitNode*)malloc(sizeof(BitNode));
		T->index=index;
		createTree(T->lchild);
		createTree(T->rchild);
	}
}

//先序遍历（递归）
void preOrderTraverse(BitNode* &T){
	if(T){
		cout<<T->index<<"  ";
		preOrderTraverse(T->lchild);
		preOrderTraverse(T->rchild);

	}
}


//中序遍历（递归）
void inOrderTraverse(BitNode* &T){
	if(T){
		inOrderTraverse(T->lchild);
		cout<<T->index<<"  ";
		inOrderTraverse(T->rchild);
	}
}


//后序遍历（递归）
void postOrderTraverse(BitNode* &T){
	if(T){
		postOrderTraverse(T->lchild);
		postOrderTraverse(T->rchild);
		cout<<T->index<<"  ";
	}
}
