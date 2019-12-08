#include<stdio.h>
#include<stdlib.h>

#define maxvex 100

typedef int edgetype;
typedef char vertextype;

typedef struct edgeNode{
	int adjvex;
	edgetype info;
	struct edgeNode *next;
}EdgeNode;

typedef struct vertexNode{
	vertextype data;
	EdgeNode *firstedge;
}VertexNode,AdjList[maxvex];

typedef struct{
	AdjList adjlist;
	int numNodes,numEdges;//��ǰ�������ͱ��� 
}GraphAdjList;

//����ͼ���ڽӱ�ṹ
void createAlGraph(GraphAdjList *G){
	int i,j,k;
	EdgeNode *e;
	printf("�����붥�����ͱ���(�س�����)��\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges);
	getchar();
	for(i=0;i<G->numNodes;i++)
	{
		printf("�����붥�㣨�س���������");
		gets(&G->adjlist[i].data);
		G->adjlist[i].firstedge=NULL; 
	}
	
	for(k=0;k<G->numEdges;k++)//����ͼ������ͼ�Ļ��Ϳ���ֻ���������ڵ� 
	{
		printf("����ߣ�vi,vj���ϵĶ������"); 
		scanf("%d,%d",&i,&j);
		e=(EdgeNode*)malloc(sizeof(EdgeNode));
		e->next=NULL;
		e->adjvex=j;
		e->next=G->adjlist[i].firstedge;
		G->adjlist[i].firstedge=e;
		
		e=(EdgeNode*)malloc(sizeof(EdgeNode));
		e->next=NULL;
		e->adjvex=i;
		e->next=G->adjlist[j].firstedge;
		G->adjlist[j].firstedge=e;
	}
	
} 
/*
int DFS(GraphAdjList &G,edgetype v){//��G�ĵ�V���ڵ�������ȱ���ͼ
	if(v>G.numNodes-1) return -1;//�Ƿ���ڸýڵ�
	EdgeNode *p;
	printf("%c",G.adjlist[v-1].data);
	p=G.adjlist[v-1].firstedge;
	while(p->next)
	{
		if(p->adjvex==NULL)
			DFS(G,p->info);
		p=p->next;
	
	}
	return 0;
}*/

int main()
{
	GraphAdjList G;
	createAlGraph(&G);
	return 0;
}










