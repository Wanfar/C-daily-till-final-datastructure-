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
	int numNodes,numEdges;//当前顶点数和边数 
}GraphAdjList;

//建立图的邻接表结构
void createAlGraph(GraphAdjList *G){
	int i,j,k;
	EdgeNode *e;
	printf("请输入顶点数和边数(回车输入)：\n");
	scanf("%d,%d",&G->numNodes,&G->numEdges);
	getchar();
	for(i=0;i<G->numNodes;i++)
	{
		printf("请输入顶点（回车结束）：");
		gets(&G->adjlist[i].data);
		G->adjlist[i].firstedge=NULL; 
	}
	
	for(k=0;k<G->numEdges;k++)//无向图，有向图的话就可以只建立单个节点 
	{
		printf("输入边（vi,vj）上的顶点序号"); 
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
int DFS(GraphAdjList &G,edgetype v){//从G的第V个节点深度优先遍历图
	if(v>G.numNodes-1) return -1;//是否存在该节点
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










