#include<stdio.h>
#include<stdlib.h>

void bfs(int adj[][100],int s,int vis[],int n){
	int q[100];
	int i,f=0,r=0;

	q[r++]=s;
	vis[s]=1;
	while(f<r){
		int top = q[f++];
		printf("%d ",top);
		for(i=0;i<n;i++){
			if(adj[top][i] && !vis[i]){
				vis[i]=1;
				q[r++]=i;
			}
		}
	}
}

int main(){
	int i,j,n,e;
	printf("Enter number of vertices and edges-\n");
	scanf("%d %d",&n,&e);
	printf("Enter edges-\n");
	int adj[100][100];
	for(i=0;i<n;i++) for(j=0;j<n;j++) adj[i][j]=0;

	for(i=0;i<e;i++){
		int a,b; scanf("%d %d",&a,&b);
		adj[a][b]=1;
		adj[b][a]=1;
	}
	printf("The bfs orders are-\n");
	int vis[n];
	for(i=0;i<n;i++) vis[i]=0;
	for(i=0;i<n;i++){
		if(!vis[i]){
			bfs(adj,i,vis,n);
			printf("\n");
		}
	}
	return 0;
}