#include<stdio.h>
#include<stdlib.h>

void tower(int n,char src,char mid,char dest){
	if(n==0)
		return;
	tower(n-1,src,dest,mid);
	printf("Move disc number %d from %c to %c.\n",n,src,dest);
	tower(n-1,mid,dest,src);
}
int main(){
	int n;
	scanf("%d",&n);
	tower(n,'A','B','C');
	return 0;
}