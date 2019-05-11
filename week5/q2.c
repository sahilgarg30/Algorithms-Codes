#include <stdio.h>
int adj[100][100];
int n,e;
int topo[100],itopo=0;

void bfs(int s,int vis[],int incoming[]){
	int q[100],f=0,r=0;
	for(int i=0;i<n;i++){
		if(!vis[i] && incoming[i]==0)
			q[r++]=i;
	}

	while(f<r){
		int top = q[f];
		vis[top]=1;
		f++;
		topo[itopo++]=top;
		for(int i=0;i<n;i++){
			if(adj[top][i]==1 && !vis[i]){
				incoming[i]--;
				if(incoming[i]==0){
					q[r++]=i;
					vis[i]=1;
				}
			}
		}
	}
}
int main(){
	printf("Enter number of nodes and edges - \n");
	scanf("%d %d",&n,&e);
	printf("Enter edges - \n");
	int i;
	int incoming[100];
	for(i=0;i<n;i++) incoming[i]=0;
	for(i=0;i<e;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a][b]=1;
		incoming[b]++;
	}
	printf("The topological sort - \n");
	int vis[100];
	for(i=0;i<n;i++) vis[i]=0;
	for(i=0;i<n;i++){
		if(!vis[i])
			bfs(i,vis,incoming);
	}
	for(i=0;i<n;i++) printf("%d ",topo[i]);
	return 0;
}