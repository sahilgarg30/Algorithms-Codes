#include <stdio.h>
#include "graph.h"
int min(int a,int b){return a<b?a:b;}
int main(){
	int n,m;
	int adj[100][100];
	for(int i=0;i<100;i++) 
		for(int j=0;j<100;j++){
		if(i==j) adj[i][j]=0;
		else adj[i][j]=99999;}

	inputGraph(&n,&m,adj,1);
	
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
			}
		}
	}
	printf("The shortest path matrix is -\n");
	printGraph(n,adj);
	return 0;
}