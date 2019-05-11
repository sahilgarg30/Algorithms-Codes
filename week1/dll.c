#include<stdio.h>
#include <stdlib.h>
typedef struct node{
	int val;
	struct node *left;
	struct node *right;
} node;

void display(node* head){

	if(head == NULL){
		printf("Empty list.\n");
		return;
	}
	while(head!=NULL){
		printf("%d ",head->val);
		head = head->right;
	}

	printf("\n");
}

void search(node* head,int val){

	if(head == NULL){
		printf("Empty list.\n");
		return;
	}
	while(head!=NULL){
		if(head->val == val){
			printf("Element found.\n");
			return;
		}
		head = head->right;
	}

	printf("Element not found.\n");
}

node* insert_front(node* head,int val){
	node* newn = malloc(sizeof(node));
	newn->val = val;
	newn->left=NULL;
	newn->right = NULL;

	if(head==NULL) return newn;

	newn->right = head;
	head->left = newn;
	return newn;
}

node* insert_left(node* first,int val,int ele){
	node* head = first;
	if(head == NULL){
		printf("Empty list.\n");
		return head;
	}

	if(head->val == ele){
		node* newn = malloc(sizeof(node));
		newn->val=val;
		newn->right = head;
		newn->left = head->left;
		head->left = newn;
		return newn;
	}else{
		head = head->right;
	}
	while(head!=NULL){
		if(head->val == ele){
			node* newn = malloc(sizeof(node));
			newn->val=val;
			newn->right = head;
			newn->left = head->left;
			head->left->right = newn;
			head->left = newn;
			return first;
		}
		head = head->right;
	}

	printf("Element not found.\n");
	return first;
}

node* delete(node* head,int val){
	while(head->val == val){
		node* temp = head;
		head = head->right;
		head->left = NULL;
		free(temp);
	}

	node* first = head;
	while(first!=NULL){
		if(first->val == val){
			first->left->right = first->right;
			if(first->right !=NULL) first->right->left = first->left;
			node* temp = first;
			first = first->right;
			free(temp);
		}else{
			first = first->right;
		}
	}

	return head;
}

int main(){
	node *head = NULL;
	int choice = 0;
	while(choice!=6){
		printf("1.Insert front 2.Insert left 3.Delete val 4.Search 5.Show list 6.Exit\n");
		scanf("%d",&choice);
		int val;
		switch(choice){
			case 1: scanf("%d",&val);
					head = insert_front(head,val);
					break;

			case 2: scanf("%d",&val);
					printf("Enter element whose left -\n");
					int ele;
					scanf("%d",&ele);
					head = insert_left(head,val,ele);
					break;

			case 3: scanf("%d",&val);
					head = delete(head,val);
					break;
			case 4: scanf("%d",&val);
					search(head,val);
					break;
			case 5: display(head);
					break;
		}
	}	
	return 0;
}