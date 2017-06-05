#include <iostream>
using namespace std;

typedef struct BitNode{
	int data;
	struct BitNode *lchild,*rchild;
}BitNode,*Bitree;



//利用先序构建二叉树,叶子节点要以两个子空节点结束
void createTree(Bitree &T){
	int ch;
	cout<<"input:";
	scanf("%d",&ch);
	if(!ch)T=NULL; //0表示空节点
	else {
		T=(Bitree)malloc(sizeof(BitNode));
		T->data=ch;
		createTree(T->lchild);
		createTree(T->rchild);
	}
}

//先序遍历（递归）
void preOrderTraverse(Bitree T){
	if(T){
		cout<<T->data<<"  ";
		preOrderTraverse(T->lchild);
		preOrderTraverse(T->rchild);

	}
}


//中序遍历（递归）
void inOrderTraverse(Bitree T){
	if(T){
		inOrderTraverse(T->lchild);
		cout<<T->data<<"  ";
		inOrderTraverse(T->rchild);
	}
}


//后序遍历（递归）
void postOrderTraverse(Bitree T){
	if(T){
		postOrderTraverse(T->lchild);
		postOrderTraverse(T->rchild);
		cout<<T->data<<"  ";
	}
}
