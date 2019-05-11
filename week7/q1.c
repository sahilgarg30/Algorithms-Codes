#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
	int val;
	struct node *left;
	struct node *right;	
}node;

int max(int a,int b){return a>b?a:b;}
int findBalanceFactors(node* root){
	if(root==NULL) return 0;
	int h1 = findBalanceFactors(root->left);
	int h2 = findBalanceFactors(root->right);
    printf("Node %d - %d \n",root->val,h1-h2);
	return max(h1,h2)+1;
}

node* createTree(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	node *newn = malloc(sizeof(node));
	newn->val = a;
	if(b!=-1)
		newn->left =  createTree();
	else newn->left = NULL;

	if(c!=-1) newn->right = createTree();
	else newn->right = NULL;
	return newn;
}

int main(){
	node *root;
	printf("Enter the tree - \n");
	root = createTree();
	printf("Balance factors are - \n");
	findBalanceFactors(root);
	return 0;
}
