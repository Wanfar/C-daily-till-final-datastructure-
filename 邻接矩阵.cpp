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
	printf("请输入顶点数和边数：");
	scanf("%d,%d",&G->numNodes,&G->numedges);
	getchar();//接收回车符，不然会读入顶点内 
	for(i=0;i<G->numNodes;i++)
	{
		printf("请输入顶点信息：\n"); 
		gets(&G->vexs[i]);
		//scanf("%c",G->vexs[i]);
	}
	for(i=0;i<G->numNodes;i++)//矩阵初始化 
	{
		for(j=0;j<G->numedges;j++)
		{
			G->arc[i][j]=0;
		}
	}
	for(k=0;k<G->numedges;k++)
	{
		printf("输入边（vi,vj）上的下边i，下标j和权值w:");
		scanf("%d,%d,%d",&i,&j,&w);
		G->arc[i][j]=w;
		G->arc[i][j]=G->arc[j][i];//无向图，矩阵对称！ 
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
