#include<stdio.h>

void inputGraph(int *nodes,int *edges,int adj[][100],int weights){
	printf("Enter number of nodes and edges-\n");
	scanf("%d %d",nodes,edges);
	int n = *nodes; int m = *edges;
	printf("Enter edges - \n");
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d",&a,&b);
		if(weights == 1) {
			scanf("%d",&c);
			adj[a][b]=c;
		}else adj[a][b]=1;
	}
}

void printGraph(int n,int adj[][100]){
	for(int i=0;i<n;i++){ 
		for(int j=0;j<n;j++) printf("%d ",adj[i][j]);
		printf("\n");
	}
}
