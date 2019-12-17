#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct LNode{
	elemtype data;
	struct LNode *next;
}LNode,*LinkList;

void initList(LinkList &L){//构造一个空的单链表
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL; 
} 


void createList(LinkList &L,int m){
	LinkList p,r;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	r=L;
	for(int i=0;i<m;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		p->next=NULL;
		printf("请输入链表元素：");
		scanf("%d",&p->data);
		r->next=p;
		r=p; 
	}
	
} 

int GetElem_L(LinkList L,int i,elemtype &e){
	LinkList p;
	int j;
	p=L->next;
	j=1;
	while(p&&j<i){
		p=p->next;
		j++;
	}
	if(!p||j>i) return -1;
	e=p->data;
	return 0;
}

int ListInsert(LinkList &L,int i,elemtype e){
	LinkList p,s;
	int j;
	p=L;
	for(j=0;j<i-1;j++)
		if(p) p=p->next;
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;s->next=p->next;
	p->next=s;
	return 0;
}

void printList(LinkList L){
	LinkList p;
	p=L->next;
	printf("链表元素为：");
	while(p){
		printf("%3d",p->data);
		p=p->next;
	}
	printf("\n");
}


int deleteList(LinkList &L,int i,elemtype &e){
	LinkList p,r;
	int j=0;
	p=L;
	while(p&&j<i-1){
		p=p->next;
		j++;
	}
	if(!p||j>i-1){
		printf("删除位置有误！");
		return -1; 
	}
	else{
		r=p->next;
		p->next=r->next;
		e=r->data;
		free(r);
		return e;
	}
} 

int search(LinkList L,elemtype x){//查找是否存在元素x 
	LinkList p;
	int i=1;
	p=L->next;
	while(p&&p->data!=x){
		p=p->next;
		i++; 
	}
	if(!p) {
		printf("不存在！"); 
		return 0;
	} 
	else return i;
}

int length(LinkList L){
	LinkList p;
	int i=0;
	p=L->next;
	while(p){
		p=p->next;
		i++;
	}
	return i;
}

int main(){
	LinkList L;
	int m,n,e;
	int s,x,i;
	printf("请输入链表元素个数:");
	scanf("%d",&m);
	createList(L,m);
	printList(L);
	printf("请输入要删除第几位的元素："); 
	scanf("%d",&n);
	e=deleteList(L,n,e);
	printf("该元素为：%d",e);
	printList(L);
	printf("请输入要查找的元素："); 
	scanf("%d",&x);
	s=search(L,x);
	if(s!=0)printf("该元素为：%d",s);
	i=length(L);
	printf("链表长度为：%d",i);
	
	return 0;
} 
