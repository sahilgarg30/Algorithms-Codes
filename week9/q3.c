#include <stdio.h>
#include <string.h>
int main(){
	int size;
	printf("Enter hash table size - \n");
	scanf("%d",&size);
	char c;
	scanf("%c",&c);
	char table[50][200];
	for(int i=0;i<size;i++) strcpy(table[i],"EMPTY");
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
		int temp = val;
		while(1){
		if(strcmp(table[temp],"EMPTY")==0){
			strcpy(table[temp],t);
			break;
		}else{
			temp = (temp+1)%size;
			if(temp==val) break;
		}}
	}

	for(int i=0;i<size;i++){
		printf("%d - %s\n",i,table[i]);
	}

	printf("\nEnter string to find - \n");
	char pattern[200];
	gets(pattern);
	int val = 0;
	for(int i=0;pattern[i]!='\0';i++){
		val += pattern[i]-'a'+1;
	}
	val = val%size;
	int temp = val;
		while(1){
		if(strcmp(table[temp],pattern)==0){
			printf("String found at location - %d.\n",temp);
			temp++;
			break;
		}else{
			temp = (temp+1)%size;
			if(temp==val) break;
		}}
	if(temp == val) printf("String not found.\n");
	return 0;
}