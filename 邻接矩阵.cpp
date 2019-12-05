#include<stdio.h>
#include<stdlib.h>
#define maxvex 100
typedef int edgetype;
typedef char vertextype;
typedef struct{
	vertextype vexs[maxvex];
	edgetype arc[maxvex][maxvex];
	int numNodes,numedges;
}MGraph;

void createMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("�����붥�����ͱ�����");
	scanf("%d,%d",&G->numNodes,&G->numedges);
	getchar();//���ջس�������Ȼ����붥���� 
	for(i=0;i<G->numNodes;i++)
	{
		printf("�����붥����Ϣ��\n"); 
		gets(&G->vexs[i]);
		//scanf("%c",G->vexs[i]);
	}
	for(i=0;i<G->numNodes;i++)//�����ʼ�� 
	{
		for(j=0;j<G->numedges;j++)
		{
			G->arc[i][j]=0;
		}
	}
	for(k=0;k<G->numedges;k++)
	{
		printf("����ߣ�vi,vj���ϵ��±�i���±�j��Ȩֵw:");
		scanf("%d,%d,%d",&i,&j,&w);
		G->arc[i][j]=w;
		G->arc[i][j]=G->arc[j][i];//����ͼ������Գƣ� 
	} 
}

int show_graph(MGraph G){
	int i,j;
	for(i=0;i<G.numNodes;i++)
	{
		for(j=0;j<G.numNodes;j++)
		printf("%d",G.arc[i][j]);
		printf("\n");
	}
	return 0;
}

int main(){
	MGraph G;
	createMGraph(&G);
	show_graph(G);
	return 0;
}
