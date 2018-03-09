#include <iostream>
using namespace std;

struct BitNode{
	int index;
	int flag; //是否被访问过，1表示没被访问过
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
		T->flag=1;
		createTree(T->lchild);
		createTree(T->rchild);
	}
}

//先序遍历（非递归）,先边输出边压左节点，直到没有左节点，在将栈底的左节点（当有右节点）换成右节点，（没有右节点）出栈
void preOrderTraverse(BitNode* &T){
		BitNode* list[5];  //假设有5个节点，初始化栈
		int final=0;	 //栈顶指针
		list[final++]=T; //压入根节点
		while(final){  //当栈不为空时
			T=list[final-1];
			while(T&&T->flag){
				cout<<T->index<<"  ";
				T->flag=0;
				if(list[final-1]->lchild&&list[final-1]->lchild->flag)list[final++]=T->lchild;
				T=T->lchild;
			}
			//当有右孩子时，改变自身
			if(list[final-1]->rchild)list[final-1]=list[final-1]->rchild;
			else final--;
		}
}

//中序遍历（非递归），先压全部左节点，再输出栈底的左节点，后将栈底的左节点（当有右节点）换成右节点，（没有右节点）出栈
void inOrderTraverse(BitNode* &T){
			BitNode* list[5];
			int final=0;
			list[final++]=T;
			while(final){
				T=list[final-1];
				while(T&&T->flag){
					if(T->lchild&&T->lchild->flag)list[final++]=T->lchild;
					T=T->lchild;
				}
				if(list[final-1]->flag){
					cout<<list[final-1]->index<<" ";
					list[final-1]->flag=0;
				}
				if(list[final-1]->rchild)list[final-1]=list[final-1]->rchild;
				else final--;
			}
}

//后序遍历（非递归），先压右节点，再压左节点，后输出
void postOrderTraverse(BitNode* &T){
	BitNode* list[5];
	int final=0;
	list[final++]=T;
	while(final){
		T=list[final-1];
		while(T&&T->flag){
			if(T->rchild&&T->rchild->flag)list[final++]=T->rchild;
			if(T->lchild&&T->lchild->flag)list[final++]=T->lchild;
			T=T->lchild;
		}
		if(list[final-1]->flag){
			cout<<list[final-1]->index<<"  ";
			list[--final]->flag=0;
		}
	}
}