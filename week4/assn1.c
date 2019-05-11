#include<stdio.h>
#include<stdlib.h>

int leaf[100],nleaf[100],cl=0,ncl=0;
int il=0,inl=0;

typedef struct node{
	int val;
	struct node* left;
	struct node* right;
}node;

node* insert(node* root,int val){
	if(root == NULL){
		node* newn = malloc(sizeof(node));
		newn->val = val;
		newn->left = NULL;
		newn->right = NULL;
		return newn;
	}

	if(root->val == val){
		printf("Element already exists.\n");
		return root;
	}

	if(val < root->val)
		root->left = insert(root->left,val);
	else
		root->right = insert(root->right,val);

	return root;
}

void display(node* root){
	if(root == NULL) return;

	display(root->left);
	if(root->left == NULL && root->right==NULL){
		leaf[il++]=root->val;
		cl++;
	}else{
		nleaf[inl++]=root->val;
		ncl++;
	}
	display(root->right);
}

int main(){
	node* root = NULL;
	int i,n = 0;
	printf("Enter number of nodes-\n");
	scanf("%d",&n);
	printf("Enter nodes-\n");
	for(i=0;i<n;i++){
		int a; scanf("%d",&a);
		root = insert(root,a);
	}

	display(root);

	printf("Count of leaf and non leaf nodes - %d and %d.\n",cl,ncl);

	printf("Leaf nodes - \n");
	for(i=0;i<il;i++)
		printf("%d ",leaf[i]);

	printf("\nNon-Leaf nodes - \n");
	for(i=0;i<inl;i++)
		printf("%d ",nleaf[i]);

	printf("\n");
	return 0;
}