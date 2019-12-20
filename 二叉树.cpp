#include<stdio.h>
#include<stdlib.h>

typedef char telemtype;
typedef struct BiTNode{
	telemtype data;
	struct BiTNode *lchild,*rchild; 
}BiTNode,*BiTree;

void createTree(BiTree &T){
	telemtype ch;
	scanf("%c",&ch);
	if(ch=='*') T=NULL;
	else{
		T=(BiTNode*)malloc(sizeof(BiTNode));
		T->data=ch;
		createTree(T->lchild);
		createTree(T->rchild);
	}
}

void visit(telemtype a){
	printf("%3c",a);
}

void preOrder(BiTree T)//preorder is mean,the root date first to print.
{
	if(T){
		visit(T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inOrder(BiTree T){
	if(T){
		inOrder(T->lchild);
		visit(T->data);
		inOrder(T->rchild);
	}
}

void exchange(BiTree &T){
	BiTree p;
	if(T!=NULL){
		exchange(T->lchild);
		exchange(T->rchild);
		p=T->lchild;
		T->lchild=T->rchild;
		T->rchild=p;}
}

//the number of leaves
int leaf(BiTree T){
	if(T==NULL) return 0;
	if(T->lchild==NULL&&T->rchild==NULL)
		return 1;
	return leaf(T->lchild)+leaf(T->rchild);
}

//the depth of tree
int depthq(BiTree &T){
	int depth;
	int ld,rd;
	if(T==NULL) return 0;
	else{
		ld=depthq(T->lchild);
		rd=depthq(T->rchild);
		depth=(ld>rd?ld:rd)+1;
	}
	return depth;
}

void main(){
	BiTree T;
	int l,d;
	printf("please enter the elements of the BiTree:\n");
	createTree(T);
	preOrder(T);
	exchange(T);
	printf("\n");
	l=leaf(T);
	d=depthq(T);
	printf("%2d,%2d",l,d);
	printf("\n");
	inOrder(T);
	printf("\n");
	preOrder(T);
}
