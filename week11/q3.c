#include <stdio.h>
#include <stdlib.h>
int n;

typedef struct node{
	char ch; int val;
	struct node *left, *right;
}node;
node *nodes[100];

void sortNodes(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(nodes[j]->val > nodes[j+1]->val){
				node *temp = nodes[j];
				nodes[j] = nodes[j+1];
				nodes[j+1] = temp;
			}
		}
	}
}

void inorder(node *root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d  ",root->val);
	inorder(root->right);
}

int main(){
	printf("Enter number of chars - \n");
	scanf("%d",&n);
	char extra;
	printf("Enter characters and values - \n");
	for(int i=0;i<n;i++){
		char a; int b;
		scanf("%c",&a);
		scanf("%c",&extra);
		scanf("%d",&b);
		nodes[i] = malloc(sizeof(node));
		nodes[i]->ch = a; nodes[i]->val = b;
		nodes[i]->left = nodes[i]->right = NULL;
	}
	int size = n;
	for(int i=0;i<size-1;i++){
		sortNodes();
		node* a = nodes[0];
		node* b = nodes[1];
		node* newNode = (node*)malloc(sizeof(node));
		newNode->left = a;
		newNode->right = b;
		newNode->val = a->val+b->val;
		nodes[0] = newNode;
		nodes[1]=nodes[n-1];
		n--;
	}
	inorder(nodes[0]);
}