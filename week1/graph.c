#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	struct node* next;
}node;

node* insert(node* root,int val){
	if(root == NULL){
		node* newn = malloc(sizeof(node));
		newn->next = NULL;
		newn->val = val;
		return newn;
	}

	node* first = root;
	while(first->next!=NULL) first = first->next;
	node* newn = malloc(sizeof(node));
	newn->next = NULL;
	newn->val = val;
	first->next = newn;
	return root;
}

int main(){
	int n,m,i,j;
	printf("Enter number of nodes and edges - \n");
	scanf("%d %d",&n,&m);

	int adj[101][101];
	for(i=0;i<101;i++){
		for(j=0;j<101;j++){
			adj[i][j] = 0;
		}
	}

	node* adjlist[101];
	for(i=0;i<n;i++){
		adjlist[i] = malloc(sizeof(node));
		adjlist[i] = NULL;
	}
	printf("Enter the edges - \n");
	for(i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a][b] = 1;
		adj[b][a] = 1;

		adjlist[a] = insert(adjlist[a],b);
		adjlist[b] = insert(adjlist[b],a);
	}

	printf("Adjacency Matrix - \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}

	printf("Adjacency List - \n");
	for(i=0;i<n;i++){
		node* head = adjlist[i];
		printf("%d -> ",i);
		while(head!=NULL){
			printf("%d ",head->val);
			head = head->next;
		}
		printf("\n");
	}
	return 0;
}