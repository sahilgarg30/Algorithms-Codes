#include<stdio.h>
#include<stdlib.h>

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

void preorder(node* root){
	if(root == NULL) return;

	printf("%d ",root->val);
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root){
	if(root == NULL) return;

	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);
}

void postorder(node* root){
	if(root == NULL) return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->val);
}

void display(node* root){
	printf("Preorder - \n");
	preorder(root);
	printf("\nInorder - \n");
	inorder(root);
	printf("\nPostorder - \n");
	postorder(root);
	printf("\n");
}

int main(){
	node* root = NULL;
	int choice = 0;
	while(choice!=3){
		printf("1.Find/Insert element 2.Display tree 3.Exit\n");
		scanf("%d",&choice);
		int val;
		switch(choice){
			case 1: scanf("%d",&val);
					root = insert(root,val);
					break;

			case 2: display(root);
					break; 
		}
	}
	return 0;
}