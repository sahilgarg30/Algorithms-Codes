#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *right;
	struct node *left;
}node;

node *createTree(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);

	node *newn = malloc(sizeof(node));
	newn->val = a;
	if(b!=-1) newn->left = createTree();
	else newn->left = NULL;
	if(c!=-1) newn->right = createTree();
	else newn->right = NULL;
}

int findNodes(node *root){
	if(root == NULL) return 0;
	return findNodes(root->left) + 1 + findNodes(root->right);
}

int main(){
	node *root;
	root = createTree();
	int ans = findNodes(root);
	printf("The number of nodes are - %d\n",ans);
	return 0;
}