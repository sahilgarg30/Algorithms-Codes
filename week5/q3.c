#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
	int val;
	struct node *left;
	struct node *right;	
}node;

int max(int a,int b){return a>b?a:b;}
int diam(node* root,int *height){
	if(root==NULL) return 0;
	int lh=0,rh=0;
	int h1 = diam(root->left,&lh);
	int h2 = diam(root->right,&rh);

	*height = max(lh,rh)+1;
	return max(lh+rh+1,max(h1,h2));

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
	int height = 0;
	int dia = diam(root,&height);
	printf("Diameter of tree is %d.\n",dia);	
	return 0;
}