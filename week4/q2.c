#include<stdio.h>
#include<stdlib.h>

int push[100],pop[100],ipu=0,ipo=0;
void dfs(int adj[][100],int s,int vis[],int n){
	vis[s]=1;
	push[ipu++]=s;
	printf("%d ",s);
	int i;
	for(i=0;i<n;i++){
		if(adj[s][i]==1 && !vis[i])
			dfs(adj,i,vis,n);
	}
	pop[ipo++]=s;
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

	printf("The dfs orders are-\n");
	int vis[n];
	for(i=0;i<n;i++) vis[i]=0;
	for(i=0;i<n;i++){
		if(!vis[i]){
			dfs(adj,i,vis,n);
			printf("\n");
		}
	}

	printf("Push order -\n");
	for(i=0;i<ipu;i++) printf("%d ",push[i]);
	printf("\nPop order-\n");
	for(i=0;i<ipo;i++) printf("%d ",pop[i]);
	return 0;
}