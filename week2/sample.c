#include <stdio.h>

unsigned int EuclidGCD(unsigned int m,unsigned int n){
	unsigned int r;
	int opcount = 0;
	while(n!=0){
		opcount++;
		r = m%n;
		m =n;
		n = r;
	}

	printf("Operation count - %d\n",opcount);
	return m;
}

int main(){
	unsigned int m,n;
	scanf("%d %d",&m,&n);
	printf("\nGCD - %d\n",EuclidGCD(m,n));
	return 0;
}