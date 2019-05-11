#include <stdio.h>
int adj[100][100];
int n,e;
int topo[100],itopo=0;

void dfs(int s,int vis[]){
	vis[s] = 1;
	int i;
	for(i=0;i<n;i++){
		if(!vis[i] && adj[s][i]){
			dfs(i,vis);
		}
	}
	topo[itopo++]=s;
}

int main(){
	printf("Enter number of nodes and edges - \n");
	scanf("%d %d",&n,&e);
	printf("Enter edges - \n");
	int i;
	for(i=0;i<e;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a][b]=1;
	}
	printf("The topological sort - \n");
	int vis[100];
	for(i=0;i<n;i++) vis[i]=0;
	for(i=0;i<n;i++){
		if(!vis[i])
			dfs(i,vis);
	}
	for(i=n-1;i>=0;i--) printf("%d ",topo[i]);
	return 0;
}