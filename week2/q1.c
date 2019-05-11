#include <stdio.h>
#include <stdlib.h>

int main(){
	int a,b;
	scanf("%d %d",&a,&b);

	int t = a<b?a:b;

	while(a%t != 0 || b%t!=0)
		t--;

	printf("%d\n",t);
	return 0; 
}