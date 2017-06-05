#include <iostream>
using namespace std;

typedef struct BitNode{
	int data;
	struct BitNode *lchild,*rchild;
	int flag; //是否被访问过，1表示没被访问过
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
		T->flag=1;//用于非递归遍历
		createTree(T->lchild);
		createTree(T->rchild);
	}
}


//先序遍历（非递归）,先输出，再压左节点，后压右节点
void preOrderTraverse(Bitree T){
		Bitree list[5];  //假设有5个节点，初始化栈
		int final=-1;//栈顶指针
		list[++final]=T; //压入根节点
		while(final+1){  //当栈不为空时
			T=list[final];
			while(T&&T->flag){
				cout<<T->data<<"  ";
				T->flag=0;
				if(list[final]->lchild&&list[final]->lchild->flag)list[++final]=T->lchild;
				T=T->lchild;
			}
			if(list[final]->rchild)list[final]=list[final]->rchild;//当有右孩子时，改变自身
			else final--;
		}
}


//中序遍历（非递归），先压左节点，再输出，后压右节点
void inOrderTraverse(Bitree T){
			Bitree list[5];  	//假设有5个节点，初始化栈
			int final=-1;		//栈顶指针
			list[++final]=T; 	//压入根节点
			while(final+1){  	//当栈不为空时
				T=list[final];
				while(T&&T->flag){ //依次把当前节点的左孩子压栈
				if(T->lchild&&T->lchild->flag)list[++final]=T->lchild;
					T=T->lchild;
				}
			if(list[final]->flag){
				cout<<list[final]->data<<" ";
				list[final]->flag=0;
			}
			if(list[final]->rchild)list[final]=list[final]->rchild;//当有右孩子时，改变自身
			else final--; //出栈
			}
}

//后序遍历（非递归），先压左节点，再压右节点，后输出
void postOrderTraverse(Bitree T){
	Bitree list[5];
	int final=-1;
	list[++final]=T;
	while(final+1){
		T=list[final];
		while(T&&T->flag){
			if(T->rchild&&T->rchild->flag)list[++final]=T->rchild;
			if(T->lchild&&T->lchild->flag)list[++final]=T->lchild;
			T=T->lchild;
		}
		if(list[final]->flag){
			cout<<list[final]->data<<"  ";
			list[final--]->flag=0;
		}
	}
}
