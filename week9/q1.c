#include <stdio.h>
#include <string.h>
int table[200];

void shiftTable(char pattern[]){
	int m = strlen(pattern);
	for(int i=0;i<200;i++) table[i] = m;
	for(int i=0;i<m-1;i++) table[pattern[i]] = m-1-i;
}

int main(){
	char text[200];
	char pattern[50];
	printf("Enter text and pattern - \n");
	gets(text);
	gets(pattern);
	shiftTable(pattern);
	int m = strlen(pattern);
	int n = strlen(text);
	int i=m-1;
	while(i<n){
		int k=0;
		while(k<m && pattern[m-1-k]==text[i-k]) k++;
		if(k==m) {printf("%d ",i-m+1);i=i+table[text[i]];}
		else i = i+table[text[i]];
	}
	return 0;
}