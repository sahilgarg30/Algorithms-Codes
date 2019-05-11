#include <stdio.h>
int arr[10000];

typedef struct{
	int a,b,c;
}edge;
edge edges[100];

int findSet(int i){
	while(i!=arr[i]){
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i;
}

int unionSet(int a,int b){
	int root1 = findSet(a);
	int root2 = findSet(b);
	if(root1 == root2) return 0;
	arr[root2] = root1;
	return 1;
}

void sortEdges(int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(edges[j].c > edges[j+1].c){
				edge temp = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = temp;
			}
		}
	}
}

int main(){
	int n,e;
	printf("Enter number of nodes and edges-\n");
	scanf("%d %d",&n,&e);
	for(int i=0;i<=n;i++) arr[i] = i;

	printf("Enter the edges - \n");
	for(int i=0;i<e;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		edges[i].a = a;
		edges[i].b = b;
		edges[i].c = c;
	}

	printf("MST is - \n");
	int cost = 0;
	sortEdges(e);
	for(int i=0;i<e;i++){
		if(unionSet(edges[i].a,edges[i].b)){
			cost += edges[i].c;
			printf("%d ----- %d \n",edges[i].a,edges[i].b);
		}
	}

	printf("Minimum cost is - %d\n",cost);
}