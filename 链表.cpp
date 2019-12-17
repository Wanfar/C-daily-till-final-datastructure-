#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef struct LNode{
	elemtype data;
	struct LNode *next;
}LNode,*LinkList;

void initList(LinkList &L){//����һ���յĵ�����
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
		printf("����������Ԫ�أ�");
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
	printf("����Ԫ��Ϊ��");
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
		printf("ɾ��λ������");
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

int search(LinkList L,elemtype x){//�����Ƿ����Ԫ��x 
	LinkList p;
	int i=1;
	p=L->next;
	while(p&&p->data!=x){
		p=p->next;
		i++; 
	}
	if(!p) {
		printf("�����ڣ�"); 
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
	printf("����������Ԫ�ظ���:");
	scanf("%d",&m);
	createList(L,m);
	printList(L);
	printf("������Ҫɾ���ڼ�λ��Ԫ�أ�"); 
	scanf("%d",&n);
	e=deleteList(L,n,e);
	printf("��Ԫ��Ϊ��%d",e);
	printList(L);
	printf("������Ҫ���ҵ�Ԫ�أ�"); 
	scanf("%d",&x);
	s=search(L,x);
	if(s!=0)printf("��Ԫ��Ϊ��%d",s);
	i=length(L);
	printf("������Ϊ��%d",i);
	
	return 0;
} 
