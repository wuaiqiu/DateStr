#define LH +1
#define EH 0
#define RH -1

//构建平衡二叉树
struct BitNode {
	int data;
	int bf; //平衡因子；|右子树深度 - 左子树深度|
	BitNode *lchild, *rchild;
};

//右旋
void R_Rotate(BitNode* &T) {
	BitNode* lc = T->lchild;
	T->lchild = lc->rchild;
	lc->rchild = T;
	T = lc;
}

//左旋
void L_Rotate(BitNode* &T) {
	BitNode* rc = T->rchild;
	T->rchild = rc->lchild;
	rc->lchild = T;
	T = rc;
}
//平衡树（左平衡）
void leftBalance(BitNode* &T) {
	BitNode* lc = T->lchild; //lc为左节点
	switch (lc->bf) {
	case LH:  //(1)右旋:T的【左子树的左子树】插入节点
		T->bf = lc->bf = EH;
		break;
	case RH: //(2)左右旋：T的【左子树的右子树】插入节点
		BitNode* rd = lc->rchild; //rd为左节点的右节点
		switch (rd->bf) {
		case LH:
			T->bf = RH;
			lc->bf = EH;
			break;
		case RH:
			T->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		L_Rotate(T->lchild); //不要写成lc
		break;
	}
	R_Rotate(T);
}

//平衡树（右平衡）
void rightBalance(BitNode* &T) {
	BitNode* rc = T->rchild; //rc为右子树
	switch (rc->bf) {
	case RH: //(3)左旋:T的【右子树的右子树】插入节点
		T->bf = rc->bf = EH;
		break;
	case LH: //(4)右左旋：T的【右子树的左子树】插入节点
		BitNode* ld = rc->lchild; //ld为右子树的左子树
		switch (ld->bf) {
		case RH:
			T->bf = LH;
			rc->bf = EH;
			break;
		case LH:
			T->bf = EH;
			rc->bf = RH;
			break;
		}
		ld->bf = EH;
		R_Rotate(T->rchild); //不要写成rc
		break;
	}
	L_Rotate(T);
}

//插入树（平衡二叉树，二叉排序树的升级）,falg表示是否长高，1表示长高，0表示没长
int insertAVL(BitNode* &T, int key, int &flag) {
	if (!T) { //T节点为空
		T = (BitNode*) malloc(sizeof(BitNode));
		T->data = key;
		T->bf = EH;
		T->lchild = T->rchild = NULL;
		flag = 1;
	} else { //T节点不为空时
		if (key == T->data) {
			return 0;
		} //当节点存在时退出这层递归
		else if (key < T->data) { //1.左边插入节点
			if (!insertAVL(T->lchild, key, flag)) {
				return 0;
			} //当节点存在时退出这层递归
			if (flag) { //长高后平衡
				switch (T->bf) {
				case LH:
					leftBalance(T); //左平衡
					flag = 0;
					break;
				case EH:
					T->bf = LH;
					flag = 1;
					break;
				case RH:
					T->bf = EH;
					flag = 0;
					break;
				}
			}
		} else {  //2.右边插入节点
			if (!insertAVL(T->rchild, key, flag)) {
				return 0;
			} //当节点存在时退出这层递归
			if (flag) { //长高后平衡
				switch (T->bf) {
				case LH:
					T->bf = EH;
					flag = 0;
					break;
				case EH:
					T->bf = RH;
					flag = 1;
					break;
				case RH:
					rightBalance(T);
					flag = 0;
					break;
				}
			}
		}
	}
	return 1; //成功插入
}