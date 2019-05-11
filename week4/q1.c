#include <stdio.h>
#include <stdlib.h>
int res[100],ri=0,cost=99999;
int cur[100];
int swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void permute(int adj[][100],int n,int curele,int curcost){
	int i;
	if(curele==n && curcost<cost){
		cost = curcost;
		for(i=0;i<n;i++) res[i]=cur[i];
		return;
	}
	if(curele==n) return;

	for(i=curele;i<n;i++){
		swap(&cur[i],&cur[curele]);
		permute(adj,n,curele+1,curcost+adj[curele][cur[curele]]);
		swap(&cur[i],&cur[curele]);
	}
}

int main(){
	int i,j,n;
	printf("Enter number of persons/jobs - \n"); scanf("%d",&n);

	printf("Enter the costs for all jobs person wise - \n");
	int adj[100][100];
	for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&adj[i][j]);
	for(i=0;i<n;i++) cur[i]=i;
	permute(adj,n,0,0);

	printf("\nMinimum cost is - %d\n",cost);
	printf("The people assigned are - \n");
	for(i=0;i<n;i++){
		printf("Job %d - Person %d\n",i+1,res[i]+1);
	}
	return 0;
}