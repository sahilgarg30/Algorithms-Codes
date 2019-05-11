#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	struct node* next;
	char s[200];
}node;

node* insert(node *head,char entry[200]){
	node* newn = (node*)malloc(sizeof(node));
	strcpy(newn->s,entry);
	newn->next = NULL;
	node* temp = head;
	while(temp->next != NULL) temp = temp->next;
	temp->next = newn;
	return head;
}

int main(){
	int size;
	printf("Enter hash table size - \n");
	scanf("%d",&size);
	char c;
	scanf("%c",&c);
	node** list = (node **)malloc(sizeof(node *)*size);
	for(int i=0;i<size;i++){
		list[i] = (node*)malloc(sizeof(node));
	}
	char text[200];
	gets(text);
	int n = strlen(text);
	text[n] = ' ';
	text[n+1] = '\0';
	for(int i=0;i<n;){
		char t[200];
		int k=0;
		while(text[i]!=' '){
			t[k++] = text[i++];
		}
		t[k] = '\0';
		i++;
		int val = 0;
		for(int j=0;j<k;j++){
			val += t[j]-'a'+1;
		}
		val = val%size;
		list[val] = insert(list[val],t);
	}

	for(int i=0;i<size;i++){
		printf("%d ",i);
		node* temp = list[i];
		while(temp!=NULL){
			printf("%s -> ",temp->s);
			temp = temp->next;
		}
		printf("END\n");
	}

	printf("\nEnter string to find - \n");
	char pattern[200];
	gets(pattern);
	int val = 0;
	for(int i=0;pattern[i]!='\0';i++){
		val += pattern[i]-'a'+1;
	}
	val = val%size;
	node* temp = list[val]->next;
	while(temp!=NULL){
		if(strcmp(pattern,temp->s)==0){
			printf("String found.\n");
			break;
		}
		temp = temp->next;
	}
	if(temp==NULL) printf("String not found.\n");
	return 0;
}