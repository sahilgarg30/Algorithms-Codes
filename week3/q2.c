#include <stdio.h>
#include <stdlib.h>

int main(){
	char text[100],pat[20];
	int i,j;
	printf("Enter text and pattern -\n");
	gets(text);
	gets(pat);

	int len1=0,len2=0;
	while(text[len1]!='\0') len1++;
	while(pat[len2]!='\0') len2++;

	printf("Index where pattern occurs - \n");
	for(i=0;i<len1;i++){
		j=0;
		while(j<len2 && text[i+j]==pat[j]) j++;
		if(j==len2)
			printf("%d \n",i+1);
	}
	return 0;
}