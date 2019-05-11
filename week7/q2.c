#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int key;
	struct node *left,*right;
}node;

int max(int a,int b){return a>b?a:b;}
int height(node *n) 
{ 
    if (n == NULL) 
        return 0; 
    return max(height(n->left),height(n->right))+1; 
} 
void inorder(node *ptr){
	if(ptr!=NULL){
		inorder(ptr->left);
		printf("%d  ",ptr->key);
		inorder(ptr->right);
	}
}

node* newNode(int key) 
{ 
    node* newnode = (node*)malloc(sizeof(node)); 
    newnode->key   = key; 
    newnode->left   = NULL; 
    newnode->right  = NULL; 
    return(newnode); 
} 
node *rightRotate(node *y) 
{ 
    node *x = y->left; 
    node *T2 = x->right; 
    x->right = y; 
    y->left = T2; 
  	return x; 
} 
node *leftRotate(node *x) 
{ 
    node *y = x->right; 
    node *T2 = y->left; 
  	y->left = x; 
    x->right = T2; 
  	return y; 
} 
int getBalance(node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
  
node* insert(node* node, int key) 
{ 
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else 
        return node; 
  
    int balance = getBalance(node); 
  
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    return node; 
} 
int main(){
	int ch = 1,n;
	node *root = NULL;
	while(ch!=3){
		printf("\n1.Insert into BST 2.Display inorder 3.Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the value - \n");
					scanf("%d",&n);
					root = insert(root,n);
					break;

			case 2: inorder(root);
					break;

			case 3: exit(0);
		}
	}
	return 0;
}