#include <stdio.h>
#include "graph.h"
int main(){
	int n,m;
	int adj[100][100];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++){adj[i][j]=0;}
	inputGraph(&n,&m,adj,0);
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
			}
		}
	}
	printf("Transitive closure is - \n");
	printGraph(n,adj);
	return 0;
}