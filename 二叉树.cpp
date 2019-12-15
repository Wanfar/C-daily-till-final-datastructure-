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

void preOrder(BiTree T)//preorder is mean,root node traverse first¡£ 
{
	if(T){
		visit(T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
int main(){
	BiTree T;
	createTree(T);
	preOrder(T);
	return 0;
}
