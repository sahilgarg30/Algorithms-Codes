#include <stdio.h>
#include "graph.h"
int n,e;
int adj[100][100],sptSet[100];

int findMin(int node){
	int index,min=99999;
	for(int i=0;i<n;i++){
		if(!sptSet[i] && adj[node][i]<=min){
			min = adj[node][i];
			index = i;
		}
	}
	return index;
}

int main(){ 
	 for(int i=0;i<100;i++) for(int j=0;j<100;j++) adj[i][j]=99999;
	 for(int i=0;i<100;i++) {adj[i][i] = 0;sptSet[i]=0;}
	 inputGraph(&n,&e,adj,1);

	 printf("Enter node to which all distances found - \n");
	 int node;
	 scanf("%d",&node);
	 printf("Minimum distances to all nodes are - \n");

	 for(int i=0;i<n;i++){
	 	int m = findMin(node);
	 	printf("Node %d - %d \n",m,adj[node][m]);
	 	sptSet[m] = 1;
	 	for(int i=0;i<n;i++){
	 		if(adj[node][m] == 99999) break;
	 		if(!sptSet[i] && adj[node][i]>adj[node][m]+adj[m][i])
	 			adj[node][i] = adj[node][m] + adj[m][i];
	 	}
	 }
}