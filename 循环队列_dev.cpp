#include<stdio.h>
#include<stdlib.h>
#define maxsize 20
typedef int elemtype;
typedef struct{
	elemtype *base;
	int front;
	int rear;
}queue;

int init(queue &Q){//Initialize the queue.
	Q.base=(elemtype*)malloc(maxsize*sizeof(elemtype));
	if(!Q.base) return -1;
	Q.front=Q.rear;
	return 0;
}

int length(queue Q){//return the queue's length.
	return (Q.rear-Q.front+maxsize)%maxsize;
}

int enQueue(queue *Q,elemtype e){//adding elements to the queue.
	if((Q->rear+1)%maxsize==Q->front) return -1;//the queue is full.
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%maxsize;
	return 0;
}

int deQueue(queue &Q,elemtype &e){//delete element from the queue and return the element.
	if(Q.front==Q.rear) return -1;//the queue is empty!
	e=Q.base[Q.front];//!first in first out!(FIFO)
	Q.front=(Q.front+1)%maxsize;
	return 0;
}

int printQueue(queue Q){
	if(Q.front==Q.rear) return -1;//the queue is empty!
	if(!Q.base){
		printf("Not exist!");
		return -1;}
	int i;
	printf("The queue is ");
	for(i=0;i<(Q.rear-Q.front+maxsize)%maxsize;i++)
	{
		printf("%3d",Q.base[Q.front+i]);
	}
	return 0;
}

//void destroyQueue(queue *Q){
//	Q->base=NULL;
//	Q->front=0;
//	Q->rear=0;
//	free(Q->base);
//} 


int main(){
	queue Q;
	init(Q);
	int n,i,e;
	printf("please enter the quantity of queue:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		enQueue(&Q,e);
	}
	deQueue(Q,e);
	printf("%d\n",e);
	enQueue(&Q,1);
	enQueue(&Q,2);
	enQueue(&Q,3);
	enQueue(&Q,4);
	printQueue(Q);
	return 0;

}
